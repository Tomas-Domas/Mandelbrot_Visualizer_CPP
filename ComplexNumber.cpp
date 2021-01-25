#include "ComplexNumber.h"

ComplexNumber ComplexNumber::dZ(1,0);
const double ComplexNumber::ARBRITARY_SMALL_NUM(.001f);

ComplexNumber::ComplexNumber(long double _a, long double _b): a(_a),b(_b) {
}

short ComplexNumber::getNumEscapeSteps(const ComplexNumber& c) {
    dZ.a=1;
    dZ.b=0;
    z.a=0;
    z.b=0;
    for(unsigned short i=0; i<MAX_ITERATIONS; i++){
        //Zn=Z^2+c
        z=z*z+c;
        //dZn=2dZ*Z
//        dZ=dZ*z*2;
        if(z.magnitudeSquared()>=ESCAPE_RADIUS_SQUARED)
            return i;
//        if(dZ.magnitudeSquared()<=ARBRITARY_SMALL_NUM)
//            return -1;
    }
    return -1;
}

long double ComplexNumber::magnitudeSquared() {
    return a*a+b*b;
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