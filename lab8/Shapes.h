#ifndef _SHAPES_H_
#define _SHAPES_H_

using namespace std;

#include <iostream>

class Shape
{
public:
    Shape(int size, int x, int y);
    void changeSize(int newSize);
    void move(int newX, int newY);
    int getSize() const, getX() const, getY() const;
    virtual float area() const = 0;
    virtual ~Shape() {}
protected:
    virtual void put(ostream &o) const = 0;
    int size, xpos, ypos;
    friend ostream &operator<<(ostream &o, const Shape &s);
};

class Circle: public Shape
{
public:
    Circle(int diam, int x, int y);
    float area() const;
protected:
    void put(ostream &o) const;
};

class Square: public Shape
{
public:
    Square(int size, int x, int y);
    float area() const;
protected:
    void put(ostream &o) const;
};

class Triangle: public Shape
{
public:
    Triangle(int size, int x, int y);
    float area() const;
protected:
    void put(ostream &o) const;
};

#endif
