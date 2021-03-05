#include "header/doubledigitdisplay.h"
#include "header/timer.h"

int main()
{
  sf::RenderWindow window(sf::VideoMode(1500, 400), "Clock");
  Timer t = Timer();
  
  pDoubleDigitDisplay hours = new DoubleDigitDisplay(24, 0, 255);
  pDoubleDigitDisplay minutes = new DoubleDigitDisplay(60, 500, 750);
  pDoubleDigitDisplay seconds = new DoubleDigitDisplay(60, 1000, 1250);

  std::time_t now = std::time(nullptr);
  std::tm tt = *std::localtime(std::addressof(now));

  hours->setCurrentNumber(tt.tm_hour);
  minutes->setCurrentNumber(tt.tm_min);
  seconds->setCurrentNumber(tt.tm_sec);

  t.setInterval([&]() {
    seconds->Increment();
    if (seconds->getCurrentNumber() == 0)
    {
      minutes->Increment();

      if (minutes->getCurrentNumber() == 0)
        hours->Increment();
    }
  }, 1000);

  while (window.isOpen())
  {
    sf::Event event;
    while (window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        window.close();
    }

    window.clear();
    hours->Draw(window);
    minutes->Draw(window);
    seconds->Draw(window);
    window.display();
  }

  return 0;
}