#include <iostream>
#include <math.h>
using namespace std;
#include "utils.h"

template<typename t>
t min(const t &a, const t &b, const t&c)
{
    return min(min(a,b),c);
}


template<typename t>
t max(const t &a, const t &b, const t&c)
{
    return max(max(a,b),c);
}


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
