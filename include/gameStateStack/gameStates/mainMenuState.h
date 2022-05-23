#pragma once

#include "stateMachine/stateStack.h"

class MainMenuState: public StateStack::State{
    
    public:
        MainMenuState(StateStack* stateStack = nullptr);
        virtual ~MainMenuState();

        virtual void enter();
        virtual void exit();

        virtual void update();
};