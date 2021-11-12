#include "event_manager.h"
#include <chrono>
#include <ctime>
#include <sstream>
#include <string>
#include <iomanip>

//Constructor for event manager
EventManager::EventManager()
{
    window = nullptr;
    bot_left = Complex(-2,-2);
    top_right = Complex(2,2);
    zoomfactor = 1.05;
    isDetails=false;
}

//sets window object
void EventManager::setWindow(sf::RenderWindow *_window)
{
    window = _window;
}

//sets mandelbrot object
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

//resolves keystrokes and takes action
void EventManager::solveKeyStrokes()
{
    Complex shift;      //to model shift in coordinates if arrow keys are pressed
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
        case sf::Keyboard::Dash :
            zoomfactor -= 0.03;
            break;

        //Shift is in units of 1/10th window dimension
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
            break;

        case sf::Keyboard::D :
            isDetails = !isDetails;
            break;

    }
}

void EventManager::saveFig()
{   
    //this part is to get the filename from system time
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

    //this part is to save the image
    texture.create(window->getSize().x,window->getSize().y);
    texture.update(*window);
    if (texture.copyToImage().saveToFile(filename))
    {
        std::cout<<"File saved to "<<filename<<std::endl;
    }
}
