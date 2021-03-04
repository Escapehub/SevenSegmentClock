#include "header/doubledigitdisplay.h"

int main()
{
  sf::RenderWindow window(sf::VideoMode(1920, 1080), "Clock");
  pDoubleDigitDisplay minutes = new DoubleDigitDisplay(60, 500, 750);
  pDoubleDigitDisplay hours = new DoubleDigitDisplay(24, 0, 255);
  
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
          minutes->Increment();

          if (minutes->getCurrentNumber() == 0)
            hours->Increment();
        }
      }
    }
    window.clear();
    minutes->getLeftDisplay()->Draw(window);
    minutes->getRightDisplay()->Draw(window);

    hours->getLeftDisplay()->Draw(window);
    hours->getRightDisplay()->Draw(window);
    window.display();
  }

  return 0;
}