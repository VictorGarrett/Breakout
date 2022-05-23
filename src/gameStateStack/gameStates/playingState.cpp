#include "gameStateStack/gameStates/PlayingState.h"
#include "gameStateStack/gameStateStack.h"
#include "sound/soundManager.h"

PlayingState::PlayingState(StateStack* stateStack): StateStack::State(stateStack){

}

PlayingState::~PlayingState(){

}

void PlayingState::enter(){

    if(GameContainer::playButton){
        GameContainer::playButton->setVisible(false);
        GameContainer::playButton->setEnabled(false);
    }

    SoundManager::loadSound(SoundLocation::BRICK_BREAK_SOUND);

    TextureManager::loadTexture(TextureLocation::MAIN_ATLAS);
    TextureManager::loadTexture(TextureLocation::SHARD);

    GameContainer::bricks = new BrickGroup;
    GameContainer::ball = new Ball;
    GameContainer::paddle = new Paddle;

    GameContainer::bricks->fill({19.0f, 5.0f}, 20, 10);
    SoundManager::setListenerPosition({FIELD_WIDTH/2, FIELD_HEIGHT/2}, 4*FIELD_WIDTH);
     
}

void PlayingState::exit(){
    delete GameContainer::bricks;
    GameContainer::bricks = nullptr;

    delete GameContainer::ball;
    GameContainer::ball = nullptr;

    delete GameContainer::paddle;
    GameContainer::paddle = nullptr;

    if(GameContainer::playButton){
        GameContainer::playButton->setVisible(true);
        GameContainer::playButton->setEnabled(true);
    }

    TextureManager::unloadTexture(TextureLocation::MAIN_ATLAS);
    TextureManager::unloadTexture(TextureLocation::SHARD);
    SoundManager::unloadSound(SoundLocation::BRICK_BREAK_SOUND);
}   

void PlayingState::update(){
    CollisionManager::pollAllCollisions();

    GameContainer::bricks->update();
    GameContainer::ball->update();
    GameContainer::paddle->update();

    if(!GameContainer::ball->isAlive()){
        stateStack->pop();
        return;
    }
    if(!GameContainer::bricks->getBrickCount()){
        stateStack->pop();
        return;
    }
}
