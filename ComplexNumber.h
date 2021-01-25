#pragma once

class ComplexNumber {
    double a, b;
public:
    ComplexNumber(double a, double b);
    double magnitudeSquare();
    ComplexNumber operator+(const ComplexNumber& rhs);
};