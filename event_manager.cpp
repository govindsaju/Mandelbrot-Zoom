#include "event_manager.h"
#include <chrono>
#include <ctime>
#include <sstream>
#include <string>
#include <iomanip>

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
            std::cout<<"Zoom factor is now "<<zoomfactor<<std::endl;
            break;
        
        case sf::Keyboard::Subtract :
        case sf::Keyboard::Dash :
            zoomfactor -= 0.03;
            std::cout<<"Zoom factor is now "<<zoomfactor<<std::endl;
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

        case sf::Keyboard::S :
            saveFig();

    }
}

void EventManager::saveFig()
{
    auto currtime = std::chrono::system_clock::now();
    auto in_time_t_format = std::chrono::system_clock::to_time_t(currtime);
    std::stringstream ss;
    ss << std::put_time(std::localtime(&in_time_t_format),"%Y-%m-%d %X");
    std::string filename = ss.str();
    std::string s="mandelbrot-";
    for (auto c:filename)
    {   
        if (c==' ') s+='-';
        else if (c!=':') s+=c;
        else s+='-';
    }
    filename = s + ".png";
    sf::Texture texture;
    texture.create(window->getSize().x,window->getSize().y);
    texture.update(*window);
    if (texture.copyToImage().saveToFile(filename))
    {
        std::cout<<"File saved to "<<filename<<std::endl;
    }
}