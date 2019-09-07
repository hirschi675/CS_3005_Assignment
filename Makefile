all: ppm_image

ppm_image: image_menu.o ppm_menu.o PPM.o
		g++ -std=c++11 -o ppm_image image_menu.o ppm_menu.o PPM.o

image_menu.o : image_menu.cpp image_menu.h
		g++ -std=c++11 -c image_menu.cpp

ppm_menu.o : ppm_menu.cpp image_menu.h
		g++ -std=c++11 -c ppm_menu.cpp

PPM.o : PPM.cpp PPM.h
    g++ -std=c++11 -c PPM.cpp

clean: -rm -f image_menu.o ppm_menu.o PPM.o
