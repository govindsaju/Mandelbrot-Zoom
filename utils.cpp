#include <iostream>
#include <math.h>
using namespace std;
#include "utils.h"

//min of 3 values
template<typename t>
t min(const t &a, const t &b, const t&c)
{
    return min(min(a,b),c);
}

//max of 3 values
template<typename t>
t max(const t &a, const t &b, const t&c)
{
    return max(max(a,b),c);
}

//checks doubles for equality upto a threshold of 1e-6
bool isEquals(const double& a, const double &b)
{
    if (a-b>=0)
    {
        if (a-b < 1e-6) return true;
        else return false;
    }
    else
    {
        if (b - a < 1e-6) return true;
        else return false;
    }
}

bool compareLuminosity(ColorRGB a, ColorRGB b)
{
    double l1 = 0.241* a.r + 0.691*a.g + 0.068 * a.b;
    double l2 = 0.241* b.r + 0.691*b.g + 0.068 * b.b;
    return l1 < l2;
}
