#include <iostream>
#include <SFML/Graphics.hpp>
#include "renderer.h"
using namespace std;

#include <chrono>

int main()
{
    Renderer renderer;

    auto start = chrono::system_clock::now();
    int counter = 0;
    while (renderer.running())
    {
        counter++;
        renderer.update();
        renderer.render();
    }
    auto end = chrono::system_clock::now();
    auto time = std::chrono::duration_cast<std::chrono::seconds>(end-start);

    cout<<"FPS :"<<counter/time.count()<<"\n";
}