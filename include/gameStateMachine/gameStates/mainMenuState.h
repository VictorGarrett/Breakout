#pragma once

#include "stateMachine/state.h"

class MainMenuState: public State{
    
    public:
        MainMenuState(StateMachine* stateMachine = nullptr);
        virtual ~MainMenuState();

        virtual void enter(int from);
        virtual void exit(int to);

        virtual void update();
};