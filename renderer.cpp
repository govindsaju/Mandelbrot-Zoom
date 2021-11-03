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

void Renderer::update()
{
    pollEvents();
    mandelbrot->update(Complex(-2,-2),Complex(2,2));
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