#pragma once

#include "game/brick.h"
#include "sound/soundManager.h"
#include "game/gameParameters.h"
#include <vector>

#define BRICK_SPACING_X 23.0f
#define BRICK_SPACING_Y 12.0f

class BrickGroup{

    private:
        std::vector<Brick*> bricks;
        int brickCount;
        ParticleSystem redBrickBreakParticles;
        ParticleSystem greenBrickBreakParticles;
        ParticleSystem blueBrickBreakParticles;

        SoundSource brickBreakSource;

    public:

        BrickGroup();
        ~BrickGroup();

        int getBrickCount();

        void breakBrick(Brick* brick);

        void update();

        void fill(vec2f origin, int width, int height);
        void clear();
};