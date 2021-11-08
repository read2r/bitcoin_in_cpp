#include <iostream>
#include "galois.h"
#include "ellipticcurve.h"
#include "customtype.h"

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
    cout << (d.pow(-4) * e) << endl << endl;

    // elliptic curve
    Point A = Point(-1, -1, 5, 7);
    Point B = Point(18, 77, 5, 7);
    Point C = Point(0, 0, 5, 7, 1);

    cout << (A == A) << endl;
    cout << (A == B) << endl;
    cout << (A != B) << endl << endl;

    // elliptic curve operator+
    Point p1 = Point(-1, -1, 5, 7);
    Point p2 = Point(-1, 1, 5, 7);
    Point inf = Point(1, 1, 5, 7, 1);
    cout << (p1 + inf) << endl;
    cout << (inf + p2) << endl << endl;

    Point p3 = Point(2, 5, 5, 7);
    Point p4 = Point(-1, -1, 5, 7);
    cout << (p3 + p4) << endl << endl;

    Point p5 = Point(-1, -1, 5, 7);
    cout << (p5 + p5) << endl << endl;

    // Int_c
    Int_c ic1 = Int_c(2);
    Int_c ic2 = Int_c(4);
    Int_c ic3 = Int_c(8);
    Int_c ic4 = Int_c(8, 1);

    cout << "ic1 : " << ic1 << endl;
    cout << "ic2 : " << ic2 << endl;
    cout << "ic3 : " << ic3 << endl;
    cout << "ic4 : " << ic4 << endl << endl;

    return 0;
}
