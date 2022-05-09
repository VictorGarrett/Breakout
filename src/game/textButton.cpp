#include "game/textButton.h"

TextButton::TextButton():
content(),
clickBox()
{

}

TextButton::~TextButton(){

}

void TextButton::update(){
    if(clickBox.isHovering())
        content.setColor({1.0f, 0.0f, 0.0f, 1.0f});
    else
        content.setColor({1.0f, 1.0f, 1.0f, 1.0f});
}

void TextButton::setPosition(const vec2f& pos){
    content.setPosition(pos);
    clickBox.setPosition(pos);
}

void TextButton::setColor(const vec4f& color){
    content.setColor(color);
}

void TextButton::setText(std::string text){
    content.setText(text);
    clickBox.setSize(content.getSize());
}

void TextButton::setFont(FontLocation font, int size){
    content.setFont(FontManager::getFont(font, size));
    clickBox.setSize(content.getSize());
}