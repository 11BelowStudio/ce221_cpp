/*
initially copied from slide 31 of lecture 9 as instructed
*/

#include "Shapes.h"
#include <vector>
#include <iterator>

int main()
{

    Circle c(12,4,8);

    Shape &s1 = c;

    Shape *p1 = &c;

    cout << s1.area() << ", " << p1->area() << endl;

    cout << c << endl;

    cout << s1 << endl;

    cout << *p1 << endl;



    Square sq(5, 12, 12);

    Shape &s2 = sq;

    Shape *p2 = &sq;

    cout << s2.area() << ", " << p2->area() << endl;

    cout << sq << endl;

    s2.changeSize(10);

    cout << s2 << endl;

    cout << *p2 << endl;



    Triangle t(8,0,4);

    Shape &s3 = t;

    t.move(1,2);

    Shape *p3 = &t;

    cout << s3.area() << ", " << p3->area() << endl;

    cout << t << endl;

    cout << s3 << endl;

    cout << *p3 << endl;

    cout << endl << endl << "vector time" << endl;


    vector<Shape*> sVec;

    Shape *p4 = new Triangle(1,4,5);
    Shape *p5 = new Square(24,57,2);
    Shape *p6 = new Circle(2,6,-2);
    Shape *p7 = new Triangle(12,6,73);
    Shape *p8 = new Square(6,-4,5);
    Shape *p9 = new Circle(10,-5,-5);

    sVec.push_back(p1);
    sVec.push_back(p2);
    sVec.push_back(p3);
    sVec.push_back(p4);
    sVec.push_back(p5);
    sVec.push_back(p6);
    sVec.push_back(p7);
    sVec.push_back(p8);
    sVec.push_back(p9);

    vector<Shape*>::iterator it;

    for (it = sVec.begin(); it != sVec.end(); it++)
    {
        cout << **it << endl;
    }


    return 0;
}
