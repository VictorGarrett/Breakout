#include "game/brick.h"
#include "game/brickGroup.h"

Brick::Brick(BrickGroup* group, BrickColor color):
image(TextureLocation::MAIN_ATLAS),
collidable(this, CollidableType::Brick, {0.0f, 0.0f, 22.0f, 11.0f})
{  
    this->group = group;
    setColor(color);
    image.setLayer(50);

}

Brick::~Brick(){

}

void Brick::setPosition(vec2f position){
    this->position = position;
    image.setPosition(position);
    collidable.setPosition(position);
}

void Brick::setColor(BrickColor color){

    this->color = color;

    switch(color){
        case BrickColor::Red:
            image.setTexturePosition(RED_BRICK_POSITION);
            image.setTextureSize(RED_BRICK_SIZE);
            image.setSize(RED_BRICK_SIZE);
            collidable.setSize(RED_BRICK_SIZE);
            break;
        case BrickColor::Green:
            image.setTexturePosition(GREEN_BRICK_POSITION);
            image.setTextureSize(GREEN_BRICK_SIZE);
            image.setSize(GREEN_BRICK_SIZE);
            collidable.setSize(GREEN_BRICK_SIZE);
            break;
        case BrickColor::Blue:
            image.setTexturePosition(BLUE_BRICK_POSITION);
            image.setTextureSize(BLUE_BRICK_SIZE);
            image.setSize(BLUE_BRICK_SIZE);
            collidable.setSize(BLUE_BRICK_SIZE);
            break;
    }
}

void Brick::BrickCollidable::onCollide(Collidable* other){
    if(other->getType() == CollidableType::Ball){
        GET_COLLIDABLE_PARENT(this, Brick)->group->breakBrick(GET_COLLIDABLE_PARENT(this, Brick));
        GET_COLLIDABLE_PARENT(this, Brick)->collidable.deactivate();
        GET_COLLIDABLE_PARENT(this, Brick)->image.setVisible(false);
    }
}
