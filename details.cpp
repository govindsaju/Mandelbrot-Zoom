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
    nextpos = 2;
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
    nextpos = 0;
    renderInstructions();

    int headsiz = 30;
    sf::Text params;
    std::ostringstream ss;
    ss << "PARAMETERS\n";
    params.setFont(font);
    params.setString(ss.str());
    params.setCharacterSize(headsiz);
    params.setFillColor(sf::Color::Red);
    params.setPosition((window->getSize().x - params.getLocalBounds().width)/2,nextpos);
    nextpos += params.getLocalBounds().height;
    window->draw(params);
    renderZoom();
    renderBounds();
}

void Details::renderBounds()
{
    int siz = 20;
    std::ostringstream ss;  
    sf::Text bounds;
    ss << std::fixed << std::setprecision(14);
    ss << "Lower left  \t" << bl.x <<" + "<<bl.y<<"i\n" << "Upper right \t"<<tr.x<<" + "<<tr.y<<"i\n";
    bounds.setFont(font);
    bounds.setString(ss.str());
    bounds.setCharacterSize(siz);
    bounds.setFillColor(sf::Color::Yellow);
    bounds.setPosition(10.0,nextpos);
    nextpos += bounds.getLocalBounds().height;
    window->draw(bounds);

}

void Details::renderZoom()
{
    int siz = 20;

    sf::Text zoom_info;
    std::ostringstream ss;
    ss << "Zoomfactor  \t\t "<<zoomfactor<<"\n" << "Total zoom ratio\t "<<totalzoom<<"\n";
    zoom_info.setFont(font);
    zoom_info.setString(ss.str());
    zoom_info.setCharacterSize(siz);
    zoom_info.setFillColor(sf::Color::Yellow);
    zoom_info.setPosition(10.0,nextpos);
    nextpos += zoom_info.getLocalBounds().height;
    window->draw(zoom_info);
}

void Details::renderInstructions()
{
    int headsiz = 30;
    sf::Text instructions[2];
    std::ostringstream ss;
    ss << "INSTRUCTIONS \n";
    instructions[0].setFont(font);
    instructions[0].setString(ss.str());
    instructions[0].setCharacterSize(headsiz);
    instructions[0].setFillColor(sf::Color::Red);
    instructions[0].setPosition((window->getSize().x - instructions[0].getLocalBounds().width)/2,nextpos);
    nextpos += instructions[0].getLocalBounds().height;
    ss.str("");

    window->draw(instructions[0]);
    int siz = 18;
    instructions[1].setFont(font);
    ss << "Click with mouse to zoom with that point as focus\n";
    ss << "Click the key A to toggle autozoom on or off\n";
    ss << "Press the + or = key to increase zoomfactor\n";
    ss << "Press the - or _ key to reduce zoomfactor\n";
    ss << "Use the arrow keys to alter region of display\n";
    ss << "Click S key to save current frame as an image\n";
    ss << "Press D key or Esc key to alter between details and mandelbrot\n";    
    ss << "Press I to alter color palette\n";
    instructions[1].setString(ss.str());
    instructions[1].setCharacterSize(siz);
    instructions[1].setFillColor(sf::Color::Magenta);
    instructions[1].setPosition(10,nextpos);
    nextpos += instructions[1].getLocalBounds().height;

    window->draw(instructions[1]);
    

}
