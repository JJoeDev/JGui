#include <SFML/Graphics.hpp>
#include <SFML/Window/Event.hpp>
#include <iostream>

#include "JGui.h"

using jGui::Button, jGui::Label;

void button2Callback(){
    std::cout << "Button 2 Pressed!\n";
}

int main(){
    sf::RenderWindow window(sf::VideoMode(800, 800), "Window"); // Size gets ignored by my window manager

    Button btn(sf::Vector2f(100, 100), sf::Vector2f(200, 50), sf::Color::Red);
    Button btn2(sf::Vector2f(100, 200), sf::Vector2f(50, 50), sf::Color::Red);
    Label label(sf::Vector2f(100, 50), 24, sf::Color::Green, "Font/Comfortaa.ttf");

    label.SetText("Hello World!");
    label.SetStyle(sf::Text::Bold | sf::Text::Italic);

    // Set a function callback for the button
    btn.SetOnClick([&](){
       label.SetText("Button 1 Pressed!");
    });

    btn2.SetOnClick(button2Callback);

    // Game Loop
    while(window.isOpen()){
        sf::Event e;
        while(window.pollEvent(e)){
            if(e.type == sf::Event::Closed)
                window.close();

            btn.EventHandler(e, window);
        }

        window.clear(sf::Color::Black);

        btn.Draw(window);
        label.Draw(window);

        window.display();
    }

    return 0;
}