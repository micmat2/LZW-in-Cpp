#include "lzw.h"

LZW::~LZW(){

    plikin.close();
    plikout.close();
    //pliklog.close();
}
LZW::LZW(){
    //pliklog.open("PLIK_LOG", ios_base::trunc);


}
