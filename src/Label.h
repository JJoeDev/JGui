#ifndef LABEL_H
#define LABEL_H

#include "Component.h"

namespace jGui{
    class Label : public Component{
    public:
        Label(const sf::Vector2f& position, const int& size, const sf::Color& fill, const char* font) : _position(position), _size(size), _fill(fill) {
            _font.loadFromFile(font);
            _text.setPosition(position);
            _text.setCharacterSize(size);
            _text.setFillColor(fill);

            _text.setFont(_font);

            width = _text.getLocalBounds().width;
            height = _text.getLocalBounds().height;
        }

        void SetFont(const char* font){
            _font.loadFromFile(font);
        }

        void SetText(const char* text){
            _text.setString(text);
            width = _text.getLocalBounds().width;
            height = _text.getLocalBounds().height;
        }

        void SetStyle(unsigned int style){
            _text.setStyle(style);
        }

        void SetPosition(const sf::Vector2f& pos){
            _position = pos;
            _text.setPosition(_position);
        }

        sf::Vector2f GetBounds() {
            return sf::Vector2f{width, height};
        }

        void Draw(sf::RenderWindow& window) const override {
            window.draw(_text);
        }

    private:
        sf::Vector2f _position;
        sf::Color _fill;
        sf::Font _font;
        sf::Text _text;
        int _size;

        float width;
        float height;
    };
}

#endif