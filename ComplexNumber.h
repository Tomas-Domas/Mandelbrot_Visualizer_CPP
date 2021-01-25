#pragma once

class ComplexNumber {
    static const int MAX_ITERATIONS=1000;
    static const char ESCAPE_RADIUS_SQUARED = 4;
    static const double ARBRITARY_SMALL_NUM;
    static ComplexNumber dZ, z;
public:
    double a, b;
    ComplexNumber(double a, double b);
    int getNumEscapeSteps(const ComplexNumber& c);
    double magnitudeSquared();
    ComplexNumber operator+(const ComplexNumber& rhs) const;
    ComplexNumber operator*(const ComplexNumber& rhs) const;
    ComplexNumber operator*(const int lhs) const;
};