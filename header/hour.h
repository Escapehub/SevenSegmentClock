#include "displayhelper.h"

#ifndef __HOUR__
#define __HOUR__

class Hour : public DisplayHelper
{
private:
  pDisplay m_DdisplayL = new Display(0);
  pDisplay m_DdisplayR = new Display(255);

public:
  Hour(int max = 24) { this->setMax(max); }

  void Increment() 
  {
    
  }
};

#endif //!__HOUR__
