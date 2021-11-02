#ifndef __RENDERER__
#define __RENDERER__

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Renderer{
private:
    sf::RenderWindow* window;
    sf::Event ev;
    sf::VideoMode videoMode;

    void initVariables();
    void initWindow();
    void pollEvents();

public:
    Renderer();
    ~Renderer();
    void update();
    void render();
    bool running();

};


#endif 
