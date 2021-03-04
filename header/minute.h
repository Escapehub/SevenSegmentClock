#include "displayhelper.h"

#ifndef __MINUTE__
#define __MINUTE__

class Minute : public DisplayHelper
{
private:
  pDisplay m_pDisplayL = new Display(500);
  pDisplay m_pDisplayR = new Display(750);

public:
  Minute(int max = 60) { this->setMax(max); }

  void Increment() 
  {
    this->m_pDisplayR->Increment();

  }
};

#endif //!__MINUTE__