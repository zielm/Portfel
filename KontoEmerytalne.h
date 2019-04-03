//
// Created by PC on 2018-01-27.
//

#ifndef PORTFELPROJEKT_KONTOEMERYTALNE_H
#define PORTFELPROJEKT_KONTOEMERYTALNE_H

#include "Aktywa.h"
#include <iostream>
#include <string>
using namespace std;

class KontoEmerytalne : public Aktywa {
private:
    int skladkaMiesieczna;
    int oprocentowanie;

public:
    KontoEmerytalne(const string &nazwaAktywa, int wartosc, int *data);

    KontoEmerytalne(const string &nazwaAktywa, int wartosc, int *data, int skladkaMiesieczna, int oprocentowanie);

    ~KontoEmerytalne();

    void opis() override;

    string daneDoZapisu() override;

    double szacujWartosc(int *data) override;

    void edytuj() override;

};


#endif //PORTFELPROJEKT_KONTOEMERYTALNE_H
