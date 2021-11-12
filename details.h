#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include <string>

class Details{
private:
    sf::Font font;
    sf::RenderWindow* window;
    double zoomfactor;
public:
    Details();
    void setZoomFactor(double zm);
    void render();
    void setWindow(sf::RenderWindow* _window);

};
