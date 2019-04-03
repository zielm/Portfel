//
// Created by PC on 2018-01-27.
//

#ifndef PORTFELPROJEKT_KONTRAKT_H
#define PORTFELPROJEKT_KONTRAKT_H

#include "Aktywa.h"
#include <iostream>
#include <string>
using namespace std;

class Kontrakt : public Aktywa {
private:
    int procentZysku;
    int ryzykoStrat;
public:
    Kontrakt(const string &nazwaAktywa, int wartosc, int *data);

    Kontrakt(const string &nazwaAktywa, int wartosc, int *data, int procentZysku, int ryzykoStrat);

    ~Kontrakt();

    void opis() override;

    string daneDoZapisu() override;

    double szacujWartosc(int *data) override;

    void edytuj() override;

};


#endif //PORTFELPROJEKT_KONTRAKT_H
