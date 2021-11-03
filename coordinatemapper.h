#ifndef __COORDINATE_MAPPER_H__
#define __COORDINATE_MAPPER_H__

#include "complex.h"
#include <vector>

/**
 * @brief Maps the pixels of the display window to numbers in complex plane 
 */
class CoordinateMapper{
private:
    int dimx,dimy;
public:
    //Stores the mapping of the window coordinates to the complex plane, mapping[i][j] stores
    //complex value at pixel (i,j) 
    std::vector<std::vector<Complex>> mapping;

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
};

#endif