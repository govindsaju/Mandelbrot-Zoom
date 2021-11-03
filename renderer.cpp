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
    bot_left = Complex(-2,-2);
    top_right = Complex(2,2);
    total_zoom_factor = 1;
}

//Creates the window and sets frame limit
void Renderer::initWindow()
{
    videoMode.height = WINDOW_HEIGHT;
    videoMode.width = WINDOW_WIDTH;
    window = new sf::RenderWindow(videoMode,"Mandelbrot Zoom", sf::Style::Titlebar | sf::Style::Close);
    window->setFramerateLimit(20);
}

//Creates the mandelbrot object
void Renderer::initMandelbrot()
{
    mandelbrot = new Mandelbrot(WINDOW_WIDTH,WINDOW_HEIGHT);
}

//Polls for events and stores them in ev
void Renderer::pollEvents()
{
    while (window->pollEvent(ev))
    {
        switch (ev.type)
        {
            case sf::Event::Closed :        //if close button is pressed then close the window
                window->close();
                break;
            default:
                break;
        }
    }
}

//updates the mouse position in mousePos
void Renderer::updateMousePos()
{
    mousePos = sf::Mouse::getPosition(*window);
}

//Function to perform the zoom operation with c as focus and zoomfactor as factor of zoom in each dimension
void Renderer::zoom(Complex c, double zoomfactor = 1.03)
{
    total_zoom_factor *= zoomfactor;
    Complex g1 = top_right - c;
    Complex g2 = c - bot_left;
    g1 = g1 / zoomfactor;
    g2 = g2 / zoomfactor;
    top_right = c + g1;
    bot_left = c - g2;
}

//Gets complex value mapped to point of current mousePos
Complex Renderer::getClickComplex()
{
    return mandelbrot->getComplexVal(mousePos.x,mousePos.y);
}

//updates all params and polls for events
void Renderer::update()
{
    pollEvents();
    updateMousePos();
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) and mouseInWindow())
    {
        zoom(getClickComplex());
    }
    mandelbrot->update(bot_left,top_right);
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