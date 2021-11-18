#include "details.h"

//Constructor
Details::Details()
{
    if (!font.loadFromFile("DejaVuSerifCondensed.ttf"))
    {
        std::cout<<"Could not load font!\n";
        return;
    }
    window = nullptr;
    zoomfactor = 1;
    nextpos = 2;
    colormode = 1;
}

//sets zoom factor
void Details::setZoomFactor(double zm)
{
    zoomfactor = zm;
}

//sets window pointer
void Details::setWindow(sf::RenderWindow* _window)
{
    window = _window;
}

//sets the bottom left and top right complex value 
void Details::setBounds(Complex _bl, Complex _tr)
{
    bl = _bl;
    tr = _tr;
}

//Sets the total zoom value
void Details::setTotalZoom(double val)
{
    totalzoom = val;
}

//sets the current colormode
void Details::setColorMode(int mode)
{
    colormode = mode;
}

//renders all details on screen
void Details::render()
{
    nextpos = 0;
    renderInstructions();

    int headsiz = 30;
    sf::Text params;
    std::ostringstream ss;
    ss << "PARAMETERS\n";
    setParams(params,headsiz,sf::Color::Red);
    params.setString(ss.str());
    params.setPosition((window->getSize().x - params.getLocalBounds().width)/2,nextpos);
    nextpos += -3 +  params.getLocalBounds().height;
    window->draw(params);
    renderZoom();
    renderBounds();
    renderColorDetails();
}

//renders the current bounds
void Details::renderBounds()
{
    int siz = 20;
    std::ostringstream ss;  
    sf::Text bounds;
    ss << std::fixed << std::setprecision(14);
    ss << "Lower left  \t" << bl.x <<" + "<<bl.y<<"i\n" << "Upper right \t"<<tr.x<<" + "<<tr.y<<"i\n";
    setParams(bounds,siz,sf::Color::Yellow);
    bounds.setString(ss.str());
    bounds.setPosition(10.0,nextpos);
    nextpos += -3 +  bounds.getLocalBounds().height;
    window->draw(bounds);

}

//renders the zoom related information
void Details::renderZoom()
{
    int siz = 20;

    sf::Text zoom_info;
    std::ostringstream ss;
    ss << "Zoomfactor  \t\t "<<zoomfactor<<"\n" << "Total zoom ratio\t "<<totalzoom<<"\n";
    setParams(zoom_info,siz,sf::Color::Yellow);
    zoom_info.setString(ss.str());
    zoom_info.setPosition(10.0,nextpos);
    nextpos += -3 +  zoom_info.getLocalBounds().height;
    window->draw(zoom_info);
}

//renders the color related information
void Details::renderColorDetails()
{
    int siz = 20;
    sf::Text color_info;
    std::ostringstream ss;
    ss << "Colormode \t\t "<<colormode<<"\n";
    setParams(color_info,siz,sf::Color::Yellow);
    color_info.setString(ss.str());
    color_info.setPosition(10.0,nextpos);
    nextpos += -3 +color_info.getLocalBounds().height;
    window->draw(color_info);
}

//renders the instructions
void Details::renderInstructions()
{
    int headsiz = 30;
    sf::Text instructions[2];
    std::ostringstream ss;
    ss << "INSTRUCTIONS \n";
    setParams(instructions[0],headsiz,sf::Color::Red);
    instructions[0].setString(ss.str());
    instructions[0].setPosition((window->getSize().x - instructions[0].getLocalBounds().width)/2,nextpos);
    nextpos += -3 +  instructions[0].getLocalBounds().height;
    ss.str("");

    window->draw(instructions[0]);

    setParams(instructions[1],18,sf::Color::Magenta);
    printInstruction(instructions[1],"Zoom with point as focus","Mouse Click\n");
    printInstruction(instructions[1],"Alter region of display","Press Arrow Keys\n");
    printInstruction(instructions[1],"Toggle autozoom on or off","Press Key  A\n");
    printInstruction(instructions[1],"Increase Zoomfactor","Press Key  + or =\n");
    printInstruction(instructions[1],"Decrease Zoomfactor","Press Key  - or _\n");
    printInstruction(instructions[1],"Save current frame as image","Press Key  S\n");
    printInstruction(instructions[1],"Toggle Mandelbrot and details","Press Key  D or Esc\n");
    printInstruction(instructions[1],"Alter color mode (Algorithm \nof colouring)","Press Keys  1,2,3,4,5,6\n\n");
    printInstruction(instructions[1],"Cyclic shift of color palette","Press Key  I\n");

}

//used to initalise the text object
void Details::setParams(sf::Text &text, int siz, sf::Color col)
{
    text.setFont(font);
    text.setCharacterSize(siz);
    text.setFillColor(col);
}

//used to format the printing of instructions
void Details::printInstruction(sf::Text &text, std::string requirement, std::string action)
{
    int depth = 0;
    text.setString(requirement);
    text.setPosition(10,nextpos);
    text.setFillColor(sf::Color::Magenta);
    depth = text.getLocalBounds().height;
    window->draw(text);
    
    text.setString(action);
    text.setPosition(window->getSize().x/2,nextpos);
    text.setFillColor(sf::Color::Cyan);
    window->draw(text);
    depth = std::max(depth,static_cast<int>(text.getLocalBounds().height));
    nextpos += -9 + depth;

}