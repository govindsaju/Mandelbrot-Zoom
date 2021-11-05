#include "renderer.h"
using namespace std;

//Constructor for renderer
Renderer::Renderer() 
{
    initVariables();
    initWindow();
    initMandelbrot();
}


//Destructor for renderer
Renderer::~Renderer()
{
    delete window;
    delete mandelbrot;
}


//Initialises variables of renderer
void Renderer::initVariables()
{
    window = nullptr;
    mandelbrot = nullptr;
    total_zoom_factor = 1;
}

//Creates the window and sets frame limit
void Renderer::initWindow()
{
    videoMode.height = WINDOW_HEIGHT;
    videoMode.width = WINDOW_WIDTH;
    window = new sf::RenderWindow(videoMode,"Mandelbrot Zoom", sf::Style::Titlebar | sf::Style::Close);
    window->setFramerateLimit(20);
    events.setWindow(window);
}

//Creates the mandelbrot object
void Renderer::initMandelbrot()
{
    mandelbrot = new Mandelbrot(WINDOW_WIDTH,WINDOW_HEIGHT);
    events.setMandelbrot(mandelbrot);
}


//updates the mouse position in mousePos
void Renderer::updateMousePos()
{
    mousePos = sf::Mouse::getPosition(*window);
}

//Function to perform the zoom operation with c as focus and zoomfactor as factor of zoom in each dimension
void Renderer::zoom(Complex c)
{
    double zoomfactor = events.zoomfactor;
    total_zoom_factor *= zoomfactor;
    Complex g1 = events.top_right - c;
    Complex g2 = c - events.bot_left;
    g1 = g1 / zoomfactor;
    g2 = g2 / zoomfactor;
    events.top_right = c + g1;
    events.bot_left = c - g2;
}

//Gets complex value mapped to point of current mousePos
Complex Renderer::getClickComplex()
{
    return mandelbrot->getComplexVal(mousePos.x,mousePos.y);
}

//updates all params and polls for events
void Renderer::update()
{
    events.pollEvents();
    updateMousePos();
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) and mouseInWindow())
    {
        zoom(getClickComplex());
    }
    //mandelbrot->update_multithreaded(events.bot_left,events.top_right);
    mandelbrot->update(events.bot_left,events.top_right);
}

//renders all changes onto the display window
void Renderer::render()
{
    window->clear();
    sf::Vertex* pixels= mandelbrot->getPixels();
    window->draw(pixels,WINDOW_HEIGHT*WINDOW_WIDTH,sf::Points);
    window->display();
}

//checks if display window is open or not
bool Renderer::running()
{
    return window->isOpen();
}

//checks if mouse is in the window or not
bool Renderer::mouseInWindow()
{
    if (mousePos.x>0 and mousePos.x < WINDOW_WIDTH and mousePos.y>0 and mousePos.y < WINDOW_HEIGHT) 
        return true;
    return false;
}