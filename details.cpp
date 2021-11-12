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

void Details::setBounds(Complex _bl, Complex _tr)
{
    bl = _bl;
    tr = _tr;
}

void Details::setTotalZoom(double val)
{
    totalzoom = val;
}
void Details::render()
{
    sf::Text zoom_info;
    std::ostringstream ss;
    ss << "Zoomfactor is "<<zoomfactor<<"\n" << "Total zoom ratio is "<<totalzoom<<"\n";
    zoom_info.setFont(font);
    zoom_info.setString(ss.str());
    zoom_info.setCharacterSize(20);
    zoom_info.setFillColor(sf::Color::Yellow);

    sf::Text bounds;
    ss.flush();
    ss << "Lower left is " << bl.x <<" + "<<bl.y<<"i \n" << "Top right is "<<tr.x<<" + "<<tr.y<<"\n";
    bounds.setFont(font);
    bounds.setString(ss.str());
    bounds.setCharacterSize(20);
    bounds.setFillColor(sf::Color::Yellow);
    window->draw(zoom_info);
    window->draw(bounds);
}
