#include "segment.h"
#include <vector>

#ifndef __DISPLAY__
#define __DISPLAY__

class Display
{
private:
  std::vector<Segment> m_segments;
  int m_currentNumber; 
public:
  Display();
  Display(int);
  
  void Increment();

  void setNumber(int);

  void Draw(sf::RenderWindow&);

  int getCurrentNumber() { return this->m_currentNumber; }

  void Reset();
};

#endif //!__DISPLAY__
