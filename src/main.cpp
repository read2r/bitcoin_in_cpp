#include <iostream>
#include "galois.h"
#include "ellipticcurve.h"

using namespace std;

int main(void) {
    // galois
    FieldElement a = FieldElement(3, 31);
    FieldElement b = FieldElement(24, 31);
    cout << (a / b) << endl;

    FieldElement c = FieldElement(17, 31);
    cout << c.pow(-3) << endl;

    FieldElement d = FieldElement(4, 31);
    FieldElement e = FieldElement(11, 31);
    cout << (d.pow(-4) * e) << endl;

    // elliptic curve
    Point A = Point(-1, -1, 5, 7);
    Point B = Point(18, 77, 5, 7);

    cout << (A == A) << endl;
    cout << (A == B) << endl;
    cout << (A != B) << endl;

    return 0;
}
