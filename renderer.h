#ifndef __RENDERER__
#define __RENDERER__

#define WINDOW_WIDTH 300
#define WINDOW_HEIGHT 300
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "mandelbrot.h"
#include "complex.h"

class Renderer{
private:
    sf::RenderWindow* window;
    sf::Event ev;
    sf::VideoMode videoMode;
    sf::Vector2i mousePos;
    Complex bot_left, top_right;


    void initVariables();
    void initWindow();
    void pollEvents();
    void initMandelbrot();
    void updateMousePos();
    void zoom(Complex c, double zoomfactor);
    Complex getClickComplex();
    Mandelbrot* mandelbrot;
    bool mouseInWindow();

public:
    double total_zoom_factor;
    Renderer();
    ~Renderer();
    void update();
    void render();
    bool running();

};


#endif 
