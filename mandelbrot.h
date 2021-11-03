#ifndef __MANDELBROT__
#define __MANDELBROT__

#include <SFML/Graphics.hpp>
#include "complex.h"
#include "coordinatemapper.h"
#include "colormapper.h"

class Mandelbrot{
private:
    //Stores the values of bottom left and top right of the current mapping
    Complex bl,tr;      //bl is bottom left, tr is top right
    
    //Object for maintaining mapping
    CoordinateMapper cm;

    //pixel array to be painted on the screen to render mandelbrot
    sf::Vertex* pixels;

    //dimensions of the window
    int dimx,dimy;

    //object to store a color palette, used to assign colours to complex numbers depending on speed of convergence
    ColorMapper colors;

    //colorshift refers to the cyclic rotation that is applied to the palette
    int colorshift;

public:
    /**
     * @brief Construct a new Mandelbrot object
     * 
     * @param dimx length of x dimension of the window
     * @param dimy length of y dimension of the window
     */
    Mandelbrot(int dimx,int dimy);

    /**
     * @brief Destroy the Mandelbrot object
     */
    ~Mandelbrot();

    /**
     * @brief Does the mathematics and returns the color of a complex number using its speed of convergence and the colorpalette
     * 
     * @param c Complex number that needs to be coloured
     * @return sf::Color An sfml color object
     */
    sf::Color getColor(Complex c);

    /**
     * @brief Updates the pixel array by adding objects based on the new mapping after finding their colors
     * 
     * @param bl Complex number which is the bottom left in the new mapping to be updated
     * @param ur Complex number which is in the top right in the new mapping to be updated
     */
    void update(const Complex &_bl,const Complex &_ur);

    /**
     * @brief Get the array of pixels to paint the entire display window
     * 
     * @return sf::Vertex* 
     */
    sf::Vertex* getPixels();

    /**
     * @brief Get the complex number mapped to the pixel coordinate (xcoord,ycoord)
     * 
     * @param xcoord X coordinate in the window frame
     * @param ycoord Y coordinate in the window frame
     * @return Complex number which is mapped to (xcoord,ycoord)
     */
    Complex getComplexVal(int xcoord, int ycoord);

    /**
     * @brief Increases the colorshift by delta
     * 
     * @param delta value by which colorshift is increased
     */
    void updateColorShift(int delta=10);
};

#endif 
