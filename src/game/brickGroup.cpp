#include "game/brickGroup.h"

BrickGroup::BrickGroup(){
    redBrickBreakParticles.setTexture(TextureLocation::SHARD);
    redBrickBreakParticles.setTexturePosition({0.0f, 0.0f});
    redBrickBreakParticles.setTextureSize({20.0f, 20.0f});
    redBrickBreakParticles.setColor({171/255.0f, 49/255.0f, 49/255.0f, 1.0f});

    redBrickBreakParticles.setPositionRange({-10.0f, -5.0f}, {10.0f, 5.0f});
    redBrickBreakParticles.setVelocityRange({-30.0f, 150.0f}, {30.0f, 20.0f});
    redBrickBreakParticles.setSizeRange({4.0f, 4.0f}, {8.0f, 8.0f}, true);
    redBrickBreakParticles.setLifetimeRange(0.5, 0.8);
    
    greenBrickBreakParticles.setScalingFactor(0.998f);
    greenBrickBreakParticles.setLayer(50);

    greenBrickBreakParticles.setTexture(TextureLocation::SHARD);
    greenBrickBreakParticles.setTexturePosition({0.0f, 0.0f});
    greenBrickBreakParticles.setTextureSize({20.0f, 20.0f});
    greenBrickBreakParticles.setColor({75/255.0f, 104/255.0f, 76/255.0f, 1.0f});

    greenBrickBreakParticles.setPositionRange({-10.0f, -5.0f}, {10.0f, 5.0f});
    greenBrickBreakParticles.setVelocityRange({-30.0f, 150.0f}, {30.0f, 20.0f});
    greenBrickBreakParticles.setSizeRange({4.0f, 4.0f}, {8.0f, 8.0f}, true);
    greenBrickBreakParticles.setLifetimeRange(0.5, 0.8);

    greenBrickBreakParticles.setScalingFactor(0.998f);
    greenBrickBreakParticles.setLayer(50);

    blueBrickBreakParticles.setTexture(TextureLocation::SHARD);
    blueBrickBreakParticles.setTexturePosition({0.0f, 0.0f});
    blueBrickBreakParticles.setTextureSize({20.0f, 20.0f});
    blueBrickBreakParticles.setColor({91/255.0f, 110/255.0f, 225/255.0f, 1.0f});

    blueBrickBreakParticles.setPositionRange({-10.0f, -5.0f}, {10.0f, 5.0f});
    blueBrickBreakParticles.setVelocityRange({-30.0f, 150.0f}, {30.0f, 20.0f});
    blueBrickBreakParticles.setSizeRange({4.0f, 4.0f}, {8.0f, 8.0f}, true);
    blueBrickBreakParticles.setLifetimeRange(0.5, 0.8);

    blueBrickBreakParticles.setScalingFactor(0.998f);
    blueBrickBreakParticles.setLayer(50);

    brickBreakSource.attachSound(BRICK_BREAK_SOUND);
    brickBreakSource.setReferenceDistance(3*FIELD_WIDTH);

}

BrickGroup::~BrickGroup(){
    brickBreakSource.clear();
    clear();
}

int BrickGroup::getBrickCount(){
    return brickCount;
}

void BrickGroup::breakBrick(Brick* brick){
    brickBreakSource.setPosition(brick->getPosition());
    brickBreakSource.play();
    brickCount--;
    switch(brick->getColor()){
        case BrickColor::Red:
            redBrickBreakParticles.setPosition(brick->getPosition() + vec2f RED_BRICK_SIZE/3);
            redBrickBreakParticles.emit(40);
            break;
        case BrickColor::Green:
            greenBrickBreakParticles.setPosition(brick->getPosition() + vec2f GREEN_BRICK_SIZE/3);
            greenBrickBreakParticles.emit(40);
            break;
        case BrickColor::Blue:
            blueBrickBreakParticles.setPosition(brick->getPosition() + vec2f BLUE_BRICK_SIZE/3);
            blueBrickBreakParticles.emit(40);
            break;
    }
}

void BrickGroup::update(){
    redBrickBreakParticles.update(1/60.0f);
    greenBrickBreakParticles.update(1/60.0f);
    blueBrickBreakParticles.update(1/60.0f);
}

void BrickGroup::fill(vec2f origin, int width, int height){
    clear();
    for(int y = 0; y < height; y++)
        for(int x = 0; x < width; x++){
            Brick* newBrick = new Brick(this, (BrickColor)((x+width*y)%3));
            newBrick->setPosition({origin.x + x*BRICK_SPACING_X, origin.y + y*BRICK_SPACING_Y});
            bricks.push_back(newBrick);
        }
        brickCount = width*height;
}

void BrickGroup::clear(){
    int count = 0;
    for(auto i = bricks.begin(); i != bricks.end(); i++){
        delete *i;
    }
    bricks.clear();
}