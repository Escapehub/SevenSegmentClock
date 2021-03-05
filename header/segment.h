/*
  +---------------------------------------------------+
  |                                                   |
  | @file segment.h                                   |
  |                                                   |
  | @brief Defines controls for a segment that makes  |
  |     up one of 7 in a display                      |
  |                                                   |
  +---------------------------------------------------+
*/

#ifndef __SEGMENT__
#define __SEGMENT__

////////////////////
// Headers
////////////////////
#include <SFML/Graphics.hpp>

////////////////////
// Enum definitions
////////////////////
#define POS_TOP_MIDDLE Segment::Pos::TOP_MIDDLE
#define POS_TOP_RIGHT Segment::Pos::TOP_RIGHT
#define POS_TOP_LEFT Segment::Pos::TOP_LEFT
#define POS_MIDDLE Segment::Pos::MIDDLE
#define POS_BOTTOM_RIGHT Segment::Pos::BOTTOM_RIGHT
#define POS_BOTTOM_LEFT Segment::Pos::BOTTOM_LEFT
#define POS_BOTTOM_MIDDLE Segment::Pos::BOTTOM_MIDDLE


class Segment : public sf::RectangleShape
{
public:
  enum Pos
  {
    TOP_MIDDLE    = 0,
    TOP_RIGHT     = 1,
    TOP_LEFT      = 2,
    MIDDLE        = 3,
    BOTTOM_RIGHT  = 4,
    BOTTOM_LEFT   = 5,
    BOTTOM_MIDDLE = 6
  };

private:
  Pos m_currentPos;

public:

  /**
   * Constructor
   * 
   * @param Pos - position to set segment too
   * @param int - offset
   */
  Segment(Pos, int = 0);

  /**
   * Hide current segment
   */
  void Hide();

  /**
   * Show current segment
   */
  void Show();
};

#endif //!__SEGMENT__
