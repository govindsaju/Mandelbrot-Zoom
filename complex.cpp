#include "complex.h"

Complex::Complex() 
{
    this->x = 0.0;
    this->y = 0.0;
}

Complex::Complex(const double &a)
{
    this->x = a;
    this->y = 0.0;
}

Complex::Complex(const double &a, const double &b)
{
    this->x = a;
    this->y = b;
}

double& Complex::real()
{
    return x;
}

double& Complex::imaginary()
{
    return y;
}

double Complex::absval()
{
    return sqrt(x*x+y*y);
}

Complex Complex::conjug()
{
    return Complex(x,-y);
}

Complex operator+(const Complex &a, const Complex &b)
{
    return Complex(a.x+b.x,a.y+b.y);
}

Complex operator-(const Complex &a, const Complex &b)
{
    return Complex(a.x-b.x,a.y-b.y);
}

Complex operator*(const Complex &a, const Complex &b)
{
    return Complex(a.x*b.x - a.y*b.y,a.x*b.y+a.y*b.x);
}

Complex operator/(const Complex &a, const Complex &b)
{
    return Complex((a.x*b.x + a.y*b.y)/(b.x*b.x + b.y*b.y),(a.y*b.x - a.x*b.y)/(b.x*b.x + b.y*b.y));
}

