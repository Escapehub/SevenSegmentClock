#include "display.h"

class DisplayHelper
{
protected:
  int m_max;
  int m_currentNumber = 0;
  int concat(int a, int b)
  {
    return std::stoi(std::to_string(a) + std::to_string(b));
  }
  std::pair<int, int> split(int a)
  {
    std::string sa = std::to_string(a);
    return std::pair<int, int>(sa[0], sa[1]);
  }
public:
  void setMax(int m) { this->m_max = m; }
  int getMax() { return this->m_max; }

  virtual void Increment() {}
};
