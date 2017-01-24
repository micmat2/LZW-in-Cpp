#include "kompresja.h"

Kompresja::Kompresja(char *nazwa){
    kod=1;
    kod_na_wyjscie = 0;
    wypelnij_slownik_alfabetem();
    wszystko_poprawne = true;
    string nazwapliku_out(nazwa);
    nazwapliku_out = nazwapliku_out +".lzw";
    plikout.open("plik.lzw");
    plikin.open(nazwa, ios_base::binary);

    //plikout out w klasie Kodowanie
    kodowanie = new Kodowanie(nazwapliku_out.c_str());

    if(!plikin.is_open() || kodowanie->koniec_pliku == true/*|| !plikout.is_open()*/){
        cout << "cos jest nie tak. blad odczytu plik in: " << nazwa << endl;

        wszystko_poprawne = false;

    }
    else{

        koniec_pliku = false;

        c = "c";
        s = "s";
    }

}
Kompresja::~Kompresja(){
    slownik.clear();
    delete kodowanie;
}

void Kompresja::run(){
    if(wszystko_poprawne){
        cout << "Kompresuje ;)\n";
        //int licznik = 1;
        pobierz_znak();
        c[0] = s[0];
        while(1){

            pobierz_znak();
            if(koniec_pliku == true){
                //kompresja();
                break;
            }
            kompresja();

        }

        kod_na_wyjscie = slownik[c];
        zapisz_kod();
        // koniec
    }
}
void Kompresja::kompresja(){

    if(slownik[c+s] == 0){
        // nie ma w slowniku
        kod_na_wyjscie = slownik[c];
        zapisz_kod();
        slownik[c+s]  = kod++;
        c = s;

    }
    else{
        // jest w slowniku
        c = c + s;

    }

}

void Kompresja::pobierz_znak(){

    plikin.read(&s[0], 1);
    if(plikin.eof()){
        koniec_pliku = true;
    }
}
void Kompresja::zapisz_kod(){

    unsigned k;
    while((k = (1 << (kodowanie->const_bity))) <= kod_na_wyjscie){
        kodowanie->nowy_kod(0);
        kodowanie->const_bity++;
    }

    kodowanie->nowy_kod(kod_na_wyjscie);


}

void Kompresja::wypelnij_slownik_alfabetem(){
    string z = "z";
    for(int i = 0; i < 256; ++i){

        z[0] = char(i);
        slownik[z] = kod;
        kod++;

    }
}
