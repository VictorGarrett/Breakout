#include "gameStateStack/gameStates/mainMenuState.h"
#include "gameStateStack/gameStateStack.h"
#include "game/gameContainer.h"

MainMenuState::MainMenuState(StateStack* stateStack): StateStack::State(stateStack){

}

MainMenuState::~MainMenuState(){

}

void MainMenuState::enter(){

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

void MainMenuState::exit(){
    delete GameContainer::playButton;
    GameContainer::playButton = nullptr;
    FontManager::unloadFont(FontLocation::MENU_FONT, 40);
}

void MainMenuState::update(){
    GameContainer::playButton->update();
    if(GameContainer::playButton->wasClicked(MouseButtons::MouseButton_1)){
        stateStack->push(static_cast<StateStack::State*>(new PlayingState(stateStack)));
    }
}
