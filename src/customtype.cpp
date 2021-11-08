#include "customtype.h"
#include <stdexcept>

Int_c::Int_c(int _data, int _inf) : data(_data), inf(_inf) {
    if(inf) {
        data = 0;
    }
}

bool Int_c::isInf() {
    if(inf) {
        return true;
    }
    return false;
}

ostream& operator<<(ostream& os, const Int_c& I) {
    if(I.inf == 1) {
        os << "Infinity";
    } else {
        os << I.data;
    }
    return os;
}

bool operator==(const Int_c& A, const Int_c& B) {
    if(A.inf == 1 && B.inf == 1) {
        return true;
    } else if(A.inf != B.inf ) {
        return false;
    } else if(A.data == B.data) {
        return true;
    } else {
        return false;
    }
}

bool operator!=(const Int_c& A, const Int_c& B) {
    return (A == B);
}

Int_c operator+(const Int_c& A, const Int_c& B) {
    if(A.inf == 1 || B.inf == 1) {
        return Int_c(0, 1);
    }
    return Int_c(A.data + B.data);
}

Int_c operator-(const Int_c& A, const Int_c& B) {
    if(A.inf == 1 || B.inf == 1) {
        return Int_c(0, 1);
    }
    return Int_c(A.data - B.data);
}

Int_c operator*(const Int_c& A, const Int_c& B) {
    if(A.inf == 1 || B.inf == 1) {
        return Int_c(0, 1);
    }
    return Int_c(A.data * B.data);
}

Int_c operator/(const Int_c& A, const Int_c& B) {
    if(B.inf == 1) {
        throw invalid_argument("invalid operation");
    } else if(A.inf == 1) {
        return Int_c(0, 1);
    } else {
        return Int_c(A.data / B.data);
    }
}
