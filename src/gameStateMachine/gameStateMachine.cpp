#include "gameStateMachine/gameStateMachine.h"

GameStateMachine::GameStateMachine(){
    addState(new MainMenuState(this));
    addState(new PlayingState(this));

    changeState(MainMenuStateID);
}

GameStateMachine::~GameStateMachine(){

}

