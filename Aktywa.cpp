//
// Created by PC on 2018-01-27.
//

#include "Aktywa.h"
#include <iostream>
#include <string>
using namespace std;

Aktywa::Aktywa() {}
Aktywa::Aktywa(string nazwaAktywa, int wartosc, int *data) : nazwa(nazwaAktywa), wartosc(wartosc) {
    for (int i = 0; i < 3; ++i) {
        dataKupna[i] = data[i];
    }
}

Aktywa::~Aktywa() {}

void Aktywa::setNazwa(const string &nazwa) {
    Aktywa::nazwa = nazwa;
}

const string Aktywa::getNazwa() {
    return nazwa;
}

int Aktywa::getWartosc() const {
    return wartosc;
}

void Aktywa::setWartosc(int wartosc) {
    Aktywa::wartosc = wartosc;
}

string Aktywa::wyswietlDataKupna() {
    string s = to_string(dataKupna[0]) + "." + to_string(dataKupna[1]) + "." + to_string(dataKupna[2]);
    return s;
}

void Aktywa::setDataKupna(int data[3]) {
    for (int i = 0; i < 3; ++i) {
        dataKupna[i] = data[i];
    }
}

int Aktywa::getRodzaj() const {
    return rodzaj;
}

void Aktywa::setRodzaj(int rodzaj) {
    Aktywa::rodzaj = rodzaj;
}

void Aktywa::opis() {
    cout << nazwa << " | " << wartosc << " | " << wyswietlDataKupna();
}

string Aktywa::dane() {
    string s = to_string(rodzaj) + " " + nazwa + " " + to_string(wartosc) + " " + to_string(dataKupna[0]) + " " + to_string(dataKupna[1]) + " " + to_string(dataKupna[2]);
    return s;
}

/*
 * bardzo uproszczone liczenie ilosci dni
 * przy liczeniu miesiecy i dni zakladamy ze miesiac ma 30 dni
 * przy liczeniu lat zakladamy ze kazdy rok ma 365 dni
*/
int Aktywa::iloscDni(int *data) {
    int tempData[3];
    tempData[0] = dataKupna[0];
    tempData[1] = dataKupna[1];
    tempData[2] = dataKupna[2];
    int iloscDni = 0;

    // roznica w dniach
    if(tempData[0] < data[0]) {
        iloscDni = data[0] - tempData[0];
    }

    else {
        iloscDni = 30 - (tempData[0] - data[0]);
        if(tempData[1] == 12) {
            tempData[1] = 1;
            tempData[2]++;
        }
        else {
            tempData[1]++;
        }
    }

    //roznica w miesiach
    if(tempData[1] < data[1]) {
        iloscDni += 30 * (data[1] - tempData[1]);
    }

    else {
        iloscDni += 30 * (12 - (tempData[1] - data[1]));
        tempData[2]++;
    }

    //roznica w latach
    iloscDni += 365 * (data[2] - tempData[2]);

    return iloscDni;
}
