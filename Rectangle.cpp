//
// Created by schraja on 27.5.17.
//

#include <stdexcept>
#include "include/Rectangle.h"

Rectangle::Rectangle(double x, double y)
  : m_X(x), m_Y(y)
{
  if (m_X <= 0 || m_Y <= 0)
    throw std::logic_error("ERROR: No side can be less than zero or equal.");
}

double Rectangle::area() const
{
  return m_X * m_Y;
}

double Rectangle::perimeter() const
{
  return 2 * (m_X + m_Y);
}