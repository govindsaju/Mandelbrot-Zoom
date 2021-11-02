#ifndef __COORDINATE_MAPPER_H__
#define __COORDINATE_MAPPER_H__

#include "complex.h"
#include <vector>

class CoordinateMapper{
private:
    int dimx,dimy;
public:
    std::vector<std::vector<Complex>> mapping;
    CoordinateMapper(int dimx, int dimy);
    void update(Complex bl, Complex tr);
};

#endif