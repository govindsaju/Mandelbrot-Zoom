#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include <string>
#include "complex.h"
#include <iomanip>
class Details{
private:
    sf::Font font;
    sf::RenderWindow* window;
    Complex bl,tr;
    double zoomfactor;
    double totalzoom;
    int nextpos;
    int colormode;

    void renderInstructions();
    void renderZoom();
    void renderBounds();
    void renderColorDetails();
    void setParams(sf::Text &text, int font_size,sf::Color);
    void printInstruction(sf::Text &text, std::string requirement, std::string action);


public:
    Details();
    void setZoomFactor(double zm);
    void render();
    void setWindow(sf::RenderWindow* _window);
    void setBounds(Complex _bl, Complex _tr);
    void setTotalZoom(double val);
    void setColorMode(int mode);
};
