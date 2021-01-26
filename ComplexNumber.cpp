#include "ComplexNumber.h"

ComplexNumber ComplexNumber::dZ(1,0);
ComplexNumber ComplexNumber::z(0,0);
const char ComplexNumber::ESCAPE_RADIUS_SQUARED(4) ;
int ComplexNumber::MAX_ITERATIONS(50);
double ComplexNumber::ARBITRARILY_SMALL_NUM(.0005);

ComplexNumber::ComplexNumber(long double _a, long double _b): a(_a),b(_b) {
}

short ComplexNumber::getNumEscapeSteps() const {
    dZ.a=1;
    dZ.b=0;
    z.a=0;
    z.b=0;
    for(unsigned short i=0; i<MAX_ITERATIONS; i++){
        //Zn=Z^2+c
        z=z*z+*this;
        //dZn=2dZ*Z
        dZ=dZ*z*2;
        if(z.magnitudeSquared()>=ESCAPE_RADIUS_SQUARED)
            return i;
        if(dZ.magnitudeSquared()<=ARBITRARILY_SMALL_NUM)
            return -2;
    }
    return -1;
}

long double ComplexNumber::magnitudeSquared() {
    return a*a+b*b;
}

ComplexNumber ComplexNumber::operator+(const ComplexNumber& rhs) const {
    return {a+rhs.a,b+rhs.b};
}

void ComplexNumber::operator+=(const ComplexNumber &rhs) {
    a+=rhs.a;
    b+=rhs.b;
}

ComplexNumber ComplexNumber::operator*(const ComplexNumber &rhs) const {
    return {a*rhs.a - b*rhs.b, a*rhs.b + b*rhs.a};
}

ComplexNumber ComplexNumber::operator*(const int rhs) const {
    return {a*rhs, b*rhs};
}