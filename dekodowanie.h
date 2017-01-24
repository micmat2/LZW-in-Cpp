#ifndef DEKODOWANIE_H
#define DEKODOWANIE_H
#include <iostream>
#include <fstream>
#include <bitset>
using namespace std;

class Dekodowanie
{
    unsigned const_bity;
    unsigned bity;
    unsigned wolne;
    unsigned char znak; // koniecznie bez znaku. problem z przesunieciem w prawo
    unsigned kod;
    ofstream plikLOG;
    ifstream plik_in;
    void pobierz_znak();
    void dekodowanie();

public:
    bool koniec_pliku;
    unsigned nowy_kod();

    Dekodowanie(const char *nazwa_pliku);
    ~Dekodowanie();
};

#endif // DEKODOWANIE_H
