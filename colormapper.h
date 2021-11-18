/**
 * @file colormapper.h
 * @brief File for defining class ColorMapper, and helper structs ColorRGB and ColorHSV
 */
#ifndef __COLOR_MAPPER__
#define __COLOR_MAPPER__

#include <SFML/Graphics.hpp>
#include <vector>
#include <tuple>
#include <queue>
#include <functional>

/**
 * @brief Struct to store color of form r,g,b 
 */
struct ColorRGB{
    int r,g,b;  //RGB varies from 0 to 255
    ColorRGB();
    ColorRGB(int _r, int _g, int _b);   //values of color in RGB format
};

/**
 * @brief struct to store color of form h,s,v
 */
struct ColorHSV{
    double h,s,v;   //h varies from 0 to 360, s varies from 0 to 1, v varies from 0 to 1
    ColorHSV();
    ColorHSV(double _h, double _s, double _v);  //values of color in HSV format
};

/**
 * @brief Class to act as a wrapper to provide access to a cyclic pallete of colours 
 */
class ColorMapper{

    //size of pallete
    int palette_size;

    //Defines which algorithm is used for colouring (Varies from 1 to 6)
    int mode;


public:

    
    //The pallete of colours
    std::vector<sf::Color> palette;

    /**
     * @brief Construct a new Color Mapper object
     * @param _pallete_size size of pallete required
     */
    ColorMapper(int _pallete_size, int _mode = 1);

    /**
     * @brief Sets up the pallete with colour objects from SFML and uses the algorithm defined the current mode 
     */
    void setupPalette();

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

    /**
     * @brief Used to update the size of the palette
     * @param siz the new size of palette  
     */
    void updateSize(int siz);

    /**
     * @brief Set the value of mode, which decides which colouring algorithm to use
     * @param mod The value which mode is to be set to
     */
    void setMode(int mod);

    /**
     * @brief Algorithm for mode 1
     * @details Deterministic algorithm, Generates a sorted palette with uniformly distributed Hue values, with S=V=1
     * Contains very bright colors
     */
    void CyclicHSVSetup();

    /**
     * @brief Algorithm for mode 2
     * @details Deterministic algorithm, Generates a photographic negative of sorted palette 
     * with uniformly distributed Hue values, has smaller S and V values 
     */
    void CyclicHSVNegativeSetup();

    /**
     * @brief Algorithm for mode 3
     * @details Randomised algorithm, generates colors randomly with HSV values, performs a heap sort in ascending order
     * on them giving priority to H values, followed by S values followed by V values
     */
    void HSVHeapSortAscendingSetup();

    /**
     * @brief Algorithm for mode 4
     * @details Randomised algorithm, generates colors randomly with HSV values, performs a heap sort in descending order
     * on them giving priority to H values, followed by S values followed by V values
     */
    void HSVHeapSortDescendingSetup();

    /**
     * @brief Algorithm for mode 5
     * @details Randomised algorithm, generates colors randomly with RGB values, performs a heap sort in Ascending
     * order based on luminosity of the colours
     */
    void LuminosityAscendingSetup();

    /**
     * @brief Algorithm for mode 6
     * @details Randomised algorithm, generates colors randomly with RGB values, performs a heap sort in Descending
     * order based on luminosity of the colours
     */
    void LuminosityDescendingSetup();
};

#endif 