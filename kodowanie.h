#ifndef KODOWANIE_H
#define KODOWANIE_H
#include <iostream>
#include <bitset>
#include <fstream>
using namespace std;

class Kodowanie
{
private:
    unsigned wolne;
    unsigned bity;
    ofstream plikLOG;
    char znak;
    ofstream plik_out;
    unsigned kod; // nie woolno zmieniac na int.. proboblem z przesunięciem w prawo.
public:
    Kodowanie(const char *nazwa_pliku);
    unsigned const_bity;
    bool koniec_pliku;
    ~Kodowanie();
    void nowy_kod(unsigned kod);
    void zapisz_znak();
    void kodowanie();
};

#endif // KODOWANIE_H
