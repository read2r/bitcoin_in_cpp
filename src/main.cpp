#include <iostream>
#include "galois.h"

using namespace std;

int main(void) {
    FieldElement a = FieldElement(3, 31);
    FieldElement b = FieldElement(24, 31);
    cout << (a / b) << endl;

    FieldElement c = FieldElement(17, 31);
    cout << c.pow(-3) << endl;

    FieldElement d = FieldElement(4, 31);
    FieldElement e = FieldElement(11, 31);
    cout << (d.pow(-4) * e) << endl;

    return 0;
}
