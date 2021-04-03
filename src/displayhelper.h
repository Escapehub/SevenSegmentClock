/*
  +---------------------------------------------------+
  |                                                   |
  | @file displayhelper.h                             |
  |                                                   |
  | @brief helper functions for doubledigit displays  |
  |                                                   |
  +---------------------------------------------------+
*/

#ifndef __DISPLAYHELPER__
#define __DISPLAYHELPER__

////////////////////
// Headers
////////////////////
#include "display.h"

class DisplayHelper
{
protected:
  int m_max;
  int m_currentNumber;

protected:

  /**
   * Combine two ints into one
   * 
   * @param int left int
   * @param int right int
   * 
   * @return int comined int
   */
  int concat(int a, int b)
  {
    return std::stoi(std::to_string(a) + std::to_string(b));
  }

  /**
   * Split single int into two ints
   * 
   * @param int int to split
   * 
   * @return std::pair<int, int> split its
   */
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

  /**
   * Set member variable m_max
   * 
   * @param int max
   */
  void setMax(int m) 
  { 
    this->m_max = m; 
  }

  /**
   * get member variable m_max
   * 
   * @return int m_max
   */
  int getMax() { return this->m_max; }

  /**
   * Increment number by one
   */
  virtual void Increment() {}
};

#endif //!__DISPLAYHELPER__