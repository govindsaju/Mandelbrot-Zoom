#include <iostream>
#include <SFML/Graphics.hpp>
#include "renderer.h"
using namespace std;

int main()
{
    Renderer renderer;
    while (renderer.running())
    {
        renderer.update();
        renderer.render();
    }
}