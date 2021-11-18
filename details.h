/**
 * @file details.h
 * @brief File for containing details class, to show data to to the user
 */

#ifndef __DETAILS_H__
#define __DETAILS_H__

#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include <string>
#include "complex.h"
#include <iomanip>

/**
 * @brief Class for defining details to be shown to the user
 */
class Details{
private:
    //Font used for writing all text
    sf::Font font;

    //Pointer to window to print the info
    sf::RenderWindow* window;

    //Values of the bottom left and top right of current mapping
    Complex bl,tr;

    //Current zoomfactor
    double zoomfactor;

    //Total zoom until now
    double totalzoom;

    //Value telling next available y coordinate to print information
    int nextpos;

    //Stores color mode, i.e. index of algorithm being used to render information
    int colormode;

    /**
     * @brief Renders the instructions on screen
     */
    void renderInstructions();

    /**
     * @brief Renders data regarding the zoom parameters 
     */
    void renderZoom();

    /**
     * @brief Renders data regarding the bounds of the current mapping 
     */
    void renderBounds();

    /**
     * @brief Renders data regarding the current color mapping 
     */
    void renderColorDetails();

    /**
     * @brief Initialises the text object with the font, font size and color 
     * @param text object
     * @param font_size 
     * @param Color c 
     */
    void setParams(sf::Text &text, int font_size,sf::Color c);

    /**
     * @brief Used for formatting the printing of instructions 
     * @param text Text object initialised with parameters
     * @param requirement The requirement expected when action is done
     * @param action The key which is to be pressed for the requirement to be satisfied
     */
    void printInstruction(sf::Text &text, std::string requirement, std::string action);


public:

    /**
     * @brief Construct a new Details object
     */
    Details();

    /**
     * @brief Sets the value of zoom factor
     * @param zm zoomfactor
     */
    void setZoomFactor(double zm);

    /**
     * @brief Sets the Window object
     * @param _window 
     */
    void setWindow(sf::RenderWindow* _window);

    /**
     * @brief Sets the bounds of current mapping
     * @param _bl bottom left
     * @param _tr top right
     */
    void setBounds(Complex _bl, Complex _tr);

    /**
     * @brief Sets the value of total zoom
     * @param val 
     */
    void setTotalZoom(double val);

    /**
     * @brief Sets the value of current color mode 
     * @param mode 
     */
    void setColorMode(int mode);

    /**
     * @brief Renders all instructions and parameters on screen
     */
    void render();
};


#endif 