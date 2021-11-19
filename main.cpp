#include <iostream>
#include <SFML/Graphics.hpp>
#include <chrono>
#include <thread>
#include "renderer.h"
using namespace std;

int main()
{
    Renderer renderer;  //Renderer object to display the mandelbrot zoom

    this_thread::sleep_for(chrono::seconds(3));
    auto start = chrono::system_clock::now();   //time counter to measure FPS
    double counter = 0;                       //Frame counter

    while (renderer.running())
    {
        counter+=1;
        renderer.update();
        renderer.render();
    }
    auto end = chrono::system_clock::now();     //time of completion
    auto time = std::chrono::duration_cast<std::chrono::seconds>(end-start);    //time elapsed

    cout<<"Total FPS :"<<counter/time.count()<<"\n";  
}