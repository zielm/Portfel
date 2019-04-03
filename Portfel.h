//
// Created by PC on 2018-01-27.
//

#ifndef PORTFELPROJEKT_PORTFEL_H
#define PORTFELPROJEKT_PORTFEL_H
#include <iostream>
#include <vector>
#include "Aktywa.h"
#include "Lista.h"

using namespace std;

class Portfel {

private:
    Lista <Aktywa> posiadaneAktywa;
    int wartosc;

public:
    Portfel();
    ~Portfel();

    int getWartosc();

    void setWartosc(int wartosc);


    int wczytaj();
    void zapisz();
    void wyswietlZawartosc();


    void dodaj();

    void usun();

    void zmien();

    void obliczZysk();


};


#endif //PORTFELPROJEKT_PORTFEL_H
