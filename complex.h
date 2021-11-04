/**
 * @file complex.h
 * @brief File for defining Complex class
 */
#ifndef __COMPLEX__
#define __COMPLEX__

#include <iostream>
#include <math.h>

/**
 * @brief A class for complex number arithmetic 
 */
class Complex{
private:

public:

//x stores the real number, y stores the imaginary coordinate
double x,y;

/**
 * @brief Construct a new Complex object, default value 0 + 0i
 */
Complex();

/**
 * @brief Construct a new Complex object, of the form a + 0i
 * @param a The real part of the complex number
 */
Complex(const double &a);

/**
 * @brief Construct a new Complex object, of the form a+bi
 * 
 * @param a The real part of the complex number
 * @param b The imaginary part of the complex number
 */
Complex(const double &a, const double &b);

/**
 * @brief Returns a reference to the real part
 * @return double& 
 */
double& real();

/**
 * @brief Returns a reference to the imaginary part 
 * @return double& 
 */
double& imaginary();

/**
 * @brief Returns the absolute value of the complex number
 * @return double the absolute value
 */
double absval();

/**
 * @brief Returns the complex conjugate of the function
 * @return Complex the complex conjugate
 */
Complex conjug();

//operator overloading for basic arithmetic operations

friend Complex operator+ (const Complex &a, const Complex &b);
friend Complex operator- (const Complex &a, const Complex &b);
friend Complex operator* (const Complex &a, const Complex &b);
friend Complex operator/ (const Complex &a, const Complex &b);

};


#endif 