#include <iostream>
#include <string>
#include "PPM.h"
#include <vector>
using namespace std;



PPM::PPM( )
    :mHeight(0), mWidth(0), mMaxColorValue(0) {
    
    this->mVect.resize(mWidth * mHeight * 3);
    std::cout << "testing" << std::endl;
}

PPM::PPM( const int& height, const int& width )
    :mHeight(height), mWidth(width), mMaxColorValue(0) {

    this->mVect.resize(mWidth * mHeight * 3);
    std::cout << "testing2" << std::endl;
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
        // return (row) * (this->mWidth * 3) + (column) * 3 + channel;
        // std::cout << row << " " << column << " " << channel << std::endl;
        int i = index(row, column, channel);
        return this->mVect[i];
    }
    else {
        // std::cout << row + column + channel << endl;
        return -1;
    }
}



bool PPM::indexValid( const int& row, const int& column, const int& channel ) const {
    // std::cout << mHeight << " H/W " << mWidth << std::endl;
    // row = 3 column = 4 channel = 1
    std::cout << row << " row " << column << " column " << channel << " channel" << std::endl;
    std::cout << this->mHeight << std::endl;

    if ((channel >= 0 && channel <= 2) && (row >= 0 && row < this->mHeight) && (column >= 0 && column < this->mWidth)) {
        return true;
    }
    else {
        // std::cout << row << " " << column << " " << channel << std::endl;
        // std::cout << mHeight << " H/W " << mWidth << std::endl;
        return false;
    }

}

int PPM::index( const int& row, const int& column, const int& channel ) const {
    int in = ((row * this->mWidth + column) * 3 + channel);
    return in;
}

bool PPM::valueValid( const int& value ) const {
    if(value >= 0 && value <= this->mMaxColorValue){
        // std::cout << value << endl;
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
    std::cout << "Size of vector " << this->mVect.size() << std::endl;
    if(indexValid(row, column, channel)) {
        // std::cout << "value " << valueValid(value) << std::endl;
        if(valueValid(value)) {
            std::cout << "does it set channel?" << std::endl;
            int i = index(row, column, channel);
            this->mVect[i] = value;
        }
    }
    std::cout << "does it exit set channel?" << std::endl;
    return;
}

void PPM::setPixel( const int& row, const int& column, const int& red, const int& green, const int& blue ) {
    setChannel(row, column, 0, red);
    setChannel(row, column, 1, green);
    setChannel(row, column, 2, blue);
    return;
}

// std::ostream& operator<<( std::ostream& os, const PPM& rhs ) {
// return os;
// }