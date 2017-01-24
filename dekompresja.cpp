#include "dekompresja.h"

Dekompresja::Dekompresja(char *nazwa){
cout << "dekompresuje..\n";
    wszystko_poprawne = true;
    kod = 1;
    string nazwa_pliku_out(nazwa);
    if(nazwa_pliku_out.length() > 4)
        nazwa_pliku_out.erase(nazwa_pliku_out.length()-4, nazwa_pliku_out.length()-1);
    cout << "plik_in : " << nazwa << endl;
    cout << "plik_out: " << nazwa_pliku_out << endl;
    wypelnij_slownik_alfabetem();
    dekodowanie = new Dekodowanie(nazwa);
    plikout.open(nazwa_pliku_out.c_str(), ios_base::trunc);
    //plikin.open(nazwa);
    if(/*!plikin.is_open()*/dekodowanie->koniec_pliku==true || !plikout.is_open()){
        cout << "cos jest nie tak. blad odczytu pliku: " << nazwa << endl;

        wszystko_poprawne = false;

    }
    else{
        cout << "OK\n";
        koniec_pliku = false;

    }


}
Dekompresja::~Dekompresja(){
    slownik.clear();
    delete dekodowanie;
}
void Dekompresja::run(){
    if(wszystko_poprawne == true){
        int pk;
        string temp;
        pobierz_kod();
        pk = k;
        //cout << slownik[pk];
        string pc;
        plikout << slownik[pk];
        while(1){
            pobierz_kod();
            if(koniec_pliku == true)
                break;
            pc = slownik[pk];
            temp = slownik[k];
            if(temp.empty()){
                // nie ma w slowniku
                temp = pc + pc[0];
                slownik[kod++] = temp;
                plikout << temp;
                plikout.flush();

            }
            else{
                // jest w slowniuku;
                slownik[kod++] = pc+temp[0];
                plikout << temp;
                plikout.flush();

            }
            pk = k;
            if(koniec_pliku == true){
                break;
            }
        }
        cout << "koniec pliku" << endl;
    }
}
void Dekompresja::pobierz_kod(){
//    plikin >> k;
//    if(plikin.eof()){
//        koniec_pliku = true;

//    }
    k = dekodowanie->nowy_kod();
    if(dekodowanie->koniec_pliku == true){
        this->koniec_pliku = true;
    }
}
void Dekompresja::wypelnij_slownik_alfabetem(){
    string z = "z";
    for(int i = 0; i < 256; ++i){

        z[0] = char(i);
        slownik[kod] = z;
        kod++;

    }
}
