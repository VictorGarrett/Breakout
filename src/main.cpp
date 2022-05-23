#include <iostream>

#include "graphics/shaderProgram.h"
#include "graphics/textureManager.h"
#include "math/vec2f.h"
#include "graphics/sprite.h"
#include "graphics/image.h"
#include "input/inputManager.h"
#include "graphics/text/text.h"
#include "sound/soundManager.h"
#include "graphics/graphicManager.h"
#include "physics/collisionManager.h"
#include "gameStateStack/gameStateStack.h"

#include <string>


int main(){

    //initializing static managers
    GraphicManager::openWindow(SCR_WIDTH, SCR_HEIGHT, "abstracted window");
    TextureManager::init();
    GraphicManager::init();
    FontManager::init();
    SoundManager::init();


    GameStateStack* gameStateStack = new GameStateStack;

    gameStateStack->push(static_cast<StateStack::State*>(new MainMenuState(gameStateStack)));


    // render loop
    // -----------
    while (!GraphicManager::getWindowShouldClose()){
        
        gameStateStack->update();
        GraphicManager::render();
        // swap buffers and poll IO events
        // -------------------------------------------------------------------------------
        InputManager::pollEvents();

    }
    
    delete gameStateStack;
    
    //terminating managers
    SoundManager::terminate();
    GraphicManager::terminate();
    TextureManager::terminate();
    FontManager::terminate();

    return 0;
}
