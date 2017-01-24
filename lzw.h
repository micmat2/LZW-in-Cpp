#ifndef LZW_H
#define LZW_H
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

class LZW{

protected:

    ifstream plikin;
    ofstream plikout;
    ofstream pliklog;
public:
    virtual void run(){}
    virtual ~LZW();

    LZW();
};

#endif // LZW_H
