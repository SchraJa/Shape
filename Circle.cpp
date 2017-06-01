//
// Created by schraja on 26.5.17.
//
#include <cmath>
#include <stdexcept>

#include "include/Circle.h"

Circle::Circle(double radius)
  : m_Radius(radius)
{
  if (radius <= 0)
    throw std::logic_error("ERROR: Radius cannot be less than zero or equal.");
}

double Circle::area() const
{
  return m_Radius * m_Radius * M_PI;
}

double Circle::perimeter() const
{
  return 2 * M_PI * m_Radius;
}