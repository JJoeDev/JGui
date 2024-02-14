#ifndef BUTTON_H
#define BUTTON_H

#include "Component.h"

#include <SFML/System/Vector2.hpp>
#include <cmath>
#include <functional>
#include <system_error>

namespace jGui{
    class Button : public Component {
    public:
        Button(const sf::Vector2f& position, const sf::Vector2f& scale, const sf::Color& fill) : _position(position), _scale(scale), _fill(fill) {}

        void SetOnClick(std::function<void()> onClick){
            _onClick = onClick;
        }

        void SetPosition(const sf::Vector2f& pos){
            _position = pos;
        }

        void SetScale(const sf::Vector2f& scale){
            _scale = scale;
        }

        void Draw(sf::RenderWindow& window) const override {
            sf::RectangleShape buttonShape(_scale);
            buttonShape.setPosition(_position);
            buttonShape.setFillColor(_fill);
            window.draw(buttonShape);
        }

        void EventHandler(const sf::Event& e, sf::RenderWindow& window) override {
            if(e.type == sf::Event::MouseButtonPressed){
                sf::Vector2i mPos = sf::Mouse::getPosition(window);
                if(_onClick && contains(mPos)){
                    _onClick();
                }
            }
        }

    private:
        sf::Vector2f _position;
        sf::Vector2f _scale;
        sf::Color _fill;

        std::function<void()> _onClick;

        bool contains(const sf::Vector2i point) const {
            return point.x >= _position.x && point.x <= _position.x + _scale.x && point.y >= _position.y && point.y <= _position.y + _scale.y;
        }
    };
}

#endif