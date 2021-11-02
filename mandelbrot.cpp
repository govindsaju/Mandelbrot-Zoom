#include "mandelbrot.h"

Mandelbrot::Mandelbrot(sf::RenderWindow *_window,int _dimx,int _dimy) : cm(_dimx,_dimy)
{
    pixels.resize(dimx*dimy);
    dimx = _dimx;
    dimy = _dimy;
}
sf::Color Mandelbrot::getColor(Complex c)
{
    return sf::Color::Green;
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

void Mandelbrot::render()
{
    window->draw(pixels);
}