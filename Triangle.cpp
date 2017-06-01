//
// Created by schraja on 26.5.17.
//

#include <iostream>
#include <cmath>
#include "include/Triangle.h"

Triangle::Triangle(double a, double b, double c)

{
  if (a <= 0 || b <= 0 || c <= 0)
    throw std::logic_error("ERROR: No side can be less than zero or equal.");

  if (a + b <= c || a + c <= b || b + c <= a)
    throw std::logic_error("ERROR: This can be triangle. The sum of two sides "
                           "must be greater than the third!\n");

  m_A = a;
  m_B = b;
  m_C = c;
}

double Triangle::area() const
{
  double s = perimeter() / 2;

  return std::sqrt(s * (s - m_A) * (s - m_B) * (s - m_C));
}

double Triangle::perimeter() const
{
  return m_A + m_B + m_C;
}