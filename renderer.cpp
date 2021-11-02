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
}

void Renderer::initWindow()
{
    videoMode.height = WINDOW_HEIGHT;
    videoMode.width = WINDOW_WIDTH;
    window = new sf::RenderWindow(videoMode,"Mandelbrot Zoom", sf::Style::Titlebar | sf::Style::Close);
    window->setFramerateLimit(60);
}

void Renderer::initMandelbrot()
{
    mandelbrot = new Mandelbrot(window,WINDOW_WIDTH,WINDOW_HEIGHT);
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

void Renderer::update()
{
    pollEvents();
    mandelbrot->update(Complex(0.0,0.0),Complex(10.0,10.0));
}

void Renderer::render()
{
    window->clear();
    mandelbrot->render();
    window->display();
}

bool Renderer::running()
{
    return window->isOpen();
}