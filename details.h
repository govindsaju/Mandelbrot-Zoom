#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include <string>
#include "complex.h"

class Details{
private:
    sf::Font font;
    sf::RenderWindow* window;
    Complex bl,tr;
    double zoomfactor;
    double totalzoom;
public:
    Details();
    void setZoomFactor(double zm);
    void render();
    void setWindow(sf::RenderWindow* _window);
    void setBounds(Complex _bl, Complex _tr);
    void setTotalZoom(double val);
};
