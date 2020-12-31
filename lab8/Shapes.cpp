using namespace std;

#include <iostream>
#include <cmath>

#include "Shapes.h"

const float m_PI = 3.141593;
// not all compilers support M_PI from the cmatch header so I've declared it here
// cmath is still needed for tan

const float tan60 = tan(m_PI/3);  // argument is in radians

Shape::Shape(int size, int x, int y)
{
    // ought to do some validation
    this->size = size;
    xpos = x;
    ypos = y;
}

void Shape::changeSize(int newSize)
{
    size = newSize;
}

void Shape::move(int newX, int newY)
{
    xpos = newX;
    ypos = newY;
}

int Shape::getSize() const
{
    return size;
}

int Shape::getX() const
{
    return xpos;
}

int Shape::getY() const
{
    return ypos;
}

void Shape::put(ostream &o) const
{
}

ostream &operator<<(ostream&o, const Shape &s)
{
    s.put(o);
    return o;
}

Circle::Circle(int diam, int x, int y): Shape(diam, x, y)
{
}

float Circle::area() const
{
    int radius = size/2;
    return m_PI * radius * radius;
}

void Circle::put(ostream &o) const
{
    o << "Circle with diameter " << size << " at (" << xpos << ',' << ypos << ')';
}

Square::Square(int size, int x, int y): Shape(size, x, y)
{
}

float Square::area() const
{
    return size*size;
}

void Square::put(ostream &o) const
{
    o << "Square with side length " << size << " at (" << xpos << ',' << ypos << ')';
}

Triangle::Triangle(int size, int x, int y): Shape(size, x, y)
{
}

float Triangle::area() const
{
    return (size/2) * tan60;
}

void Triangle::put(ostream &o) const
{
    o << "Triangle with side length " << size << " at (" << xpos << ',' << ypos << ')';
}
