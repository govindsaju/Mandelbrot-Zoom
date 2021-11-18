/**
 * @file coordinatemapper.h
 * @brief File for defining CoordinateMapper class
 */

#ifndef __COORDINATE_MAPPER_H__
#define __COORDINATE_MAPPER_H__

#include "complex.h"
#include <vector>

/**
 * @brief Maps the pixels of the display window to numbers in complex plane 
 */
class CoordinateMapper{
private:
    //the dimensions of the window
    int dimx,dimy;

    //the values mapped to top left, bottom right, bottom left and top right
    Complex tl,br,bl,tr;

    //Values of increment along x axis and y axis on moving 1 pixel
    Complex x_incr,y_incr;
public:

    /**
     * @brief Construct a new Coordinate Mapper object with given dimensions of the window
     * 
     * @param dimx length of window in x axis
     * @param dimy length of window in y axis
     */
    CoordinateMapper(int dimx, int dimy);

    /**
     * @brief Updates the values of the mapping based on the new params given
     * @param bl bl stands for bottom left. It is the complex number to be used in the bottom left of the window.
     * @param tr tr stands for top right. It is the complex number to be used in the top right of the window.
     */
    void update(Complex bl, Complex tr);

    /**
     * @brief Finds the complex value mapped to the coordinate in the window coordinate frame
     * @param i X axis coordinate in window frame
     * @param j Y axis coordinate in window frame
     * @return Complex value mapped to point (i,j)
     */
    Complex findmapping(int i, int j);
};

#endif