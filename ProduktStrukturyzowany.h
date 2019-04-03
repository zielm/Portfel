//
// Created by PC on 2018-01-27.
//

#ifndef PORTFELPROJEKT_PRODUKTSTRUKTURYZOWANY_H
#define PORTFELPROJEKT_PRODUKTSTRUKTURYZOWANY_H

#include "Aktywa.h"
#include <iostream>
#include <string>
using namespace std;

class ProduktStrukturyzowany : public Aktywa {
private:
    int procentZysku;
    int ryzykoStrat;

public:
    ProduktStrukturyzowany(const string &nazwaAktywa, int wartosc, int *data);

    ProduktStrukturyzowany(const string &nazwaAktywa, int wartosc, int *data, int procentZysku, int ryzykoStrat);

    ~ProduktStrukturyzowany();

    void opis() override;

    string daneDoZapisu() override;

    double szacujWartosc(int *data) override;

    void edytuj() override;


};


#endif //PORTFELPROJEKT_PRODUKTSTRUKTURYZOWANY_H
