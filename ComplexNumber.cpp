#include "ComplexNumber.h"

ComplexNumber::ComplexNumber(double _a, double _b): a(_a),b(_b) {

}

double ComplexNumber::iterate(ComplexNumber c) {

}

double ComplexNumber::magnitudeSquared() {
    return 0;
}

ComplexNumber ComplexNumber::operator+(const ComplexNumber& rhs) const {
    return {a+rhs.a,b+rhs.b};
}

ComplexNumber ComplexNumber::operator*(const ComplexNumber &rhs) const {
    return {a*rhs.a - b*rhs.b, a*rhs.b + b*rhs.a};
}

ComplexNumber ComplexNumber::operator*(const int rhs) const {
    return {a*rhs, b*rhs};
}