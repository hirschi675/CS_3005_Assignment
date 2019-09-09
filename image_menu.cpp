#ifndef _IMAGE_MENU_H_
#define _IMAGE_MENU_H_

#include <iostream>
#include <string>
#include <fstream>
#include "PPM.h"
using namespace std;

std::string getString(std::istream& is, std::ostream& os, const std::string& prompt) {
    std::string s;
    os << prompt;
    is >> s;
    return s;
}

#endif /* _IMAGE_MENU_H_ */


int getInteger(std::istream& is, std::ostream& os, const std::string& prompt) {
    int in;
    os << prompt;
    is >> in;
    return in;
}

void writeUserImage( std::istream& is, std::ostream& os, const PPM& p ) {
    std::string outfile = getString(is, os, "Output filename? ");
    std::cout << outfile << std::endl;
    // std::ofstream ofile(outfile, std::ios::binary);
    // fstream myfile;

    std::ofstream ofile(outfile, std::ios::binary);
    ofile << p;
    ofile.close();

    

    // std::ofstream fout( filename, std::ios::binary );
    // std::ifstream fin( filename, std::ios::binary );



    // myfile.open (outfile, ios::in | ios::out | ios::binary); 
    // myfile << p << std::endl;
    // myfile.close();
    return;
}



// int assignment2( std::istream& is, std::ostream& os ); This 
// function will use getInteger to ask the user for the height of an image 
// and again for the width of an image. The questions must be asked in the order 
// demonstrated in the potential session with identical prompts. It will instantiate 
// a PPM object, with the height and width specified by the user. The max color value 
// for this image must be set to ( height + width ) / 3. For every pixel in the image, 
// set red to 0 if the pixel is in the top half of the image, or the maximum color 
// value if the pixel is in the lower half of the image. Set blue to 0 if the pixel is 
// in the left half of the image, or the maximum color value if the pixel is in the right 
// half of the image. Set green to green = ( row + column ) % ( max_color_value + 1 );. 
// That’s a value from 0 to maximum color value, inclusive. Based on the remainder when the 
// sum of row and column is divided by maximum color value plus 1. Finally, save the image to 
// a file named by the user, using writeUserImage. When determining top half vs bottom half or 
// left half vs right half, consider that x/2 results in an integer, when x is an integer. 
// The top half of the image includes all rows who are strictly less than half of the height. 
// The left half of the image includes all columns who are strictly less than half of the width. 
// (Note: if the user gives nonsense values for height, width or filename, the image saved will not make sense, and it’s their fault, not yours.)
//  This function should return 0.

int assignment2( std::istream& is, std::ostream& os ) {
    int h = getInteger(is, os, "Image height? ");
    int w = getInteger(is, os, "Image width? ");
    int max = ((h + w) / 3);
    PPM myPPM(h, w);
    myPPM.setMaxColorValue(max);



    for (int i = 0 ; i < myPPM.getHeight( ) ; i++ ) {
      for (int j = 0 ; j < myPPM.getWidth( ) ; j++ ) {
        for (int c = 0 ; c < 3 ; c++ ) {
            if(i < myPPM.getHeight()/2) {
                myPPM.setChannel(i, j, 0, 0);
            }
            else {
                myPPM.setChannel(i, j, 0, myPPM.getMaxColorValue());
            }
            if(j < myPPM.getWidth()/2) {
                myPPM.setChannel(i, j, 2, 0);
            }
            else {
                myPPM.setChannel(i, j, 2, myPPM.getMaxColorValue());
            }
            myPPM.setChannel(i, j, 1, ((i + j) % (myPPM.getMaxColorValue() + 1)));
        }
      }
    }



    // for (int i = 0; i <= myPPM.getWidth(); i++) {
    //     if(i <= myPPM.getWidth()/3) {
    //         return 1;
    //     }
    // }

    writeUserImage(is, os, myPPM);
    return 0;
}

double getDouble(std::istream& is, std::ostream& os, const std::string& prompt) {
    double d;
    os << prompt;
    is >> d;
    return d;
}

int assignment1(std::istream& is, std::ostream& os) {
    std::string c;
    int t;
    double n;
    int i;
    c = getString(is, os, "What's your favorite color? ");
    t = getInteger(is, os, "What's your favorite integer? ");
    n = getDouble(is, os, "What's your favorite number? ");
    for (i = 0; i < t; i += 1) {
        os << i + 1 << " " << c << " " << n << std::endl;
    }
    return t;
}

