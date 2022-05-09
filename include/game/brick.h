#pragma once

#include "physics/collisionManager.h"
#include "graphics/graphicManager.h"

#define BRICK_COLOR_RED     {1.0f, 0.0f, 0.0f, 1.0f}
#define BRICK_COLOR_GREEN   {0.0f, 1.0f, 0.0f, 1.0f}
#define BRICK_COLOR_BLUE    {0.0f, 0.0f, 1.0f, 1.0f}

#define RED_BRICK_POSITION      {5.0f, 33.0f}
#define GREEN_BRICK_POSITION    {5.0f, 19.0f}
#define BLUE_BRICK_POSITION     {5.0f, 5.0f}

#define RED_BRICK_SIZE      {24.0f, 13.0f}
#define GREEN_BRICK_SIZE    {24.0f, 13.0f}
#define BLUE_BRICK_SIZE     {24.0f, 13.0f}


enum BrickColor{
    Red,
    Green,
    Blue
};

class BrickGroup;

class Brick{
    private:
        vec2f position;
        
        Image image;

        BrickColor color;

        BrickGroup* group;

        CREATE_COLLLIDABLE_TYPE(BrickCollidable);
        BrickCollidable collidable;


    public:
        Brick(BrickGroup* group = nullptr, BrickColor color = BrickColor::Red);
        ~Brick();

        void setPosition(vec2f position);

        inline const vec2f& getPosition(){
            return position;
        }

        void setColor(BrickColor color);

        inline BrickColor getColor(){
            return color;
        }

};