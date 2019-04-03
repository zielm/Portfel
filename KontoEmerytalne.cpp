//
// Created by PC on 2018-01-27.
//

#include "KontoEmerytalne.h"
#include <iostream>
#include <string>
using namespace std;


KontoEmerytalne::KontoEmerytalne(const string &nazwaAktywa, int wartosc, int *data) : Aktywa(nazwaAktywa, wartosc, data) {
    setRodzaj(5);
    cout << "Skladka miesieczna: ";
    cin >> skladkaMiesieczna;
    cout << "Oprocentowanie: ";
    cin >> oprocentowanie;
}

KontoEmerytalne::KontoEmerytalne(const string &nazwaAktywa, int wartosc, int *data, int skladkaMiesieczna,
                                 int oprocentowanie) : Aktywa(nazwaAktywa, wartosc, data),
                                                       skladkaMiesieczna(skladkaMiesieczna),
                                                       oprocentowanie(oprocentowanie) {
    setRodzaj(5);
}

KontoEmerytalne::~KontoEmerytalne() {

}

void KontoEmerytalne::opis() {
    cout << "Konto emerytalne | ";
    Aktywa::opis();
    cout << " | " << skladkaMiesieczna << " | " << oprocentowanie << "% \n";
}

string KontoEmerytalne::daneDoZapisu() {
    string s = Aktywa::dane();
    s = s + " " + to_string(skladkaMiesieczna) + " " + to_string(oprocentowanie);
    return s;
}

/*
 * oprocentowanie roczne
 * jako że skladka musi być pobierana to nie zaliczam jej do zysku
 * (ale wartość początkową tak, uznając że ona się zwróciła po latach)
 */
double KontoEmerytalne::szacujWartosc(int *data) {
    int ileDni = iloscDni(data);
    double tempWartosc = getWartosc();
    double zysk = getWartosc();
    for(int i = 0; i < (ileDni/365); i++) {
        tempWartosc += 12*skladkaMiesieczna;
        zysk += (oprocentowanie/100.0)*(tempWartosc);
    }
    cout << "Konto emerytalne " << getNazwa() << " | " << ileDni << "dni | "<< getWartosc() << " | " << zysk << '\n';
    return zysk;
}

void KontoEmerytalne::edytuj() {

    int wybor;
    cout << "Wybierz co chcesz edytowac: \n"
            " 1 - nazwa \n"
            " 2 - wartosc \n"
            " 3 - data \n"
            " 4 - skladka miesieczna \n"
            " 5 - oprocentowanie \n";
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
            cout << "Skladka miesieczna: ";
            cin >> skladkaMiesieczna;
            break;
        }
        case 5: {
            cout << "Oprocentowanie: ";
            cin >> oprocentowanie;
            break;
        }
        default:
            break;
    }


}


