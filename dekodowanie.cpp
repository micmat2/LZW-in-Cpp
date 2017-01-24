#include "dekodowanie.h"


Dekodowanie::Dekodowanie(const char *nazwa_pliku){
    cout << nazwa_pliku << endl;
    plik_in.open(nazwa_pliku, ios_base::in | ios_base::binary);
    if(!plik_in.is_open() ){
        cout << "cos jest nie tak. blad odczytu pliku in: " << nazwa_pliku << endl;
        koniec_pliku = true;
    }
    else{
        koniec_pliku = false;
        plikLOG.open("plikLOGdek");
    }
    this->const_bity = 8;
    this->kod = 0;
    this->bity = this->const_bity;
    pobierz_znak(); // wolne: 8
}
Dekodowanie::~Dekodowanie(){
    plik_in.close();
}
void Dekodowanie::pobierz_znak(){
    char temp_znak = 0;
    plik_in.read(&temp_znak, 1);
    if(plik_in.eof()){
        koniec_pliku = true;
    }
    this->znak = static_cast<unsigned char>(temp_znak);
    wolne = 8;


}
void Dekodowanie::dekodowanie(){

    while(this->bity > 0){
        plikLOG << "wb: " << wolne << " " << bity << endl;

        if(this->wolne == this->bity){

            kod = kod | znak;

            pobierz_znak();
            bity = 0;
            //zwroc kod.
        }
        else if(this->wolne < this->bity){
            kod = kod | znak;
            bity = bity - wolne;

            kod = kod << bity;
            pobierz_znak();
        }
        else{
            wolne = wolne - bity;
            kod = kod | (znak >> wolne);
            znak = znak << bity;
            znak = znak >> bity;
            bity = 0;
        }

        if(koniec_pliku == true){
            break;
        }

    }
}

unsigned Dekodowanie::nowy_kod(){

    do{
        this->kod = 0;
        this->bity = this->const_bity;

        dekodowanie();



        if(kod == 0){
            cout << "zwiekszono  bity\n";
            this->const_bity++;
        }
        else{
            break;
        }
    }while(koniec_pliku == false);
    plikLOG << koniec_pliku << " " << const_bity << " " << kod << endl;
    return this->kod;
}
