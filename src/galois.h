#ifndef _GALOIS_H_
#define _GALOIS_H_

#include <iostream>

using namespace std;

// A Element of Finite Field
class FieldElement {
private:
    int num;
    int prime;
public:
    FieldElement(int n, int p);
    ~FieldElement();

    int getNum();
    int getPrime();
    
    FieldElement pow(int exponent);
    FieldElement pow(int exponent) const;
    friend ostream& operator<<(ostream& os, const FieldElement& fe);
    friend bool operator==(const FieldElement& A, const FieldElement& B);
    friend bool operator!=(const FieldElement& A, const FieldElement& B);
    friend FieldElement operator+(const FieldElement& A, const FieldElement& B);
    friend FieldElement operator-(const FieldElement& A, const FieldElement& B);
    friend FieldElement operator*(const FieldElement& A, const FieldElement& B);
    friend FieldElement operator/(const FieldElement& A, const FieldElement& B);
};

#endif
