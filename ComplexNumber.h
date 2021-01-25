#pragma once

class ComplexNumber {
    static const int MAX_ITERATIONS=1000;
    static const char ESCAPE_RADIUS_SQUARED = 4;
    static const double ARBRITARY_SMALL_NUM;
    static ComplexNumber dZ, z;
public:
    long double a, b;
    ComplexNumber(long double a, long double b);
    short getNumEscapeSteps(const ComplexNumber& c);
    long double magnitudeSquared();
    ComplexNumber operator+(const ComplexNumber& rhs) const;
    ComplexNumber operator*(const ComplexNumber& rhs) const;
    ComplexNumber operator*(const int lhs) const;
};