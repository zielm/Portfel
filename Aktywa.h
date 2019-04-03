//
// Created by PC on 2018-01-27.
//

#ifndef PORTFELPROJEKT_AKTYWA_H
#define PORTFELPROJEKT_AKTYWA_H
#include <iostream>
#include <string>
using namespace std;

class Aktywa {
private:
    string nazwa;
    int wartosc;
    int dataKupna[3];
    int rodzaj;

public:
    Aktywa();

    Aktywa(string nazwaAktywa, int wartosc, int *data);
    virtual ~Aktywa();

    void setNazwa(const string &nazwa);
    const string getNazwa();
    void setRodzaj(int rodzaj);
    int getRodzaj() const;
    string wyswietlDataKupna();
    int iloscDni(int *data);


    virtual void opis();
    virtual string daneDoZapisu() = 0;
    string dane();
    virtual double szacujWartosc(int *data) = 0;
    virtual void edytuj() = 0;

    int getWartosc() const;

    void setWartosc(int wartosc);

    void setDataKupna(int *data);
};


#endif //PORTFELPROJEKT_AKTYWA_H
