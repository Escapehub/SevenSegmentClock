/*
  +-----------------------------------------------------------+
  |                                                           |
  | @file doubledigitdiplsay.h                                |
  |                                                           |
  | @brief Create a double digit display with basic controls  |
  |                                                           |
  +-----------------------------------------------------------+
*/

#ifndef __DOUBLEDIGITDISPLAY__
#define __DOUBLEDIGITDISPLAY__

////////////////////
// Headers
////////////////////
#include "displayhelper.h"

class DoubleDigitDisplay : public DisplayHelper
{
private:
  pDisplay m_pDisplayL;
  pDisplay m_pDisplayR;

public:
  /**
   * Constructor
   * 
   * @param int - max value
   * @param int - offset for left display
   * @param int - offset for right display
   */
  DoubleDigitDisplay(int max, int offsetL, int offsetR)
  { 
    this->setMax(max); 
    m_pDisplayL = new Display(offsetL);
    m_pDisplayR = new Display(offsetR);
  }

  /**
   * Increase value by one
   */
  void Increment()
  {
    this->m_currentNumber = (this->m_currentNumber + 1) % this->getMax();

    std::pair<int, int> no = split(this->m_currentNumber);
    m_pDisplayL->setNumber(no.first);
    m_pDisplayR->setNumber(no.second);
  }

  /**
   * Draw display to screen
   * 
   * @param sf::RenderWindow& - window to draw display to
   */
  void Draw(sf::RenderWindow& window)
  {
    m_pDisplayL->Draw(window);
    m_pDisplayR->Draw(window);
  }

  /**
   * Set current number on display
   * 
   * @param int - number to set too
   */
  void setCurrentNumber(int n) 
  { 
    m_currentNumber = n;
    std::pair<int, int> no = split(n);

    m_pDisplayL->setNumber(no.first);
    m_pDisplayR->setNumber(no.second);
  } 

  /**
   * Get the current number on the display
   * 
   * @return int m_currentNumber
   */
  int getCurrentNumber() 
  { 
    return m_currentNumber; 
  }

  /**
   * Get left display
   * 
   * @return pDisplay - pointer to left display
   */
  pDisplay getLeftDisplay() 
  { 
    return m_pDisplayL; 
  }

  /**
   * Get right display
   * 
   * @return pDisplay - pointer to right display
   */
  pDisplay getRightDisplay() { return m_pDisplayR; }
};

/**
 * Defines a pointer type for DoubleDigitDisplay
 */
typedef DoubleDigitDisplay* pDoubleDigitDisplay;

#endif //!__DOUBLEDIGITDISPLAY__