#include <SFML/Graphics.hpp>
#include <vector>
//RGB varies from 0 to 255
struct ColorRGB{
    int r,g,b;
    ColorRGB();
    ColorRGB(int _r, int _g, int _b);
};

//h varies from 0 to 360, s varies from 0 to 1, v varies from 0 to 1
struct ColorHSV{
    double h,s,v;
    ColorHSV();
    ColorHSV(double _h, double _s, double _v);
};

class ColorMapper{

    int palette_size;
    void setupPalette();
public:
    ColorMapper(int _pallete_size);
    std::vector<sf::Color> palette;
    ColorHSV RGBtoHSV(ColorRGB c);
    ColorRGB HSVtoRGB(ColorHSV c);
    sf::Color ConvertToSFML(ColorRGB c);
};