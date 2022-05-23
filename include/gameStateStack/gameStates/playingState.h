#pragma once

#include "stateMachine/stateStack.h"
#include "game/gameContainer.h"

class PlayingState: public StateStack::State{
    
    public:
        PlayingState(StateStack* stateStack = nullptr);
        virtual ~PlayingState();

        virtual void enter();
        virtual void exit();

        virtual void update();
};