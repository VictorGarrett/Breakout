#pragma once

#include <vector>

class State;

class StateMachine{

protected:
    std::vector<State*> states;
    int currentStateID;

public:
    StateMachine();
    virtual ~StateMachine();

    void addState(State* state);
    void changeState(int nextStateID);

    void update();

    int getCurrentState() const;

};