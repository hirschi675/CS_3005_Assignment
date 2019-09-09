#include <iostream>
#include <string>
#include "PPM.h"
#include <vector>
using namespace std;

// STILL RECIEVES A FAULT ERROR
// WHERE ARE YOU ACCESSING MEMEORY THAT YOU CAN'T?

PPM::PPM( )
    :mHeight(0), mWidth(0), mMaxColorValue(0) {
    
    this->mVect.resize(mWidth * mHeight * 3);
}

PPM::PPM( const int& height, const int& width )
    :mHeight(height), mWidth(width), mMaxColorValue(0) {

    this->mVect.resize(mWidth * mHeight * 3);
}

int PPM::getHeight( ) const {
    return this->mHeight;
}

int PPM::getWidth( ) const {
    return this->mWidth;
}

int PPM::getMaxColorValue( ) const {
    return this->mMaxColorValue;
}

int PPM::getChannel( const int& row, const int& column, const int& channel ) const {
    if (channel >= 0 && channel <= 2 && row >= 0 && row < mHeight && column >= 0 && column < mWidth) {
        int i = index(row, column, channel);
        return this->mVect[i];
    }
    else {
        std::cout << "Wrong" << endl;
        return -1;
    }
}



bool PPM::indexValid( const int& row, const int& column, const int& channel ) const {

    if ((channel >= 0 && channel <= 2) && (row >= 0 && row < this->mHeight) && (column >= 0 && column < this->mWidth)) {
        return true;
    }
    else {
        return false;
    }

}

int PPM::index( const int& row, const int& column, const int& channel ) const {
    int in = ((row * this->mWidth * 3 + column * 3) + channel);
    return in;
}

bool PPM::valueValid( const int& value ) const {
    if(value >= 0 && value <= this->mMaxColorValue){
        return true;
    }
    else {
        return false;
    }
}

void PPM::setHeight( const int& height ) {
    if(height > 0 && height != this->mHeight) {
        this->mHeight = height;
        this->mVect.resize( 3 * this->mWidth * this->mHeight );
    }
    return;
}

void PPM::setWidth( const int& width ) {
    if(width > 0 && width != this->mWidth) {
        this->mWidth = width;
        this->mVect.resize( 3 * this->mWidth * this->mHeight );
    }
    return;

}

void PPM::setMaxColorValue( const int& max_color_value ) {
    if(max_color_value < 256 && max_color_value >= 0) {
        this->mMaxColorValue = max_color_value;
    }
    return;
}

void PPM::setChannel( const int& row, const int& column, const int& channel, const int& value ) {
    if(indexValid(row, column, channel)) {
        if(valueValid(value)) {
            int i = index(row, column, channel);
            this->mVect[i] = value;
        }
    }
    return;
}

void PPM::setPixel( const int& row, const int& column, const int& red, const int& green, const int& blue ) {
    setChannel(row, column, 0, red);
    setChannel(row, column, 1, green);
    setChannel(row, column, 2, blue);
    return;
}


std::ostream& operator<<( std::ostream& os, const PPM& rhs ) {
    unsigned char b;
    os << "P6 " << rhs.getWidth() << " " << rhs.getHeight() << " " << rhs.getMaxColorValue() <<  std::endl;
     for (int i = 0 ; i < rhs.getHeight( ) ; i++ ) {
      for (int j = 0 ; j < rhs.getWidth( ) ; j++ ) {
        for (int c = 0 ; c < 3 ; c++ ) {
            int value = rhs.getChannel(i, j ,c);
            b = (unsigned char)value;
            os.write((char*) &b, 1);
        }
      }
     }
    return os;
}
