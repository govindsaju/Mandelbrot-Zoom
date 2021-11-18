.PHONY : mandelbrot
mandelbrot:
	g++ -O2 -c *.cpp
	g++ -O2 -o mandelbrot *.o -lsfml-graphics -lsfml-window -lsfml-system
	rm *.o

