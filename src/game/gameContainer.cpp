#include "game/gameContainer.h"

Ball* GameContainer::ball = nullptr;
Paddle* GameContainer::paddle = nullptr;
BrickGroup* GameContainer::bricks = nullptr;

View GameContainer::gameView;

TextButton* GameContainer::playButton;