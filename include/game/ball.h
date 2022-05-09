#pragma once
#include "graphics/graphicManager.h"
#include "physics/collisionManager.h"
#include "game/gameParameters.h"

#define BALL_WIDTH 12
#define BALL_HEIGHT 15

#define BALL_VERT_SPEED 10

class Ball{
    
    private:
        vec2f pos, vel;

        Image image;

        bool alive;

        CREATE_COLLLIDABLE_TYPE(BallCollidable);
        BallCollidable collidable;

    public:

        Ball();
        ~Ball();

        void setPosition(const vec2f& pos);
        inline bool isAlive() const{
            return alive;
        }

        void update();
};