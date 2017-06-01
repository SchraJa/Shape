//
// Created by schraja on 26.5.17.
//

#ifndef E4T_CIRCLE_H
#define E4T_CIRCLE_H

#include "Shape.h"

class Circle : public Shape
{
  public:
    Circle(double radius);

    double area() const;
    double perimeter() const;
  private:
    double m_Radius;
};


#endif //E4T_CIRCLE_H
