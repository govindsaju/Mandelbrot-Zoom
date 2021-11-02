#ifndef __MANDELBROT__
#define __MANDELBROT__

#include <SFML/Graphics.hpp>
#include "complex.h"
#include "coordinatemapper.h"

class Mandelbrot{
private:
    sf::RenderWindow *window;
    Complex bl,tr;  //bl is bottom left, tr is top right
    CoordinateMapper cm;
    sf::VertexArray pixels;
    int dimx,dimy;
public:
    Mandelbrot(sf::RenderWindow *_window,int dimx,int dimy);
    sf::Color getColor(Complex c);
    void update(const Complex &_bl,const Complex &_ur);
    void render();
};

#endif 
