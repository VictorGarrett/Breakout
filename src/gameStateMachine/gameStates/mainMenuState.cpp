#include "gameStateMachine/gameStates/mainMenuState.h"
#include "gameStateMachine/gameStateMachine.h"
#include "game/gameContainer.h"

MainMenuState::MainMenuState(StateMachine* stateMachine): State(stateMachine){

}

MainMenuState::~MainMenuState(){

}

void MainMenuState::enter(int from){

    //setting a view to the whole screen
    View playView({0.0f, 0.0f}, {SCR_WIDTH, SCR_HEIGHT}, {-1.0f, 1.0f}, {2.0f, 2.0f});
    GameContainer::gameView = playView;
    GraphicManager::setView(GameContainer::gameView);
    InputManager::setClickablesView(playView);

    FontManager::loadFont(FontLocation::MENU_FONT, 40);

    GameContainer::playButton = new TextButton();
    GameContainer::playButton->setFont(FontLocation::MENU_FONT, 40);
    GameContainer::playButton->setText("PLAY");
    GameContainer::playButton->setPosition({100.0f, 100.0f});
}

void MainMenuState::exit(int to){
    delete GameContainer::playButton;
    GameContainer::playButton = nullptr;
    FontManager::unloadFont(FontLocation::MENU_FONT, 40);
}

void MainMenuState::update(){
    GameContainer::playButton->update();
    if(GameContainer::playButton->wasClicked(MouseButtons::MouseButton_1))
        stateMachine->changeState(PlayingStateID);
}
