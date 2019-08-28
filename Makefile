all: questions_3

questions_3: image_menu.o ppm_menu.o
		g++ -std=c++11 -o questions_3 image_menu.o ppm_menu.o

image_menu.o : image_menu.cpp image_menu.h
		g++ -std=c++11 -c image_menu.cpp

ppm_menu.o : ppm_menu.cpp image_menu.h
		g++ -std=c++11 -c ppm_menu.cpp

clean: -rm -f image_menu.o ppm_menu.o




# g++ -std=c++11 -c image_menu.cpp
# g++ -std=c++11 -c ppm_menu.cpp
# g++ -o questions_3 -std=c++11 image_menu.o ppm_menu.o

