#ifndef DEKOMPRESJA_H
#define DEKOMPRESJA_H
#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include "lzw.h"
#include "dekodowanie.h"
using namespace std;
class Dekompresja : public LZW
{
private:
    map<int, string> slownik;
    bool wszystko_poprawne;
    bool koniec_pliku;
    int kod;
    Dekodowanie *dekodowanie;
    unsigned k;
    void wypelnij_slownik_alfabetem();

    void pobierz_kod();
public:
    Dekompresja(char *nazwa);
    virtual ~Dekompresja();
    virtual void run();
};

#endif // DEKOMPRESJA_H
