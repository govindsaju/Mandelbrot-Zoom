#include "coordinatemapper.h"

//Constructor for coordinate mapper
CoordinateMapper::CoordinateMapper(int _dimx, int _dimy)
{
    dimx = _dimx;
    dimy = _dimy;
}

//updates mapping based on bottom left and top right of new mapping
void CoordinateMapper::update(Complex _bl, Complex _tr)
{
    bl = _bl;
    tr = _tr;
    tl = Complex(bl.x,tr.y) ;
    br = Complex(tr.x,bl.y);
    x_incr = (br-bl)/(dimx-1);
    y_incr = (tr-br)/(dimy-1) * (-1);

}

Complex CoordinateMapper::findmapping(int i, int j)
{
    //return tl + i*x_incr + j*y_incr;
    return Complex(tl.x+i*x_incr.x + j*y_incr.x,tl.y+i*x_incr.y+j*y_incr.y);
}