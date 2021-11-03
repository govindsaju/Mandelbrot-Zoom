#include "mandelbrot.h"
#define itersize 200
Mandelbrot::Mandelbrot(int _dimx,int _dimy) : cm(_dimx,_dimy) , colors(itersize+15)
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
/*
if (c.absval()>5 and (Complex(10,10)-c).absval()>5) return sf::Color::Green;
else return sf::Color::Magenta;
*/
    Complex z;
    int max_iterations = itersize;
    double iteration = 0;  

    while (z.absval()<256 and iteration<max_iterations)
    {
        z = z*z + c;
        iteration+=1;
    }
    bool converges = true;
    if (iteration>=max_iterations) return sf::Color(0,0,0);
    if (iteration<max_iterations)
    {
        double log_zn = log(z.absval());
        double nu = log(log_zn/log(2)) / log(2);
        iteration = iteration + 1 - nu;
    }

    sf::Color c1,c2;
    c1 = colors.palette[floor(iteration)];
    c2 = colors.palette[floor(iteration+1)];
    //todo linear interpolation

    return c1;
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

Complex Mandelbrot::getComplexVal(int i, int j)
{
    return cm.mapping[i][j];
}