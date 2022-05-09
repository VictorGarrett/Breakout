#include "game/paddle.h"

Paddle::Paddle():
image(TextureLocation::MAIN_ATLAS, {5.0f, 107.0f}, {46.0f, 15.0f}),
collidable(this, CollidableType::Paddle, {0.0f, 0.0f, PADDLE_WIDTH, PADDLE_HEIGHT})
{
    image.setSize({46.0f, 15.0f});
    image.setColor({1.0f, 1.0f, 1.0f, 1.0f});
    image.setLayer(80);
    setPosition({FIELD_WIDTH/2, FIELD_HEIGHT - 40});
    vel = {0.0f, 0.0f};
}

Paddle::~Paddle(){

}

void Paddle::setPosition(const vec2f& pos){
    this->pos = pos;
    image.setPosition({pos.x-1, pos.y-2});
    collidable.setPosition(pos);
}

void Paddle::update(){
    if(InputManager::isKeyPressed(Keys::A)){
        pos += {-PADDLE_SPEED, 0.0f};
        vel.x = -PADDLE_SPEED;
    }
    if(InputManager::isKeyPressed(Keys::D)){
        pos += {PADDLE_SPEED, 0.0f};
        vel.x = PADDLE_SPEED;
    }

    setPosition(pos);
    if(pos.x <= 0.0f){
        setPosition({0.0f, pos.y});
    }
    else if(pos.x + PADDLE_WIDTH >= FIELD_WIDTH){
        setPosition({FIELD_WIDTH-PADDLE_WIDTH, pos.y});
    }
    
}