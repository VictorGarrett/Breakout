#pragma once
#include "graphics/graphicManager.h"
#include "physics/collisionManager.h"
#include "input/inputManager.h"
#include "game/gameParameters.h"

#define PADDLE_WIDTH    45.0f
#define PADDLE_HEIGHT   20.0f//11.0f

#define PADDLE_SPEED 10.0f

class Paddle{
    
    private:
        vec2f pos, vel;

        Image image;

        Collidable collidable;

    public:

        Paddle();
        ~Paddle();

        void setPosition(const vec2f& pos);
        inline const vec2f& getPosition() const{
            return pos;
        }

        void update();

        inline const vec2f& getVelocity() const{
            return vel;
        }
};