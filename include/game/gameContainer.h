#pragma once
#include "graphics/text/fontManager.h"
#include "game/ball.h"
#include "game/paddle.h"
#include "game/brickGroup.h"
#include "game/textButton.h"

// settings
const unsigned int SCR_WIDTH = 500;
const unsigned int SCR_HEIGHT = 600;

class GameContainer{
    private:
        GameContainer(){}
        ~GameContainer(){}

    public:
        static Ball* ball;
        static Paddle* paddle;
        static BrickGroup* bricks;

        static View gameView;

        static TextButton* playButton;

};