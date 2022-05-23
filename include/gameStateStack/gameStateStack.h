#pragma once

#include "stateMachine/stateStack.h"
#include "gameStateStack/gameStates/mainMenuState.h"
#include "gameStateStack/gameStates/playingState.h"
#include "game/gameContainer.h"

enum GameStateID{
    MainMenuStateID,
    PlayingStateID
};

class GameStateStack: public StateStack{
    public:

        GameStateStack();
        virtual ~GameStateStack();

};