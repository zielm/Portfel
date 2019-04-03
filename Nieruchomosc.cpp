//
// Created by PC on 2018-01-27.
//

#include "Nieruchomosc.h"
#include <iostream>
#include <string>
using namespace std;


Nieruchomosc::Nieruchomosc(const string &nazwaAktywa, int wartosc, int *data) : Aktywa(nazwaAktywa, wartosc, data) {
    setRodzaj(4);
    cout << "Oplata miesieczna: ";
    cin >> oplataMiesieczna;
    cout << "Procent zysku: ";
    cin >> procentZysku;
    cout << "Ryzyko strat: ";
    cin >> ryzykoStrat;
}

Nieruchomosc::Nieruchomosc(const string &nazwaAktywa, int wartosc, int *data, int oplataMiesieczna, int procentZysku,
                           int ryzykoStrat) : Aktywa(nazwaAktywa, wartosc, data), oplataMiesieczna(oplataMiesieczna),
                                              procentZysku(procentZysku), ryzykoStrat(ryzykoStrat) {
    setRodzaj(4);
}

Nieruchomosc::~Nieruchomosc() {

}

void Nieruchomosc::opis() {
    cout << "Nieruchomosc | ";
    Aktywa::opis();
    cout << " | " << oplataMiesieczna << " | " << procentZysku << "% | " << ryzykoStrat << "%" << '\n';
}

string Nieruchomosc::daneDoZapisu() {
    string s = Aktywa::dane();
    s = s + " " + to_string(oplataMiesieczna) + " " + to_string(procentZysku) + " " + to_string(ryzykoStrat);
    return s;
}

/*
* zakladam procent zysku na rok
* nie biore pod uwage ryzyka strat, poniewaz zaden bank nie bedzie go liczyc przy wyliczaniu zysku
 * odejmujemy miesieczne oplaty
*/
double Nieruchomosc::szacujWartosc(int *data) {
    double zysk = getWartosc();
    int ileDni = iloscDni(data);

    for(int i = 0; i < (ileDni/365); i++) {
        zysk += zysk*(procentZysku / 100.0) - 12*oplataMiesieczna;
    }
    cout << "Nieruchomosc " << getNazwa() << " | "<< ileDni << "dni | "<< getWartosc() << " | "  << zysk << '\n';
    return zysk;
}


void Nieruchomosc::edytuj() {

    int wybor;
    cout << "Wybierz co chcesz edytowac: \n"
            " 1 - nazwa \n"
            " 2 - wartosc \n"
            " 3 - data \n"
            " 4 - oplata miesieczna \n"
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
            cout << "oplata miesieczna: ";
            cin >> oplataMiesieczna;
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



