#ifndef __MANDELBROT__
#define __MANDELBROT__

#include <SFML/Graphics.hpp>
#include "complex.h"
#include "coordinatemapper.h"
#include "colormapper.h"

class Mandelbrot{
private:
    
    Complex bl,tr;  //bl is bottom left, tr is top right
    CoordinateMapper cm;
    sf::Vertex* pixels;
    int dimx,dimy;
    ColorMapper colors;

public:
    Mandelbrot(int dimx,int dimy);
    ~Mandelbrot();
    sf::Color getColor(Complex c);
    void update(const Complex &_bl,const Complex &_ur);
    sf::Vertex* getPixels();
};

#endif 
