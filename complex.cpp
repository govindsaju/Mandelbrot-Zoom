#include "complex.h"

//Constructors for Complex based on number of parameters
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


//returns reference to real part
double& Complex::real()
{
    return x;
}

//returns reference to imaginary part
double& Complex::imaginary()
{
    return y;
}

//returns the absolute value of complex number
double Complex::absval()
{
    return sqrt(x*x+y*y);
}

//returns the complex conjugate of the complex number
Complex Complex::conjug()
{
    return Complex(x,-y);
}


//Operator overloads for addition, subtraction, division and multiplication

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

