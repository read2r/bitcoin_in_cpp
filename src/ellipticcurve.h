#ifndef __ELLIPTIC_CURVE_H__
#define __ELLIPTIC_CURVE_H__

class Point {
private:
    int a, b, x, y;
public:
    Point(int x, int y, int a , int b);
    friend bool operator==(const Point& A, const Point& B);
    friend bool operator!=(const Point& A, const Point& B);
};

#endif
