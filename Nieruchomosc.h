//
// Created by PC on 2018-01-27.
//

#ifndef PORTFELPROJEKT_NIERUCHOMOSC_H
#define PORTFELPROJEKT_NIERUCHOMOSC_H

#include "Aktywa.h"
#include <iostream>
#include <string>
using namespace std;

class Nieruchomosc : public Aktywa {
private:
    int oplataMiesieczna;
    int procentZysku;
    int ryzykoStrat;
public:
    Nieruchomosc(const string &nazwaAktywa, int wartosc, int *data);

    Nieruchomosc(const string &nazwaAktywa, int wartosc, int *data, int oplataMiesieczna, int procentZysku, int ryzykoStrat);

    virtual ~Nieruchomosc();

    void opis() override;

    string daneDoZapisu() override;

    double szacujWartosc(int *data) override;

    void edytuj() override;

};


#endif //PORTFELPROJEKT_NIERUCHOMOSC_H
