all:
	g++ -std=c++11 -c image_menu.cpp
	g++ -std=c++11 -c ppm_menu.cpp
	g++ -o questions_3 -std=c++11 image_menu.o ppm_menu.o