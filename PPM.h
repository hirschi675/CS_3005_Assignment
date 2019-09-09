
#ifndef _PPM_H_
#define _PPM_H_

#include <iostream>
#include <string>
#include <vector>
using namespace std;




class PPM {
    public:
        PPM( );
        PPM(const int& height, const int& width);
        int getHeight( ) const;
        int getWidth( ) const;
        int getMaxColorValue( ) const;
        int getChannel( const int& row, const int& column, const int& channel ) const;
        bool indexValid( const int& row, const int& column, const int& channel ) const;
        int index( const int& row, const int& column, const int& channel ) const;
        bool valueValid( const int& value ) const;
        void setHeight( const int& height );
        void setWidth( const int& width  );
        void setMaxColorValue( const int& max_color_value );
        void setChannel( const int& row, const int& column, const int& channel, const int& value );
        void setPixel( const int& row, const int& column, const int& red, const int& green, const int& blue );
        friend ostream& operator<<( std::ostream& os, const PPM& rhs );

    private:
        int mHeight;
        int mWidth;
        int mMaxColorValue;
        std::vector <int> mVect;
};



#endif