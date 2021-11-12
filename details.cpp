#include "details.h"

Details::Details()
{
    if (!font.loadFromFile("arial.ttf"))
    {
        std::cout<<"Could not load font!\n";
        return;
    }
    window = nullptr;
    zoomfactor = 1;
}

void Details::setZoomFactor(double zm)
{
    zoomfactor = zm;
}

void Details::setWindow(sf::RenderWindow* _window)
{
    window = _window;
}

void Details::render()
{
    sf::Text zoom_info;
    std::ostringstream ss;
    ss << "Zoomfactor is "<<zoomfactor<<"\n";
    zoom_info.setFont(font);
    zoom_info.setString(ss.str());
    zoom_info.setCharacterSize(20);
    zoom_info.setFillColor(sf::Color::Yellow);
    window->draw(zoom_info);
}
