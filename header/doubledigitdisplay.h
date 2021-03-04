#include "displayhelper.h"

#ifndef __DOUBLEDIGITDISPLAY__
#define __DOUBLEDIGITDISPLAY__

class DoubleDigitDisplay : public DisplayHelper
{
private:
  pDisplay m_pDisplayL;
  pDisplay m_pDisplayR;

public:
  DoubleDigitDisplay(int max, int offsetL, int offsetR)
  { 
    this->setMax(max); 
    this->m_currentNumber = 0;
    m_pDisplayL = new Display(offsetL);
    m_pDisplayR = new Display(offsetR);
  }

  void Increment()
  {
    this->m_currentNumber = (this->m_currentNumber + 1) % this->getMax();

    std::pair<int, int> no = split(this->m_currentNumber);
    m_pDisplayL->setNumber(no.first);
    m_pDisplayR->setNumber(no.second);
  }

  int getCurrentNumber() { return m_currentNumber; }

  pDisplay getLeftDisplay() { return m_pDisplayL; }
  pDisplay getRightDisplay() { return m_pDisplayR; }
};

typedef DoubleDigitDisplay* pDoubleDigitDisplay;

#endif //!__DOUBLEDIGITDISPLAY__