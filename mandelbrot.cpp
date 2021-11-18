#include "mandelbrot.h"
#define numthreads 8
#define itersize 200

//constructor for mandelbrot object
Mandelbrot::Mandelbrot(int _dimx,int _dimy) : cm(_dimx,_dimy) , colors(itersize+15)
{
    dimx = _dimx;
    dimy = _dimy;
    pixels = new sf::Vertex[_dimx*_dimy];
    colorshift = 0;
    max_iterations = itersize;
}

//destructor for mandelbrot object
Mandelbrot::~Mandelbrot()
{
    delete pixels;
}

//returns a color for a given complex number, does the math of the mandelbrot set
sf::Color Mandelbrot::getColor(Complex c)
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

void Mandelbrot::update_pixel(int i,int j)
{
    pixels[i*dimy + j].position.x = i;
    pixels[i*dimy + j].position.y = j;
    pixels[i*dimy + j].color = getColor(cm.findmapping(i,j));
}

//updates the parameters based on new bottom left and top right mapping
void Mandelbrot::update(const Complex &bl, const Complex &tr)
{
    cm.update(bl,tr);
    this->bl = bl;
    this->tr = tr;
    updateMaxIterations();
    for (int i=0;i<dimx;i++)
    {
        for (int j=0;j<dimy;j++)
        {
           update_pixel(i,j);
        }
    }

}


void Mandelbrot::update_multithreaded(const Complex &bl, const Complex &tr)
{
    cm.update(bl,tr);
    std::vector<sf::Vertex> vertices[numthreads];
    std::thread threads[numthreads];

    for (int i=0;i<numthreads;i++)
    {
        threads[i] = std::thread((RunThread()),i,colors,std::ref(vertices[i]),cm,colorshift,dimx,dimy,numthreads,itersize);

    }

    for (int i=0;i<numthreads;i++)
    {
        threads[i].join();
    }

    for (int i=0;i<dimx;i++)
    {
        int compartment_number = i/(dimx/numthreads);
        int i_inside = i - (compartment_number * (dimx/numthreads));
        for (int j=0;j<dimy;j++)
        {

            pixels[i*dimy+j] = vertices[compartment_number][i_inside * dimy + j];
        }
    }


}
//returns the pixelarray to plot on the window
sf::Vertex* Mandelbrot::getPixels()
{   
    return pixels;
    
}

//returns complex value mapped to (i,j)
Complex Mandelbrot::getComplexVal(int i, int j)
{
    return cm.findmapping(i,j);
}

//Shifts the palette by delta
void Mandelbrot::updateColorShift(int delta)
{
    colorshift += delta;
}

void Mandelbrot::updateMaxIterations()
{
    double magnitude = (tr-bl).absval();
    max_iterations = itersize + 100*(-log10(magnitude/4));
    max_iterations = std::max(max_iterations,itersize);
}

void Mandelbrot::setColorMode(int mod)
{
    colors.setMode(mod);
}