#include <SFML/Graphics.hpp>
#include "complex.h"
#include "mandelbrot.h"

class EventManager{
private:
    sf::RenderWindow *window;
    Mandelbrot *mandelbrot;

    //Event in SFML, detects events such as closing the window 
    sf::Event ev;

public:
    //bot_left corresponds to the complex number currently at the bottom left,
    //top_right has the complex number at the top right of the grid 
    Complex bot_left, top_right;
    double zoomfactor;
    EventManager();
    void setWindow(sf::RenderWindow *_window);
    void setMandelbrot(Mandelbrot *_mandelbrot);
    void solveKeyStrokes();
    /**
     * @brief Polls the events happening on the window as a result of user action and stores then in variable ev. 
     */
    void pollEvents();

};