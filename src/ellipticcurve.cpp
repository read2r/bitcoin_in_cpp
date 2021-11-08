#include "ellipticcurve.h"
#include <iostream>
#include <cmath>
#include <assert.h>
#include <stdexcept>

Point::Point(int _x, int _y, int _a, int _b, int _inf) 
    : x(_x), y(_y), a(_a), b(_b), inf(_inf) {
    if(inf) {
        x = 0;
        y = 0;
    } else {
        int lv = pow((double)y, 2.0);
        int rv = pow((double)x, 3.0) + a * x + b;
        if (lv != rv) {
            throw std::invalid_argument("Not on curve");
        }
    }
}

ostream& operator<<(ostream& os, const Point& P) {
    os << "(" << P.x << ", " << P.y << ")" << "_" << P.a << "_" << P.b;
    return os;
}

bool operator==(const Point& A, const Point& B) {
    return A.a == B.a && A.b == B.b && A.x == B.x && A.y == B.y;
}

bool operator!=(const Point& A, const Point& B) {
    return !(A == B);
}

Point operator+(const Point& A, const Point& B) {
    if(A.a != B.a || A.b != B.b) {
        throw invalid_argument("Not on the same curve");
    } 

    if(A.inf) {
        return Point(B.x, B.y, B.a, B.b);
    } 
    if(B.inf) {
        return Point(A.x, A.y, A.a, A.b);
    }
    
    if(A.x == B.x && A.y != B.y) {
        return Point(0, 0, A.a, A.b, 1);
    }

    if(A.x != B.x) {
        int s = (A.y - B.y) / (A.x - B.x);
        int nx = pow(s, 2) - A.x - B.x;
        int ny = s * (A.x - nx) - A.y;
        return Point(nx, ny, A.a, A.b);
    }

    if(A == B && A.y == 0 * A.x) {
        return  Point(0, 0, A.a, A.b, 1);
    }

    if(A == B) {
        int s = (3 * pow(A.x, 2) + A.a) / (2 * A.y);
        int nx = pow(s, 2) - 2 * A.x;
        int ny = s * (A.x - nx) - A.y;
        return Point(nx, ny, A.a, A.b);
    }

    return  Point(0, 0, A.a, A.b, 1);
}
