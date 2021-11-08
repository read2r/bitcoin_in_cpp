#ifndef __CUSTOMTYPE_H__
#define __CUSTOMTYPE_H__

#include <iostream>

using namespace std;

class Int_c {
private:
    int data, inf;
public:
    Int_c(int _data, int _inf=0);

    bool isInf();

    friend ostream& operator<<(ostream& os, const Int_c& I);
    friend bool operator==(const Int_c& A, const Int_c& B);
    friend bool operator!=(const Int_c& A, const Int_c& B);
    friend Int_c operator+(const Int_c& A, const Int_c& B);
    friend Int_c operator-(const Int_c& A, const Int_c& B);
    friend Int_c operator*(const Int_c& A, const Int_c& B);
    friend Int_c operator/(const Int_c& A, const Int_c& B);
};

#endif
