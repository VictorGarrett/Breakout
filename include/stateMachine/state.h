#pragma once

#include <vector>


class StateMachine;

class State{

protected:
    StateMachine* stateMachine;

public:
    State(StateMachine* stateMachine = NULL);
    virtual ~State();

    virtual void enter(int from){}
    virtual void exit(int to){}

    virtual void update() = 0;

    inline void setStateMachine(StateMachine* stateMachine){
        this->stateMachine = stateMachine;
    }

};



