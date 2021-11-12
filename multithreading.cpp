#include "multithreading.h"
sf::Color RunThread::getColor(Complex c, ColorMapper &colors, int colorshift, int max_iterations)
{
    Complex z;
    double iteration = 0;  

    //checks for convergence
    while (z.absval()<256 and iteration<max_iterations)
    {
        z = z*z + c;
        iteration+=1;
    }
    bool converges = true;
    if (iteration>=max_iterations) return sf::Color(0,0,0); //if inside mandelbrot set, paint it black

    //converting iteration number to real number to reduce discreteness
    if (iteration<max_iterations)
    {
        double log_zn = log(z.absval());
        double nu = log(log_zn/log(2)) / log(2);
        iteration = iteration + 1 - nu;
    }

    //Obtain colours , perform linear interpolation to obtain smooth boundaries 
    sf::Color c1,c2;
    c1 = colors.palette[static_cast<int>(floor(iteration)+colorshift)%colors.palette.size()];
    c2 = colors.palette[ static_cast<int>(floor(iteration+1)+colorshift) % (colors.palette.size()) ];

    double coeff = iteration - floor(iteration);
    c1.r = c1.r*(1-coeff) + c2.r*(coeff);
    c1.g = c1.g*(1-coeff) + c2.g*(coeff);
    c1.b = c1.b*(1-coeff) + c2.b*(coeff);

    return c1;
}

//threadindex from 0 to numthreads-1
void RunThread::operator()(int threadindex, ColorMapper colors, std::vector<sf::Vertex> &pixels, CoordinateMapper cm, int colorshift, int dimx, int dimy,int numthreads, int maxiterations)
{
    int i_min = threadindex*(dimx/numthreads);
    int i_max;

    if (threadindex==numthreads-1) i_max = dimx-1;
    else i_max = (threadindex+1)*(dimx/numthreads) - 1;
    pixels.resize((i_max-i_min+1)*dimy);


    for (int i=i_min;i<=i_max;i++)
    {
        int i_vec_index = i-i_min;
        for (int j=0;j<dimy;j++)
        {
            pixels[i_vec_index*dimy + j].position.x = i;
            pixels[i_vec_index*dimy + j].position.y = j;
            pixels[i_vec_index*dimy + j].color = getColor(cm.findmapping(i,j),colors,colorshift,maxiterations);
        }
    }
}
