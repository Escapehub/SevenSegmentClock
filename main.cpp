#include "header/doubledigitdisplay.h"

int main()
{
  sf::RenderWindow window(sf::VideoMode(1920, 1080), "Clock");
  
  pDoubleDigitDisplay hours = new DoubleDigitDisplay(24, 0, 255);
  pDoubleDigitDisplay minutes = new DoubleDigitDisplay(60, 500, 750);
  pDoubleDigitDisplay seconds = new DoubleDigitDisplay(60, 1000, 1250);

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
          seconds->Increment();
          if (seconds->getCurrentNumber() == 0)
          {
            minutes->Increment();

            if (minutes->getCurrentNumber() == 0)
              hours->Increment();
          }
        }
      }
    }
    window.clear();
    hours->Draw(window);

    minutes->Draw(window);

    seconds->Draw(window);
    window.display();
  }

  return 0;
}