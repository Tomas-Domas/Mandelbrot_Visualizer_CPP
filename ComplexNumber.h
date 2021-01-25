#pragma once

class ComplexNumber {
public:
    double a, b;
    ComplexNumber(double a, double b);
    double iterate(ComplexNumber c);
    double magnitudeSquared();
    ComplexNumber operator+(const ComplexNumber& rhs) const;
    ComplexNumber operator*(const ComplexNumber& rhs) const;
    ComplexNumber operator*(const int lhs) const;
};