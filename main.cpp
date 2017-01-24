#include <iostream>
#include "kompresja.h"
#include "dekompresja.h"
#include "lzw.h"
#include <map>
#include <string>
using namespace std;
void kompresja(LZW *t, char nazwa[]){
    cout << "Kompresja pliku...\n";
    t = new Kompresja(nazwa);
    t->run();
    delete t;
}
void dekompresja(LZW *t, char nazwa[]){
    cout << "Dekompresja pliku...\n";
    t = new Dekompresja(nazwa);
    t->run();
    delete t;
}

int main(int argv, char *argc[]){


    LZW *t = NULL;

    if(argv == 3){

                if(argc[1][0] == 'k'){

                    kompresja(t, argc[2]);
                }
                else if(argc[1][0] == 't'){




                }
                else if(argc[1][0] == 'd'){
                     dekompresja(t, argc[2]);
                }
                else{
                    cout << "o chuj Ci chodzi :D";
                }

    }
    else if(argv == 1){
        int menu = 0;
        char nazwa_pliku[256];
        cout << "nazwa pliku\n>>";
        cin >> nazwa_pliku;
        cout << "MENU: " << endl;
        cout << "1. kompresja\n";
        cout << "2. dekompresja\n";
        cout << ">>";
        cin >> menu;
        if(menu == 1){
            kompresja(t, nazwa_pliku);
        }
        else if(menu == 2){
            dekompresja(t, nazwa_pliku);
        }
        else{
            cout << "o chuj Ci chodzi??\n";
        }
    }


    return 0;
}

