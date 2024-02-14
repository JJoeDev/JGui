
# JGui

JGui is a simple gui library made on top of SFML for SFML.

[Features](#features)

[Code](#code)

## Features

| Feature | Code |
| - | - |
| Buttons | Button btn(Position, Scale, Color) |
| Label | Label label(Position, Char size, Color, Font location (const char*)) |

## Code
Available Functions
```cpp
SetOnClick(std::function<void()>);
Draw(sf::RenderWindow&) const override;
EventHandler(const sf::Event&, sf::RenderWindow&) override;
```
Example code for Buttons
```cpp
void Button2Callback(){
  // Code for when button 2 is pressed
}

int main(){
  // initialize sfml

  Button btn(sf::Vector2f(100, 100), sf::Vector2f(200, 50), sf::Color::Red);
  Button btn2(sf::Vector2f(100, 200), sf::Vector2f(100, 50), sf::Color::Red);

  btn.SetOnClick([](){
    // Code for when button is pressed
  });

  btn2.SetOnClick(Button2Callback);

  // Main loop
  sf::Event e;
  while(window.pollEvent(e)){
    if(e.type == sf::Event::Closed)
      window.close();

    btn.EventHandler(e, window);
  }

  // Render Loop
  btn.Draw(window);
}
```

### Labels

Available functions
```cpp
SetFont(const char*);
SetText(const char*);
SetStyle(unsigned int);
SetPosition(const sf::Vector2f&);
sf::Vector2f GetBounds();
Draw(sf::RenderWindow&) const override;
```
Example code for Labels
```cpp
int main(){
  // Initialize sfml
  Label label(sf::Vector2f(100, 50), 24, sf::Color::Green, "Font/Comfortaa.ttf");
  label.SetText("Hello World!");
  label.SetStyle(sf::Text::Bold | sf::Text::Italic);

  // Render loop
  label.Draw(window);
}
```