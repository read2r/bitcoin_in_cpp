#include <iostream>
#include <cassert>
#include <cmath>
#include "galois.h"

using namespace std;

FieldElement::FieldElement(int n, int p) : num(n), prime(p) {
    if(num >= prime || num < 0) {
        cout << "num : " << num << ", " << "prime : " << prime << endl;
        throw invalid_argument("Num is not in Field range");
    }
}

FieldElement::~FieldElement() {
    //...
}

int FieldElement::getNum() {
    return num;
}

int FieldElement::getPrime() {
    return prime;
}

FieldElement FieldElement::pow(int exponent) {
    int n = exponent;
    while(n < 0) {
        n += prime - 1;
    }
    int result = 1;
    for(int i = 0; i < n; i++) {
        result = (result * num) % prime;
    }
    return FieldElement(result, prime);
}

FieldElement FieldElement::pow(int exponent) const{
    int n = exponent;
    while(n < 0) {
        n += prime - 1;
    }
    int result = 1;
    for(int i = 0; i < n; i++) {
        result = (result * num) % prime;
    }
    return FieldElement(result, prime);
}

ostream& operator<<(ostream& os, const FieldElement& fe) {
    cout << "FieldElement_" << fe.prime << "(" << fe.num << ")";
    return os;
}

bool operator==(const FieldElement& A, const FieldElement& B) {
    return (A.num == B.num && A.prime == B.prime);
}

bool operator!=(const FieldElement& A, const FieldElement& B) {
    return !(A == B);
}

FieldElement operator+(const FieldElement& A, const FieldElement& B) {
    if (A.prime != B.prime) {
        throw invalid_argument("Cannot do operation that two numbers in different Fields");
    }
    int num = (A.num + B.num) % A.prime;
    return FieldElement(num, A.prime);
}

FieldElement operator-(const FieldElement& A, const FieldElement& B) {
    if (A.prime != B.prime) {
        throw invalid_argument("Cannot do operation that two numbers in different Fields");
    }
    int num = (A.num - B.num) % A.prime;
    return FieldElement(num, A.prime);
}

FieldElement operator*(const FieldElement& A, const FieldElement& B) {
    if (A.prime != B.prime) {
        throw invalid_argument("Cannot do operation that two numbers in different Fields");
    }
    int num = 0;
    for(int i = 0; i < B.num; i++) {
        num = (num + A.num) % A.prime;
    }
    return FieldElement(num, A.prime);
}

FieldElement operator/(const FieldElement& A, const FieldElement& B) {
    int num = A.num * B.pow(B.prime-2).num % A.prime;
    return FieldElement(num, A.prime);
}
