#include "coordinatemapper.h"

//Constructor for coordinate mapper
CoordinateMapper::CoordinateMapper(int _dimx, int _dimy) : mapping(_dimx,std::vector<Complex>(_dimy))
{
    dimx = _dimx;
    dimy = _dimy;
}

//updates mapping based on bottom left and top right of new mapping
void CoordinateMapper::update(Complex bl, Complex tr)
{
    Complex tl(bl.x,tr.y) , br(tr.x,bl.y);
    Complex x_incr = (br-bl)/(dimx-1);
    Complex y_incr = (tr-br)/(dimy-1) * (-1);

    mapping[0][0] = tl;

    for (int i=1;i<dimx;i++)
    {
        mapping[i][0] = mapping[i-1][0] + x_incr;
    }

    for (int i=0;i<dimx;i++)
    {
        for (int j=1;j<dimy;j++)
        {
            mapping[i][j] = mapping[i][j-1] + y_incr;
        }
    }
}