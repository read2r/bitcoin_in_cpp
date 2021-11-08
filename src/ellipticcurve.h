#ifndef __ELLIPTIC_CURVE_H__
#define __ELLIPTIC_CURVE_H__

#include <iostream>

using namespace std;

class Point {
private:
    int x, y, a, b, inf;
public:
    Point(int _x, int _y, int _a , int _b, int _inf=0);

    friend ostream& operator<<(ostream& os, const Point& P);
    friend bool operator==(const Point& A, const Point& B);
    friend bool operator!=(const Point& A, const Point& B);
    friend Point operator+(const Point& A, const Point& B);
};

#endif
