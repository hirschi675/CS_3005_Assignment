#ifndef _IMAGE_MENU_H_
#define _IMAGE_MENU_H_

#include <iostream>
#include <string>
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

