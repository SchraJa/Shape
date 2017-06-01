//
// Created by schraja on 27.5.17.
//

#ifndef E4T_RECTANGLE_H
#define E4T_RECTANGLE_H

#include "Shape.h"

class Rectangle : public Shape
{
  public:
    Rectangle(double x, double y);

    double area() const;
    double perimeter() const;
  private:
    double m_X;
    double m_Y;
};


#endif //E4T_RECTANGLE_H
