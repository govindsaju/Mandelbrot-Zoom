/**
 * @file colormapper.h
 * @brief File for defining structs ColorRGB and ColorHSV, also defines class ColorMapper
 */
#ifndef __COLOR_MAPPER__
#define __COLOR_MAPPER__

#include <SFML/Graphics.hpp>
#include <vector>

/**
 * @brief Struct to store color of form r,g,b 
 */
struct ColorRGB{
    int r,g,b;  //RGB varies from 0 to 255
    ColorRGB();
    ColorRGB(int _r, int _g, int _b);
};

/**
 * @brief struct to store color of form h,s,v
 */
struct ColorHSV{
    double h,s,v;   //h varies from 0 to 360, s varies from 0 to 1, v varies from 0 to 1
    ColorHSV();
    ColorHSV(double _h, double _s, double _v);
};

/**
 * @brief Class to act as a wrapper to provide access to a cyclic pallete of colours 
 */
class ColorMapper{

    //size of pallete
    int palette_size;

    /**
     * @brief Sets up the pallete with colour objects from SFML 
     */
    void setupPalette();
public:
    /**
     * @brief Construct a new Color Mapper object
     * @param _pallete_size size of pallete required
     */
    ColorMapper(int _pallete_size);

    //The pallete of colours
    std::vector<sf::Color> palette;

    /**
     * @brief Converts from RGB to HSV
     * 
     * @param ColorRGB c
     * @return ColorHSV 
     */
    ColorHSV RGBtoHSV(ColorRGB c);

    /**
     * @brief Converts from HSV to RGB
     * 
     * @param ColorHSV c 
     * @return ColorRGB 
     */
    ColorRGB HSVtoRGB(ColorHSV c);

    /**
     * @brief Converts from ColorRGB objects to SFML colour objects
     * 
     * @param ColorRGB c
     * @return sf::Color 
     */
    sf::Color ConvertToSFML(ColorRGB c);
};

#endif 