//
// Created by PC on 2018-01-27.
//

#include "Kontrakt.h"
#include <iostream>
#include <string>
using namespace std;



Kontrakt::Kontrakt(const string &nazwaAktywa, int wartosc, int *data) : Aktywa(nazwaAktywa, wartosc, data) {
    setRodzaj(3);
    cout << "Procent zysku: ";
    cin >> procentZysku;
    cout << "Ryzyko strat: ";
    cin >> ryzykoStrat;
}

Kontrakt::Kontrakt(const string &nazwaAktywa, int wartosc, int *data, int procentZysku, int ryzykoStrat) :
        Aktywa(nazwaAktywa, wartosc, data), procentZysku(procentZysku), ryzykoStrat(ryzykoStrat) {
    setRodzaj(3);
}

Kontrakt::~Kontrakt() {

}

void Kontrakt::opis() {
    cout << "Kontrakt | ";
    Aktywa::opis();
    cout << " | " << procentZysku << "% | " << ryzykoStrat << "%" << '\n';
}

string Kontrakt::daneDoZapisu() {
    string s = Aktywa::dane();
    s = s + " " + to_string(procentZysku) + " " + to_string(ryzykoStrat);
    return s;
}

/*
 * zakladam procent zysku na rok
 * nie biore pod uwage ryzyka strat, poniewaz zaden bank nie bedzie go liczyc przy wyliczaniu zysku
 */
double Kontrakt::szacujWartosc(int *data) {
    double zysk = getWartosc();
    int ileDni = iloscDni(data);

    for(int i = 0; i < (ileDni/365); i++) {
        zysk += zysk*(procentZysku / 100.0);
    }
    cout << "Kontrakt " << getNazwa() << " | " << ileDni << "dni | "<< getWartosc() << " | " << zysk << '\n';
    return zysk;
}

void Kontrakt::edytuj() {
    int wybor;
    cout << "Wybierz co chcesz edytowac: \n"
            " 1 - nazwa \n"
            " 2 - wartosc \n"
            " 3 - data \n"
            " 4 - procent zysku \n"
            " 5 - ryzyko strat \n";
    cin >> wybor;
    switch(wybor) {
        case 1: {
            string nazwa;
            getchar();
            cout << "Podaj nowa nazwe: ";
            getline(cin, nazwa);
            setNazwa(nazwa);
            break;
        }
        case 2: {
            int wartosc;
            cout << "Podaj nowa wartosc: ";
            cin >> wartosc;
            setWartosc(wartosc);
            break;
        }
        case 3: {
            int data[3];
            while (true) {
                cout << "Podaj date \n";
                cout << "Dzien: ";
                cin >> data[0];
                cout << "Miesiac: ";
                cin >> data[1];
                cout << "Rok: ";
                cin >> data[2];

                if (data[0] > 31 || data[1] > 12 || data[2] < 1980 || data[2] > 2018) {
                    cout << "Podales zla date, sprobuj ponownie \n";
                    continue;
                }
                setDataKupna(data);
                break;
            }
        }
        case 4: {
            cout << "Procent zysku: ";
            cin >> procentZysku;
            break;
        }
        case 5: {
            cout << "Ryzyko strat: ";
            cin >> ryzykoStrat;
            break;
        }
        default:
            break;
    }

}


