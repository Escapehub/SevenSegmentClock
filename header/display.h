/*
  +-------------------------------------------------------------+
  |                                                             |
  | @file display.h                                             |
  |                                                             |
  | @brief creates 7 segment display with basic control for it  |
  |                                                             |
  +-------------------------------------------------------------+
*/

#ifndef __DISPLAY__
#define __DISPLAY__

////////////////////
// Headers
////////////////////
#include "segment.h"
#include <vector>

class Display
{
private:
  std::vector<Segment> m_segments;
  int m_currentNumber; 
public:

  /**
   * Default constructor
   */
  Display();

  /**
   * Overload constructor
   * 
   * @param int - offset
   */
  Display(int);
  
  /**
   * Incriment display by 1
   */
  void Increment();

  /**
   * Set display to a number
   * 
   * @param int - number to set to
   */
  void setNumber(int);

  /**
   * Draw display to window
   * 
   * @param sf::RenderWindow& reference to window
   */
  void Draw(sf::RenderWindow&);

  /**
   * Get the current number on display
   * 
   * @returns int - m_currentNumber
   */
  int getCurrentNumber() 
  {
    return this->m_currentNumber; 
  }

  /**
   * Reset display to 0
   */
  void Reset();
};

/**
 * Defines a pointer type for Display
 */
typedef Display* pDisplay;

#endif //!__DISPLAY__
