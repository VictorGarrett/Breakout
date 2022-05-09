#pragma once

#include "stateMachine/state.h"
#include "game/gameContainer.h"

class PlayingState: public State{
    
    public:
        PlayingState(StateMachine* stateMachine = nullptr);
        virtual ~PlayingState();

        virtual void enter(int from);
        virtual void exit(int to);

        virtual void update();
};