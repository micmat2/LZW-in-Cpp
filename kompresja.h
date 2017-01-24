#ifndef KOMPRESJA_H
#define KOMPRESJA_H
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include "lzw.h"
#include "kodowanie.h"
#include <bitset>
using namespace std;


class Kompresja : public LZW
{
private:

    map<string, int> slownik;

    unsigned kod;
    unsigned kod_na_wyjscie;
    bool wszystko_poprawne;
    Kodowanie *kodowanie;
    string c;
    string s;
    void wypelnij_slownik_alfabetem();
    void pobierz_znak();
    void kompresja();
public:
    bool koniec_pliku;
    virtual void run();
    Kompresja(char *nazwa);
    void zapisz_kod();
    ~Kompresja();
};

#endif // KOMPRESJA_H
