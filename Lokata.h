//
// Created by PC on 2018-01-27.
//

#ifndef PORTFELPROJEKT_LOKATA_H
#define PORTFELPROJEKT_LOKATA_H

#include "Aktywa.h"
#include <iostream>
#include <string>
using namespace std;

class Lokata : public Aktywa{
private:
    int oprocentowanie;
    int sposobKapitalizacji;

public:
    Lokata(const string &nazwaAktywa, int wartosc, int *data);

    Lokata(const string &nazwaAktywa, int wartosc, int *data, int oprocentowanie, int sposobKapitalizacji);

    ~Lokata();

    void opis() override;
    string daneDoZapisu() override;

    double szacujWartosc(int *data) override;

    void edytuj() override;

};


#endif //PORTFELPROJEKT_LOKATA_H
