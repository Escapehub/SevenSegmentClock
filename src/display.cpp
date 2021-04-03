#include "display.h"

Display::Display()
{
  Segment seg1(POS_TOP_MIDDLE);
  this->m_segments.push_back(seg1);
  Segment seg2(POS_TOP_LEFT);
  this->m_segments.push_back(seg2);
  Segment seg3(POS_TOP_RIGHT);
  this->m_segments.push_back(seg3);
  Segment seg4(POS_MIDDLE);
  this->m_segments.push_back(seg4);
  Segment seg5(POS_BOTTOM_LEFT);
  this->m_segments.push_back(seg5);
  Segment seg6(POS_BOTTOM_RIGHT);
  this->m_segments.push_back(seg6);
  Segment seg7(POS_BOTTOM_MIDDLE);
  this->m_segments.push_back(seg7);

  // Default display to 0
  this->m_segments[0].Show();
  this->m_segments[1].Show();
  this->m_segments[2].Show();
  this->m_segments[3].Hide();
  this->m_segments[4].Show();
  this->m_segments[5].Show();
  this->m_segments[6].Show();
}

Display::Display(int offset)
{
  Segment seg1(POS_TOP_MIDDLE, offset);
  this->m_segments.push_back(seg1);
  Segment seg2(POS_TOP_LEFT, offset);
  this->m_segments.push_back(seg2);
  Segment seg3(POS_TOP_RIGHT, offset);
  this->m_segments.push_back(seg3);
  Segment seg4(POS_MIDDLE, offset);
  this->m_segments.push_back(seg4);
  Segment seg5(POS_BOTTOM_LEFT, offset);
  this->m_segments.push_back(seg5);
  Segment seg6(POS_BOTTOM_RIGHT, offset);
  this->m_segments.push_back(seg6);
  Segment seg7(POS_BOTTOM_MIDDLE, offset);
  this->m_segments.push_back(seg7);

  // Default display to 0
  this->m_segments[0].Show();
  this->m_segments[1].Show();
  this->m_segments[2].Show();
  this->m_segments[3].Hide();
  this->m_segments[4].Show();
  this->m_segments[5].Show();
  this->m_segments[6].Show();

}

void Display::Increment()
{
  this->m_currentNumber = (this->m_currentNumber + 1) % 10;
}

void Display::setNumber(int n)
{
  if (n > 9 || n < 0) return;
  
  this->m_currentNumber = n;
}

void Display::Draw(sf::RenderWindow& window)
{
  switch (this->m_currentNumber)
  {
    case 0:
      this->m_segments[0].Show();
      this->m_segments[1].Show();
      this->m_segments[2].Show();
      this->m_segments[3].Hide();
      this->m_segments[4].Show();
      this->m_segments[5].Show();
      this->m_segments[6].Show();
      break;
   
    case 1:
      this->m_segments[0].Hide();
      this->m_segments[1].Hide();
      this->m_segments[2].Show();
      this->m_segments[3].Hide();
      this->m_segments[4].Hide();
      this->m_segments[5].Show();
      this->m_segments[6].Hide();
      break;
   
    case 2:
      this->m_segments[0].Show();
      this->m_segments[1].Hide();
      this->m_segments[2].Show();
      this->m_segments[3].Show();
      this->m_segments[4].Show();
      this->m_segments[5].Hide();
      this->m_segments[6].Show();
      break;
   
    case 3:
      this->m_segments[0].Show();
      this->m_segments[1].Hide();
      this->m_segments[2].Show();
      this->m_segments[3].Show();
      this->m_segments[4].Hide();
      this->m_segments[5].Show();
      this->m_segments[6].Show();
      break;
   
    case 4:
      this->m_segments[0].Hide();
      this->m_segments[1].Show();
      this->m_segments[2].Show();
      this->m_segments[3].Show();
      this->m_segments[4].Hide();
      this->m_segments[5].Show();
      this->m_segments[6].Hide();
      break;
    
    case 5:
      this->m_segments[0].Show();
      this->m_segments[1].Show();
      this->m_segments[2].Hide();
      this->m_segments[3].Show();
      this->m_segments[4].Hide();
      this->m_segments[5].Show();
      this->m_segments[6].Show();
      break;
   
    case 6:
      this->m_segments[0].Show();
      this->m_segments[1].Show();
      this->m_segments[2].Hide();
      this->m_segments[3].Show();
      this->m_segments[4].Show();
      this->m_segments[5].Show();
      this->m_segments[6].Show();
      break;
   
    case 7:
      this->m_segments[0].Show();
      this->m_segments[1].Hide();
      this->m_segments[2].Show();
      this->m_segments[3].Hide();
      this->m_segments[4].Hide();
      this->m_segments[5].Show();
      this->m_segments[6].Hide();
      break;
   
    case 8:
      this->m_segments[0].Show();
      this->m_segments[1].Show();
      this->m_segments[2].Show();
      this->m_segments[3].Show();
      this->m_segments[4].Show();
      this->m_segments[5].Show();
      this->m_segments[6].Show();
      break;
   
    case 9:
      this->m_segments[0].Show();
      this->m_segments[1].Show();
      this->m_segments[2].Show();
      this->m_segments[3].Show();
      this->m_segments[4].Hide();
      this->m_segments[5].Show();
      this->m_segments[6].Hide();
      break;
  }
  for (Segment seg : this->m_segments)
    window.draw(seg);
}

void Display::Reset()
{
  this->m_currentNumber = 0;
  this->m_segments[0].Show();
  this->m_segments[1].Show();
  this->m_segments[2].Show();
  this->m_segments[3].Hide();
  this->m_segments[4].Show();
  this->m_segments[5].Show();
  this->m_segments[6].Show();
}
