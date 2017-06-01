//
// Created by schraja on 26.5.17.
//

#ifndef E4T_TRIANGLE_H
#define E4T_TRIANGLE_H

#include "Shape.h"

class Triangle : public Shape
{
  public:
    Triangle(double a, double b, double c);

    double area() const;
    double perimeter() const;
  private:
    double m_A;
    double m_B;
    double m_C;
};


#endif //E4T_TRIANGLE_H
