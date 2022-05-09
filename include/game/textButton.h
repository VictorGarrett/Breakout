#pragma once

#include <string>

#include "graphics/text/fontManager.h"
#include "input/clickable.h"


class TextButton{

    private:
        Text content;
        Clickable clickBox;

    public:
        TextButton();
        ~TextButton();

        void update();

        void setPosition(const vec2f& pos);
        void setColor(const vec4f& color);
        void setText(std::string text);
        void setFont(FontLocation font, int size);

        inline bool wasClicked(MouseButtons button){
            return clickBox.wasClicked(button);
        }
};
