#include "mandelbrot.h"

Mandelbrot::Mandelbrot(sf::RenderWindow *_window,int _dimx,int _dimy) : cm(_dimx,_dimy) 
{
    dimx = _dimx;
    dimy = _dimy;
    pixels = new sf::Vertex[_dimx*_dimy];
}

Mandelbrot::~Mandelbrot()
{
    delete pixels;
}

sf::Color Mandelbrot::getColor(Complex c)
{
    if (c.absval()>5 and (Complex(10,10)-c).absval()>5) return sf::Color::Green;
    else return sf::Color::Magenta;
}
void Mandelbrot::update(const Complex &bl, const Complex &tr)
{
    cm.update(bl,tr);
    for (int i=0;i<dimx;i++)
    {
        for (int j=0;j<dimy;j++)
        {
            pixels[i*dimy + j].position.x = i;
            pixels[i*dimy + j].position.y = j;
            pixels[i*dimy + j].color = getColor(cm.mapping[i][j]);
        }
    }
}

sf::Vertex* Mandelbrot::getPixels()
{   
    return pixels;
    
}