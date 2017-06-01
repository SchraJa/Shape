//
// Created by schraja on 27.5.17.
//

#ifndef E4T_SHAPE_H
#define E4T_SHAPE_H


class Shape
{
  public:
    virtual double perimeter() const = 0;
    virtual double area() const = 0;
    virtual ~Shape() {}
};


#endif //E4T_SHAPE_H
