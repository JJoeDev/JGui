#ifndef COMPONENT_H
#define COMPONENT_H

#include "SFML/Graphics.hpp"

namespace jGui{
    class Component{
    public:
        Component() = default;
        virtual ~Component() = default;

        virtual void Draw(sf::RenderWindow& window) const = 0; 
        virtual void Update() {}
        virtual void EventHandler(const sf::Event& event, sf::RenderWindow& window) {}
    };
}

#endif