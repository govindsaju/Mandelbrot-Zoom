#include "renderer.h"
using namespace std;

Renderer::Renderer() 
{
    initVariables();
    initWindow();
    initMandelbrot();
}

Renderer::~Renderer()
{
    delete window;
    delete mandelbrot;
}

void Renderer::initVariables()
{
    window = nullptr;
    mandelbrot = nullptr;
    bot_left = Complex(-2,-2);
    top_right = Complex(2,2);
    total_zoom_factor = 1;
}

void Renderer::initWindow()
{
    videoMode.height = WINDOW_HEIGHT;
    videoMode.width = WINDOW_WIDTH;
    window = new sf::RenderWindow(videoMode,"Mandelbrot Zoom", sf::Style::Titlebar | sf::Style::Close);
    window->setFramerateLimit(20);
}

void Renderer::initMandelbrot()
{
    mandelbrot = new Mandelbrot(WINDOW_WIDTH,WINDOW_HEIGHT);
}

void Renderer::pollEvents()
{
    while (window->pollEvent(ev))
    {
        switch (ev.type)
        {
            case sf::Event::Closed :
                window->close();
                break;
            default:
                break;
        }
    }
}

void Renderer::updateMousePos()
{
    mousePos = sf::Mouse::getPosition(*window);
}


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

Complex Renderer::getClickComplex()
{
    return mandelbrot->getComplexVal(mousePos.x,mousePos.y);
}

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

void Renderer::render()
{
    window->clear();
    sf::Vertex* pixels= mandelbrot->getPixels();
    window->draw(pixels,WINDOW_HEIGHT*WINDOW_WIDTH,sf::Points);
    window->display();
}

bool Renderer::running()
{
    return window->isOpen();
}

bool Renderer::mouseInWindow()
{
    if (mousePos.x>0 and mousePos.x < WINDOW_WIDTH and mousePos.y>0 and mousePos.y < WINDOW_HEIGHT) 
        return true;
    return false;
}