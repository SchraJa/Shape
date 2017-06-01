#include <iostream>
#include <cstring>
#include <memory>
#include <cassert>
#include <math.h>

#include "include/Circle.h"
#include "include/Rectangle.h"
#include "include/Triangle.h"

void testCircle();
void testTriangle();
void testRectangle();

Shape* parseArgs(int arg, char **args);
void printHelp();

int main(int arg, char** args)
{
  testCircle();
  testRectangle();
  testTriangle();

  Shape* shape = NULL;
  try {
    shape = parseArgs(arg, args);
  } catch(std::exception& e) {
    std::cout << e.what() << "\n";
    printHelp();
    return 1;
  }

  std::cout << "Perimeter: " << shape->perimeter() << "\n"
            << "Area: " << shape->area() << "\n";

  delete shape;
  return 0;
}

Shape* parseArgs(int arg, char **args)
{
  if (arg < 2 || arg > 5)
    throw std::invalid_argument("ERROR: Cannot run with this parameters");

  if (strcmp(args[1], "k") == 0 && arg == 3)
    return new Circle(std::stof(args[2]));
  else if (strcmp(args[1], "o") == 0 && arg == 4)
    return new Rectangle(std::stof(args[2]), std::stof(args[3]));
  else if (strcmp(args[1], "t") == 0 && arg == 5)
    return new Triangle(std::stof(args[2]), std::stof(args[3]), std::stof(args[4]));
  else if (strcmp(args[1], "h") == 0)
    throw std::invalid_argument("");
  else
    throw std::invalid_argument("ERROR: Unknown type of geometric formation");
}

void printHelp()
{
  std::cout << "How to use this program:\n"
            << "\tCircle:     shape [k] [radius]\n"
            << "\tTriangle:   shape [t] [length a] [length b] [length c]\n"
            << "\tRectangle:  shape [o] [length a] [length b]\n\n";
}


/***********************Tests***********************************/
void testCircle()
{
  Circle circle(1);
  assert(circle.area() == M_PI);
  assert(circle.area() != 0.0);

  try {
    Circle(-1);
  } catch (std::exception &e) {
    assert(strcmp(e.what(), "ERROR: Radius cannot be less than zero or equal.") == 0);
  }
  try {
    Circle(0.0);
  } catch (std::exception &e) {
    assert(strcmp(e.what(), "ERROR: Radius cannot be less than zero or equal.") == 0);
  }

}

void testRectangle()
{
  Rectangle rec(1, 1);
  assert(rec.area() == 1.0);

  Rectangle rec2(2, 2);
  assert(rec2.area() == 4.0);

  Rectangle rec3(5.5, 5);
  assert(rec3.area() == 27.5);

  Rectangle rec4(1.1111, 4);
  assert(std::fabs(4 * 1.1111 - rec4.area()) < 0.0001);

  try {
    Rectangle(-1, 5);
  } catch (std::exception &e) {
    assert(strcmp(e.what(), "ERROR: No side can be less than zero or equal.") == 0);
  }
  try {
    Rectangle(0, 0);
  } catch (std::exception &e) {
    assert(strcmp(e.what(), "ERROR: No side can be less than zero or equal.") == 0);
  }
  try {
    Rectangle(10, -5);
  } catch (std::exception &e) {
    assert(strcmp(e.what(), "ERROR: No side can be less than zero or equal.") == 0);
  }
}

void testTriangle()
{
  try {
    Triangle(1, 1, 0);
  } catch(std::exception &e) {
    assert(strcmp(e.what(), "ERROR: No side can be less than zero or equal.") == 0);
  }
  try {
    Triangle(1, -1, 1);
  } catch(std::exception &e) {
    assert(strcmp(e.what(), "ERROR: No side can be less than zero or equal.") == 0);
  }
  try {
    Triangle(0, 0, 0);
  } catch(std::exception &e) {
    assert(strcmp(e.what(), "ERROR: No side can be less than zero or equal.") == 0);
  }
  try {
    Triangle(0, 1, 10);
  } catch(std::exception &e) {
    assert(strcmp(e.what(), "ERROR: No side can be less than zero or equal.") == 0);
  }
  try {
    Triangle(1, 1, -1.1);
  } catch(std::exception &e) {
    assert(strcmp(e.what(), "ERROR: No side can be less than zero or equal.") == 0);
  }

  try {
    Triangle(1, 1, 2);
  } catch(std::exception &e) {
    assert(strcmp(e.what(), "ERROR: This can be triangle. The sum of two sides "
                            "must be greater than the third!\n") == 0);
  }

  try {
    Triangle(10, 4, 6);
  } catch(std::exception &e) {
    assert(strcmp(e.what(), "ERROR: This can be triangle. The sum of two sides "
                            "must be greater than the third!\n") == 0);
  }
}