#include "game/ball.h"
#include "game/paddle.h"

#define RAND_0TO1_F ((rand()%4096)/4096.0f)

Ball::Ball():
image(TextureLocation::MAIN_ATLAS),
collidable(this, CollidableType::Ball, {0.0f, 0.0f, BALL_WIDTH, BALL_HEIGHT})
{
    alive = true;

    image.setSize({BALL_WIDTH, BALL_HEIGHT});
    image.setColor({1.0f, 1.0f, 1.0f, 1.0f});
    image.setLayer(80);
    setPosition({FIELD_WIDTH/2, FIELD_HEIGHT/2});
    vel = {220.0f, 280.0f};

    image.setTexturePosition({34.0f, 96.0f});
    image.setTextureSize({6.0f, 7.0f});

}

Ball::~Ball(){
    
}

void Ball::setPosition(const vec2f& pos){
    this->pos = pos;
    image.setPosition({pos.x - 1.0f, pos.y - 1.0f});
    collidable.setPosition(pos);
}

void Ball::update(){
    setPosition(pos + vel*DELTA_TIME);
    if(pos.x <= 0.0f && vel.x < 0.0f){
        setPosition({0.0f, pos.y});
        vel.x = -vel.x;
    }
    else if(pos.x + BALL_WIDTH >= FIELD_WIDTH && vel.x > 0.0f){
        setPosition({FIELD_WIDTH - BALL_WIDTH, pos.y});
        vel.x = -vel.x;
    }

    if(pos.y <= 0.0f && vel.y < 0.0f){
        setPosition({pos.x, 0.0f});
        vel.y = -vel.y;
    }
    else if(pos.y >= FIELD_HEIGHT && vel.y > 0.0f){
        alive = false;
        vel = {0.0f, 0.0f};
    }

}

void Ball::BallCollidable::onCollide(Collidable* other){

    if(other->getType() == CollidableType::Brick){
        //printf("col to brick %f %f\n", GET_COLLIDABLE_PARENT(this, Ball)->pos.x, GET_COLLIDABLE_PARENT(this, Ball)->pos.y);
        vec2f correction = CollisionManager::getCorrectionVel(this->getHitbox(), other->getHitbox(), GET_COLLIDABLE_PARENT(this, Ball)->vel*DELTA_TIME);
        
        if(!CHECK_SIGN(GET_COLLIDABLE_PARENT(this, Ball)->vel.y, correction.y))
            GET_COLLIDABLE_PARENT(this, Ball)->vel.y = -GET_COLLIDABLE_PARENT(this, Ball)->vel.y;
        else if(!CHECK_SIGN(GET_COLLIDABLE_PARENT(this, Ball)->vel.x, correction.x))
            GET_COLLIDABLE_PARENT(this, Ball)->vel.x = -GET_COLLIDABLE_PARENT(this, Ball)->vel.x;
        
        
        GET_COLLIDABLE_PARENT(this, Ball)->setPosition(GET_COLLIDABLE_PARENT(this, Ball)->pos + correction);
        //printf(" to %f %f\n", GET_COLLIDABLE_PARENT(this, Ball)->pos.x, GET_COLLIDABLE_PARENT(this, Ball)->pos.y);
    }

    if(other->getType() == CollidableType::Paddle){

        vec2f correction = CollisionManager::getCorrectionVel(this->getHitbox(), other->getHitbox(), (GET_COLLIDABLE_PARENT(this, Ball)->vel + GET_COLLIDABLE_PARENT(other, Paddle)->getVelocity())*DELTA_TIME);

        if(!CHECK_SIGN(correction.y, GET_COLLIDABLE_PARENT(this, Ball)->vel.y)){
            //if(correction.x == 0.0f){
                GET_COLLIDABLE_PARENT(this, Ball)->vel.x = (((GET_COLLIDABLE_PARENT(this, Ball)->pos.x + BALL_WIDTH/2.0f)-(GET_COLLIDABLE_PARENT(other, Paddle)->getPosition().x+PADDLE_WIDTH/2.0f))/(PADDLE_WIDTH/2.0f)*180.0f);
            //}
            //else{

            //}
            GET_COLLIDABLE_PARENT(this, Ball)->vel.y = -GET_COLLIDABLE_PARENT(this, Ball)->vel.y;
            GET_COLLIDABLE_PARENT(this, Ball)->setPosition(GET_COLLIDABLE_PARENT(this, Ball)->pos + correction);
        }
    }
}