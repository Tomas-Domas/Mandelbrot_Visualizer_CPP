#pragma once

class ComplexNumber {
    static const char ESCAPE_RADIUS_SQUARED;
    static ComplexNumber dZ, z;
public:
    static int MAX_ITERATIONS;
    static double ARBITRARILY_SMALL_NUM;
    long double a, b;
    ComplexNumber(long double a, long double b);
    short getNumEscapeSteps() const;
    long double magnitudeSquared();
    ComplexNumber operator+(const ComplexNumber& rhs) const;
    void operator+=(const ComplexNumber& rhs);
    ComplexNumber operator*(const ComplexNumber& rhs) const;
    ComplexNumber operator*(int lhs) const;
};