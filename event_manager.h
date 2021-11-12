/**
 * @file event_manager.h
 * @brief File for defining EventManager class
 */
#ifndef __EVENT_MANAGER__
#define __EVENT_MANAGER__

#include "details.h"
#include <SFML/Graphics.hpp>
#include "complex.h"
#include "mandelbrot.h"

/**
 * @brief A class to manage all events arising due to user action
 */
class EventManager{
private:
    
    //pointer to window
    sf::RenderWindow *window;

    //pointer to mandelbrot object
    Mandelbrot *mandelbrot;

    //Event in SFML, detects events such as closing the window 
    sf::Event ev;

public:
    //bot_left corresponds to the complex number currently at the bottom left,
    //top_right has the complex number at the top right of the grid 
    Complex bot_left, top_right;

    //Factor by which zoom is being performed
    double zoomfactor;

    Details details;
    bool isDetails;
    /**
     * @brief Construct a new Event Manager object
     */
    EventManager();

    /**
     * @brief Set the window pointer
     * 
     * @param _window Pointer to window being rendered
     */
    void setWindow(sf::RenderWindow *_window);

    /**
     * @brief Set the Mandelbrot pointer
     * 
     * @param _mandelbrot Pointer to mandelbrot object
     */
    void setMandelbrot(Mandelbrot *_mandelbrot);

    /**
     * @brief Function to resolve actions based on which key was pressed
     */
    void solveKeyStrokes();

    /**
     * @brief Polls the events happening on the window as a result of user action and stores them in variable ev. 
     */
    void pollEvents();

    /**
     * @brief Function to save current screen as a file. Filename generated automatically 
     */
    void saveFig();

};

#endif 
