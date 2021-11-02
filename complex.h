#ifndef __COMPLEX__
#define __COMPLEX__

#include <iostream>
#include <math.h>

class Complex{
private:

public:

double x,y;

Complex();


Complex(const double &a);
Complex(const double &a, const double &b);

double& real();
double& imaginary();
double absval();
Complex conjug();


friend Complex operator+ (const Complex &a, const Complex &b);
friend Complex operator- (const Complex &a, const Complex &b);
friend Complex operator* (const Complex &a, const Complex &b);
friend Complex operator/ (const Complex &a, const Complex &b);

};


#endif 