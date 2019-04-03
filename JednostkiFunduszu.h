//
// Created by PC on 2018-01-27.
//

#ifndef PORTFELPROJEKT_JEDNOSTKIFUNDUSZU_H
#define PORTFELPROJEKT_JEDNOSTKIFUNDUSZU_H

#include "Aktywa.h"
#include <iostream>
#include <string>
using namespace std;

class JednostkiFunduszu : public Aktywa {
private:
    int dywidenda;
    int procentZysku;
    int ryzykoStrat;
public:
    JednostkiFunduszu(const string &nazwaAktywa, int wartosc, int *data);

    JednostkiFunduszu(const string &nazwaAktywa, int wartosc, int *data, int dywidenda, int procentZysku, int ryzykoStrat);

    ~JednostkiFunduszu();

    void opis() override;

    string daneDoZapisu() override;

    double szacujWartosc(int *data) override;

    void edytuj() override;
};


#endif //PORTFELPROJEKT_JEDNOSTKIFUNDUSZU_H
