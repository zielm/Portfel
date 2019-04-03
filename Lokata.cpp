//
// Created by PC on 2018-01-27.
//

#include "Lokata.h"
#include <iostream>
#include <string>
using namespace std;


Lokata::Lokata(const string &nazwaAktywa, int wartosc, int *data) : Aktywa(nazwaAktywa, wartosc, data) {
    setRodzaj(0);
    cout << "Wysokosc oprocentowania: ";
    cin >> oprocentowanie;
    while(true) {
        cout << "Sposob kapitalizacji: \n"
                "1 - miesieczna \n"
                "2 - polroczna \n"
                "3 - roczna\n";
        cin >> sposobKapitalizacji;
        if (sposobKapitalizacji != 1 && sposobKapitalizacji != 2 && sposobKapitalizacji != 3) {
            continue;
        }
        break;
    }
}


Lokata::Lokata(const string &nazwaAktywa, int wartosc, int *data, int oprocentowanie, int sposobKapitalizacji) :
        Aktywa(nazwaAktywa, wartosc, data), oprocentowanie(oprocentowanie), sposobKapitalizacji(sposobKapitalizacji) {
    setRodzaj(0);
}

Lokata::~Lokata() {

}

void Lokata::opis() {
    cout << "Lokata | ";
    Aktywa::opis();
    cout << " | " << oprocentowanie << "% | ";
    switch(sposobKapitalizacji) {
        case 1:
            cout << "miesieczna";
            break;
        case 2:
            cout << "polroczna";
            break;
        case 3:
            cout << "roczna";
            break;
        default:
            break;
    }
    cout << '\n';
}

string Lokata::daneDoZapisu() {
    string s = Aktywa::dane();
    s = s + " " + to_string(oprocentowanie) + " " + to_string(sposobKapitalizacji);
    return s;
}

double Lokata::szacujWartosc(int *data) {
    int ileDni = iloscDni(data);
    int iloscOkresowKapitalizacji;

    // uznajemy ze odsetki nie sa kapitalizowane
    switch(sposobKapitalizacji){
        case 1:
            iloscOkresowKapitalizacji = ileDni/30;
            break;
        case 2:
            iloscOkresowKapitalizacji = ileDni/182;
            break;
        case 3:
            iloscOkresowKapitalizacji = ileDni/365;
            break;
        default:
            break;
    }

    double zysk;
    zysk = getWartosc() + getWartosc()*(oprocentowanie/100.0)*iloscOkresowKapitalizacji;
    cout << "Lokata " << getNazwa() << " | "<< ileDni << "dni | "<< getWartosc() << " | " << zysk << '\n';
    return zysk;
}

void Lokata::edytuj() {
    int wybor;
    cout << "Wybierz co chcesz edytowac: \n"
            " 1 - nazwa \n"
            " 2 - wartosc \n"
            " 3 - data \n"
            " 4 - oprocentowanie \n"
            " 5 - sposob kapitalizacji \n";
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
            break;
        }
        case 4: {
            cout << "Nowa wysokosc oprocentowania: ";
            cin >> oprocentowanie;
            break;
        }
        case 5: {
            while (true) {
                cout << "Sposob kapitalizacji: \n"
                        "1 - miesieczna \n"
                        "2 - polroczna \n"
                        "3 - roczna\n";
                cin >> sposobKapitalizacji;
                if (sposobKapitalizacji != 1 && sposobKapitalizacji != 2 && sposobKapitalizacji != 3) {
                    continue;
                }
                break;
            }
            break;
        }
        default:
            break;
    }
}
