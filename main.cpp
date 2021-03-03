#include "header/display.h"

int concat(int, int);

int main()
{
  sf::RenderWindow window(sf::VideoMode(1920, 1080), "Clock");
  Display minutes1(500);
  Display minutes2(750);
  
  Display hours1(0);
  Display hours2(255);
  while (window.isOpen())
  {
    sf::Event event;
    while (window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        window.close();

      if (event.type == sf::Event::KeyPressed)
      {
        if (event.key.code == sf::Keyboard::Enter)
        {
          minutes2.Increment();
          if (minutes2.getCurrentNumber() == 9)
            minutes1.Increment();

          if (concat(minutes1.getCurrentNumber(), minutes2.getCurrentNumber())  == 59)
          {
              hours2.Increment();
              minutes1.Reset();
              minutes2.Reset();
          }
        }
      }
    }

    window.clear();
    hours1.Draw(window);
    hours2.Draw(window);
    minutes1.Draw(window);
    minutes2.Draw(window);
    window.display();
  }

  return 0;
}

int concat(int a, int b)
{
  std::string as = std::to_string(a);
  std::string bs = std::to_string(b);

  std::string abs = as + bs;

  return std::stoi(abs);
}
