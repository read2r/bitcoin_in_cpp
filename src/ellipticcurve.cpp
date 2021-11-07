#include "ellipticcurve.h"
#include <iostream>
#include <math.h>
#include <assert.h>
#include <stdexcept>

Point::Point(int _x, int _y, int _a, int _b) : x(_x), y(_y), a(_a), b(_b) {
    int lv = pow((double)y, 2.0);
    int rv = pow((double)x, 3.0) + a * x + b;
    if (lv != rv) {
        throw std::invalid_argument("Not on Curve");
    }
}

bool operator==(const Point& A, const Point& B) {
    return A.x == B.x && A.y == B.y && A.a == B.a && A.b == B.b;
}

bool operator!=(const Point& A, const Point& B) {
    return !(A == B);
}
