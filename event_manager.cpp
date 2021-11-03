#include "event_manager.h"

EventManager::EventManager()
{
    window = nullptr;
    bot_left = Complex(-2,-2);
    top_right = Complex(2,2);
    zoomfactor = 1.05;
}

void EventManager::setWindow(sf::RenderWindow *_window)
{
    window = _window;
}

void EventManager::setMandelbrot(Mandelbrot *_mandelbrot)
{
    mandelbrot = _mandelbrot;
}

//Polls for events and stores them in ev
void EventManager::pollEvents()
{
    while (window->pollEvent(ev))
    {
        switch (ev.type)
        {
            case sf::Event::Closed :        //if close button is pressed then close the window
                window->close();
                break;
            case sf::Event::KeyPressed :
                solveKeyStrokes();
                break;
            default:
                break;
        }
    }
}

void EventManager::solveKeyStrokes()
{
    Complex shift;
    switch (ev.key.code)
    {
        case sf::Keyboard::I :
            mandelbrot->updateColorShift();
            break;
        
        case  sf::Keyboard::Equal :
        case sf::Keyboard::Add :
            zoomfactor += 0.03;
            break;
        
        case sf::Keyboard::Subtract :
        case sf::Keyboard::Hyphen :
            zoomfactor -= 0.03;
            break;

        case sf::Keyboard::Left :
            shift = Complex(top_right.x-bot_left.x,0) / 10;
            top_right = top_right - shift;
            bot_left = bot_left - shift;
            break;
        
        case sf::Keyboard::Right :
            shift = Complex(top_right.x-bot_left.x,0) / 10;
            top_right = top_right + shift;
            bot_left = bot_left + shift;
            break;
        
        case sf::Keyboard::Up :
            shift = Complex(0,top_right.y-bot_left.y) / 10;
            top_right = top_right + shift;
            bot_left = bot_left + shift;
            break;
        
        case sf::Keyboard::Down :
            shift = Complex(0,top_right.y-bot_left.y) / 10;
            top_right = top_right - shift;
            bot_left = bot_left - shift;
            break;

    }
}