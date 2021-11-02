#ifndef __RENDERER__
#define __RENDERER__

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "mandelbrot.h"
class Renderer{
private:
    sf::RenderWindow* window;
    sf::Event ev;
    sf::VideoMode videoMode;

    void initVariables();
    void initWindow();
    void pollEvents();
    void initMandelbrot();

    Mandelbrot* mandelbrot;

public:
    Renderer();
    ~Renderer();
    void update();
    void render();
    bool running();

};


#endif 
