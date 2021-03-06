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
    events.isDetails = false;
    autoZoomFocus = Complex(-0.03358230000162,0.6519894699999);
}

//Creates the window and sets frame limit
void Renderer::initWindow()
{
    videoMode.height = WINDOW_HEIGHT;
    videoMode.width = WINDOW_WIDTH;
    window = new sf::RenderWindow(videoMode,"Mandelbrot Zoom", sf::Style::Titlebar | sf::Style::Close);
    window->setFramerateLimit(20);
    events.setWindow(window);
    events.details.setWindow(window);
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

//checks if given point is inside or not
bool Renderer::pointInside(Complex c)
{
    Complex d1 = events.top_right-c;
    Complex d2 = c-events.bot_left;

    if ((d1.x<0 and d2.x<0 and d1.y<0 and d1.x<0) or (d1.x>0 and d2.x>0 and d1.y>0 and d2.y>0))
        return true;
    else return false;
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
    if (events.isDetails==false)
    {
        if (events.autoZoom==false and sf::Mouse::isButtonPressed(sf::Mouse::Left) and mouseInWindow())
        {
            zoom(getClickComplex());
        }
        else if (events.autoZoom)
        {   
            if (pointInside(autoZoomFocus))
            zoom(autoZoomFocus);
            else
            {
                Complex diag = events.top_right-events.bot_left;
                events.bot_left = autoZoomFocus-diag/2;
                events.top_right = autoZoomFocus +diag/2;
            }
        }
        mandelbrot->update(events.bot_left,events.top_right);
    }
    else
    {
        events.details.setZoomFactor(events.zoomfactor);
        events.details.setBounds(events.bot_left,events.top_right);
        events.details.setTotalZoom(total_zoom_factor);
        events.details.setColorMode(mandelbrot->getColorMode());
    }
}

//renders all changes onto the display window
void Renderer::render()
{
    window->clear();
    if (events.isDetails==false)
    {
        sf::Vertex* pixels= mandelbrot->getPixels();
        window->draw(pixels,WINDOW_HEIGHT*WINDOW_WIDTH,sf::Points);
    }
    else
    {
        events.details.render();
    }
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
