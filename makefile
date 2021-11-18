.PHONY : mandelbrot
mandelbrot:
	g++ -g -c *.cpp
	g++ -g -o mandelbrot *.o -lsfml-graphics -lsfml-window -lsfml-system
	rm *.o

