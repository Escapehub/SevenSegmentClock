#include "display.h"

#ifndef __DISPLAYHELPER__
#define __DISPLAYHELPER__

class DisplayHelper
{
protected:
  int m_max;
  int m_currentNumber;
  int concat(int a, int b)
  {
    return std::stoi(std::to_string(a) + std::to_string(b));
  }
  std::pair<int, int> split(int a)
  {
    if (std::to_string(a).size() == 1)
      return std::pair<int, int>(0, a);
    else 
    {
      int digit = a % 10;
      a /= 10;
      return std::pair<int, int>(a, digit);
    }
  }
public:
  void setMax(int m) { this->m_max = m; }
  int getMax() { return this->m_max; }

  virtual void Increment() {}
};

#endif //!__DISPLAYHELPER__