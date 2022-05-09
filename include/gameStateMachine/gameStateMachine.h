#pragma once

#include "stateMachine/stateMachine.h"
#include "gameStateMachine/gameStates/mainMenuState.h"
#include "gameStateMachine/gameStates/playingState.h"
#include "game/gameContainer.h"

enum GameStateID{
    MainMenuStateID,
    PlayingStateID
};

class GameStateMachine: public StateMachine{
    public:

        GameStateMachine();
        virtual ~GameStateMachine();

};