//
// Created by PC on 2018-01-27.
//

#include "JednostkiFunduszu.h"
#include <iostream>
#include <string>
using namespace std;

JednostkiFunduszu::JednostkiFunduszu(const string &nazwaAktywa, int wartosc, int *data) : Aktywa(nazwaAktywa, wartosc, data) {
    setRodzaj(1);
    while(true) {
        cout << "Dywidenda (0 - nie / 1 - tak): ";
        cin >> dywidenda;
        if(dywidenda != 0 && dywidenda != 1) continue;
        break;
    }
    cout << "Procent zysku: ";
    cin >> procentZysku;
    cout << "Ryzyko strat: ";
    cin >> ryzykoStrat;
}

JednostkiFunduszu::JednostkiFunduszu(const string &nazwaAktywa, int wartosc, int *data, int dywidenda, int procentZysku,
                                     int ryzykoStrat) : Aktywa(nazwaAktywa, wartosc, data), dywidenda(dywidenda),
                                                        procentZysku(procentZysku), ryzykoStrat(ryzykoStrat) {
    setRodzaj(1);
}


JednostkiFunduszu::~JednostkiFunduszu() {}

void JednostkiFunduszu::opis() {
    cout << "Jednostki funduszu | ";
    Aktywa::opis();
    if(dywidenda == 0) {
        cout << " | nie | ";
    }
    else {
        cout << " | tak | ";
    }
    cout << procentZysku << "% | " << ryzykoStrat << "%" << '\n';
}

string JednostkiFunduszu::daneDoZapisu(){
    string s = Aktywa::dane();
    s = s + " " + to_string(dywidenda) + " " + to_string(procentZysku) + " " + to_string(ryzykoStrat);
    return s;
}

/*
 * zakladam procent zysku na rok
 * nie biore pod uwage ryzyka strat, poniewaz zaden bank nie bedzie go liczyc przy wyliczaniu zysku
 * dywidenda wyplacana na rok w wys 1% od sumy
 */
double JednostkiFunduszu::szacujWartosc(int *data) {
    double zysk = getWartosc();
    int ileDni = iloscDni(data);
    int dywidendy = 0;


    for(int i = 0; i < (ileDni/365); i++) {
        zysk += zysk*(procentZysku / 100.0);
        if(dywidenda == 1) {
            dywidendy += 0.01 * zysk;
        }
    }
    zysk += dywidendy;
    cout << "Jedn. funduszu " << getNazwa() << " | " << ileDni << "dni | "<< getWartosc() << " | "  << zysk << '\n';
    return zysk;
}

void JednostkiFunduszu::edytuj() {

    int wybor;
    cout << "Wybierz co chcesz edytowac: \n"
            " 1 - nazwa \n"
            " 2 - wartosc \n"
            " 3 - data \n"
            " 4 - dywidenda \n"
            " 5 - procent zysku \n"
            " 6 - ryzyko strat \n";
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
            while (true) {
                cout << "Dywidenda (0 - nie / 1 - tak): ";
                cin >> dywidenda;
                if (dywidenda != 0 && dywidenda != 1) continue;
                break;
            }
            break;
        }
        case 5: {
            cout << "Procent zysku: ";
            cin >> procentZysku;
            break;
        }
        case 6: {
            cout << "Ryzyko strat: ";
            cin >> ryzykoStrat;
            break;
        }
        default:
            break;
    }

}

