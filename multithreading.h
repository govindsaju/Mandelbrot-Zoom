#include <thread>
#include "colormapper.h"
#include "complex.h"
#include "coordinatemapper.h"
#include <SFML/Graphics.hpp>
#include <vector>
class RunThread{

sf::Color getColor(Complex c, ColorMapper &colors, int colorshift, int maxiterations);

public:
void operator()(int threadindex, ColorMapper colors, std::vector<sf::Vertex> &pixels, CoordinateMapper cm, int colorshift, int dimx, int dimy, int numthreads, int maxiterations);

};