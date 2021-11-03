#include "colormapper.h"
#include "utils.h"
#include <iostream>
#include <math.h>

//Constructors for ColorRGB and ColorHSV
ColorRGB::ColorRGB()
{
    r = 0;
    g = 0;
    b = 0;
}

ColorRGB::ColorRGB(int _r, int _g, int _b)
{
    r = _r;
    g = _g;
    b = _b;
}

ColorHSV::ColorHSV(double _h, double _s, double _v)
{
    h = _h;
    s = _s;
    v = _v;
}

ColorHSV::ColorHSV()
{
    h = 0;
    s = 1;
    v = 1;
}

//Constructors for color mapper object
ColorMapper::ColorMapper(int _pallete_size) :  palette_size(_pallete_size) , palette(palette_size)
{
    setupPalette();
}

//used to setup pallete by drawing uniformly from the colour cycle
void ColorMapper::setupPalette()
{
    double increment = 360.0/palette_size;
    double hue = 0.0;
    for (int i=0;i<palette_size;i++)
    {
        palette[i] = ConvertToSFML(HSVtoRGB(ColorHSV(hue,0.6,0.7)));
        hue += increment;
    }
}

//converts from RGB to HSV
ColorHSV ColorMapper::RGBtoHSV(ColorRGB c)
{
    double r,g,b;
    r = c.r/255.0;
    g = c.g/255.0;
    b = c.b/255.0;

    double max_col,min_col;
    max_col = std::max(r,std::max(g,b));
    min_col = std::min(r,std::min(g,b));
    double diff = max_col - min_col;

    double h,s,v;
    if (max_col==min_col) 
    {
        h = 0;
    }
    else if (max_col==r)
    {
        h = remainder((60*((g-b)/diff) + 360), 360);
    }
    else if (max_col==g)
    {
        h = remainder((60*((b-r)/diff) + 120), 360);
    }
    else 
    {
        h = remainder((60*((r-g)/diff) + 240), 360);
    }

    if (isEquals(max_col,0))
    {
        s = 0;
    }
    else
    {
        s = diff/max_col;
    }

    v = max_col;

    return ColorHSV(h,s,v);
}

//Converts from HSV to RGB
ColorRGB ColorMapper::HSVtoRGB(ColorHSV c)
{
    double h,s,v,r,g,b;
    h = c.h;
    s = c.s;
    v = c.v;
    if (isEquals(h,360)) h = 0;
    double C = v*s;
    double X = C*(1-fabs((h/60.0) - 2*floor(h/120.0)-1));
    double m = v-C;
    if (h<60)
    {
        r = C;
        g = X;
        b = 0;
    }
    else if (h<120)
    {
        r = X;
        g = C;
        b = 0;
    }
    else if (h<180)
    {
        r = 0;
        g = C;
        b = X;
    }
    else if (h<240)
    {
        r = 0;
        g = X;
        b = C;
    }
    else if (h<300)
    {
        r = X;
        g = 0;
        b = C;
    }
    else 
    {
        r = C;
        g = 0;
        b = X;
    }

    r+=m;
    g+=m;
    b+=m;

    r*=255;
    g*=255;
    b*=255;

    return ColorRGB(static_cast<int>(r),static_cast<int>(g),static_cast<int>(b));

}

//Converts from ColorRGB to SFML object
sf::Color ColorMapper::ConvertToSFML(ColorRGB c)
{
    return sf::Color(c.r,c.g,c.b);
} 