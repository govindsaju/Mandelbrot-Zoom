#include "renderer.h"
using namespace std;

Renderer::Renderer()
{
    initVariables();
    initWindow();
}

Renderer::~Renderer()
{
    delete window;
}

void Renderer::initVariables()
{
    window = nullptr;
}

void Renderer::initWindow()
{
    videoMode.height = WINDOW_HEIGHT;
    videoMode.width = WINDOW_WIDTH;
    window = new sf::RenderWindow(videoMode,"Mandelbrot Zoom", sf::Style::Titlebar | sf::Style::Close);
    window->setFramerateLimit(60);
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
}

void Renderer::render()
{

}

bool Renderer::running()
{
    return window->isOpen();
}