#include "../header/segment.h"

Segment::Segment(Pos p, int offset)
{
  this->setFillColor(sf::Color::White);
  this->setSize(sf::Vector2f(100, 50));
  this->setOrigin(this->getSize().x / 2, this->getSize().y / 2);
  switch (p)
  {
    case POS_TOP_MIDDLE:
      this->setPosition(125 + offset, 50);
      break;

    case POS_TOP_RIGHT:
      this->setRotation(90);
      this->setPosition(200 + offset, 125);
      break;

    case POS_TOP_LEFT:
      this->setRotation(90);
      this->setPosition(50 + offset, 125);
      break;

    case POS_MIDDLE:
      this->setPosition(125 + offset, 200);
      break;

    case POS_BOTTOM_LEFT:
      this->setRotation(90);
      this->setPosition(50 + offset, 275);
      break;

    case POS_BOTTOM_RIGHT:
      this->setRotation(90);
      this->setPosition(200 + offset, 275);
      break;

    case POS_BOTTOM_MIDDLE:
      this->setPosition(125 + offset, 350);
      break;
  }
}

void Segment::Hide()
{
  this->setFillColor(sf::Color::Black);
}

void Segment::Show()
{
  this->setFillColor(sf::Color::White);
}
