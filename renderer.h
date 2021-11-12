/**
 * @file renderer.h
 * @brief Definition of class Renderer
 * 
 */

#ifndef __RENDERER__
#define __RENDERER__

#define WINDOW_WIDTH 560
#define WINDOW_HEIGHT 560
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "mandelbrot.h"
#include "complex.h"
#include "event_manager.h"

/**
 * @brief A wrapper class to interact with SFML and control aspects of the GUI.
 * @details Renderer is the class that handles the display and interacts with the user.
 * It handles mouseclicks, zooming etc. 
 */
class Renderer{
private:

    //Pointer to window that shows the output
    sf::RenderWindow* window;


    //VideoMode in SFML, sets the dimensions of the window, the options available in the titlebar etc
    sf::VideoMode videoMode;

    //Stores the current mouse position
    sf::Vector2i mousePos;

    //Event manager to log all events and take appropriate actions
    EventManager events;

    Complex autoZoomFocus;
    /**
     * @brief Initialises the variables of the class.
     */
    void initVariables();

    /**
     * @brief Sets up the window of the class .
     */
    void initWindow();



    /**
     * @brief Sets up the mandelbrot object initially. 
     */
    void initMandelbrot();

    /**
     * @brief Constantly updates the mouse position relative to the window
     */
    void updateMousePos();

    /**
     * @brief A function to perform the zoom operation on the mandelbrot set, factor for zooming obtained from event manager
     * 
     * @param Complex c is the focus at which the zoom operation is performed
     */
    void zoom(Complex c);

    /**
     * @brief Get the complex number currently mapped to the current mouse position
     * 
     * @return Complex value which is mapped to current mouse position
     */
    Complex getClickComplex();

    //Pointer to mandelbrot object which handles rendering of the mandelbrot
    Mandelbrot* mandelbrot;

    /**
     * @brief Function to check if the mouse is inside the window or not
     * 
     * @return true If mouse is in the window currently
     * @return false If mouse is not in the window currently
     */
    bool mouseInWindow();

public:
    
    //stores the value of the total zoom that has been done since the rendering started
    double total_zoom_factor;

    /**
     * @brief Construct a new Renderer object
     */
    Renderer();

    /**
     * @brief Destroy the Renderer object along with the window and manelbrot objects
     */
    ~Renderer();

    /**
     * @brief Updates the parameters in for the current frame (Does not render yet)
     */
    void update();

    /**
     * @brief Renders all updated parameters to the display window
     */
    void render();

    /**
     * @brief Checks whether window is open or not
     * 
     * @return true If window is open
     * @return false If window is closed
     */
    bool running();

};


#endif 
