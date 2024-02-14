# JGui
A simple GUI library for SFML

## How to use (in code)

Initialization for Button and Label

```cpp
// Button takes Position Scale, and Fill color
Button btn(sf::Vector2f(100.0f, 100.0f), sf::Vector2f(200.0f, 50.0f), sf::Color::Blue);

// Label takes Position Char size, Fill color, and Font location
Label label(sf::Vector2f(100.0f, 50.0f), 24, sf::Color::Red, "Font/Comfortaa.ttf");
```

Label has extra param to set after constructor

```cpp
// Set the text (const char*)
label.SetText("Hello");

// Set style uses unsigned int
label.SetStyle(sf::Text::Bold);
```

But how do you know if the button has been pressed?

```cpp
// Lambda
btn.SetOnClick([](){
  std::cout << "Button Clicked!\n";
}

// Function

void callbackFunc(){
  std::cout << "Button Clicked!\n";
}

btn.SetOnClick(callbackFunc);
```

Now the last thing to do to use them is to implement button event function in your event code and the render code in your render loop

```cpp
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
```
