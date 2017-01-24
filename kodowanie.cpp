#include "kodowanie.h"

Kodowanie::Kodowanie(const char *nazwa_pliku){
    this->const_bity = 8;
    this->bity = this->const_bity;
    this->kod = 0;
    this->znak = 0;
    this->wolne = 8;
    this->plik_out.open(nazwa_pliku, ios_base::binary | ios_base::trunc);
    if(!this->plik_out.is_open() ){
        cout << "cos jest nie tak. blad plik out: " << nazwa_pliku << endl;
        this->koniec_pliku = true;
    }
    else{
        this->koniec_pliku = false;
        plikLOG.open("PLIK_LOG", ios_base::trunc);
    }
}
Kodowanie::~Kodowanie(){
    plik_out.close();
}
void Kodowanie::nowy_kod(unsigned kod){
    this->kod = kod;
    plikLOG << kod << endl;
    this->bity = const_bity;
    kodowanie();
}
void Kodowanie::zapisz_znak(){
    plik_out.write(&znak, 1);
    plik_out.flush();

    wolne = 8;
    znak = 0;
}
void Kodowanie::kodowanie(){
    //while(koniec_pliku == false){
    while(1){
        plikLOG << "wb: " << wolne << " " << bity << endl;

        if(wolne == bity){
            znak = znak | kod;
            zapisz_znak();
            //nowy_kod();
            break;
        }
        else if(wolne < bity){
            bity = bity - wolne;
            znak = znak | (kod >> bity);
            zapisz_znak();

        }
        else{//wolne > bity
            znak = znak | kod;
            wolne = wolne - bity;
            znak = znak << (wolne);
            //nowy_kod();
            break;
        }

    }
    if(koniec_pliku == true){
        zapisz_znak();
        cout << "koniec\n";
    }
}
