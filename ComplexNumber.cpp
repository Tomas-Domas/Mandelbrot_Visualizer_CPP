#include "ComplexNumber.h"

ComplexNumber::ComplexNumber(double _a, double _b): a(_a),b(_b) {
}

double ComplexNumber::magnitudeSquare() {
    return 0;
}

ComplexNumber ComplexNumber::operator+(const ComplexNumber& rhs) {
    return ComplexNumber(a+rhs.a,b+rhs.b);
}