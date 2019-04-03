//
// Created by PC on 2018-01-27.
//

#include "ProduktStrukturyzowany.h"
#include "Portfel.h"
#include "Lokata.h"
#include "JednostkiFunduszu.h"
#include "Kontrakt.h"
#include "Nieruchomosc.h"
#include "KontoEmerytalne.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

Portfel::Portfel() {
    wartosc = 0;
    Lista <Aktywa*> posiadaneAktywa;
}

Portfel::~Portfel() {}

/*
 * wczytanie portfela z pliku
 */
int Portfel::wczytaj() {
    ifstream in("portfel.txt");
    if(in.good()) {
        int rodzaj, data[3];
        int wart;
        string nazwa;


        in >> wartosc;
        while(!in.eof())
        {
            in >> rodzaj >> nazwa >> wart >> data[0] >> data[1] >> data[2];

            switch(rodzaj) {
                case 0: {
                    int oprocentowanie, sposobKapitalizacji;
                    in >> oprocentowanie >> sposobKapitalizacji;
                    posiadaneAktywa += new Lokata(nazwa, wart, data, oprocentowanie, sposobKapitalizacji);
                    break;
                }
                case 1: {
                    int dywidenda;
                    int procentZysku, ryzyko;
                    in >> dywidenda >> procentZysku >> ryzyko;
                    posiadaneAktywa += new JednostkiFunduszu(nazwa, wart, data, dywidenda, procentZysku, ryzyko);
                    break;
                }
                case 2: {
                    int procentZysku, ryzyko;
                    in >> procentZysku >> ryzyko;
                    posiadaneAktywa += new ProduktStrukturyzowany(nazwa, wart, data, procentZysku, ryzyko);
                    break;
                }
                case 3: {
                    int procentZysku, ryzyko;
                    in >> procentZysku >> ryzyko;
                    posiadaneAktywa += new Kontrakt(nazwa, wart, data, procentZysku, ryzyko);
                    break;
                }
                case 4: {
                    int oplata, procentZysku, ryzyko;
                    in >> oplata >> procentZysku >> ryzyko;
                    posiadaneAktywa += new Nieruchomosc(nazwa, wart, data, oplata, procentZysku, ryzyko);
                    break;
                }
                case 5: {
                    int skladka, oprocentowanie;
                    in >> skladka >> oprocentowanie;
                    posiadaneAktywa += new KontoEmerytalne(nazwa, wart, data, skladka, oprocentowanie);
                    break;
                }
                default:
                    break;
            }
        }
        cout << "Wczytano zawartosc portfela \n";
        return 0;
    }
    in.close();
    return -1;
}

/*
 * zapisanie portfela do pliku
 */
void Portfel::zapisz() {
    ofstream out("portfel.txt");
    out << wartosc;
    for(int i = 0; i < posiadaneAktywa.rozmiar(); i++) {
        out << '\n' << posiadaneAktywa.element(i)->daneDoZapisu();
    }
    out.close();
}

/*
 * wyswietlanie zawartosci portfela
 */
void Portfel::wyswietlZawartosc() {
    cout << "Sposob wyswietlania informacji o aktywach: \n"
            "rodzaj | nazwa | aktualna wartosc | data \n"
            "nastepnie w zaleznosci od rodzaju: \n"
            " LOKATA | oprocentowanie | rodzaj kapitalizacji \n"
            " JEDN FUNDUSZU | dywidenda | procent zysku | ryzyko strat  \n"
            " PRODUKT | procent zysku | ryzyko strat \n"
            " KONTRAKT | procent zysku | ryzyko strat \n"
            " NIERUCHOMOSC | oplata miesieczna | procent zysku | ryzyko strat \n"
            " KONTO EMERYTALNE | skladka miesieczna | oprocentowanie \n";
    cout << "\n*******\n";
    for(int i = 0; i < posiadaneAktywa.rozmiar(); i++)
    {
        posiadaneAktywa.getElementy().at(i)->opis();
    }

}

/*
 * obliczanie wartosci portfela
 */
void Portfel::obliczZysk() {
    double zysk = wartosc;
    int obecnaWartosc = wartosc;
    int data[3];
    while(true) {
        cout << "Podaj przyszla (co najmniej rok 2020) \n";
        cout << "Dzien: ";
        cin >> data[0];
        cout << "Miesiac: ";
        cin >> data[1];
        cout << "Rok: ";
        cin >> data[2];

        if(data[0] > 31 || data[1] > 12 || data[2] < 2020 ) {
            cout << "Podales zla date, sprobuj ponownie \n";
            continue;
        }
        break;
    }

    cout << "Rodzaj | Nazwa | Ilosc dni | Wartosc obecna | Wartosc przewidywana \n";
    for(int i = 0; i < posiadaneAktywa.rozmiar(); i++)
    {
        obecnaWartosc += posiadaneAktywa.getElementy().at(i)->getWartosc();
        zysk += posiadaneAktywa.getElementy().at(i)->szacujWartosc(data);
    }

    cout << "\n\nObecna wartosc portfela: " << obecnaWartosc;
    cout << "\nSzacowane oszczednosci na " << data[0] << "." << data[1] << "." << data[2] << ": " << zysk << '\n';
    cout << "Szacowany zysk: " << zysk - obecnaWartosc << '\n';


}

/*
 * dodanie aktywa do portfela
 */
void Portfel::dodaj() {
    int wybor;
    cout << "Wybierz aktywo, ktore chcesz dodac do portfela: \n"
         << " 0 - lokata \n"
         << " 1 - jednostki funduszu \n"
         << " 2 - produkt strukturyzowany \n"
         << " 3 - kontrakt \n"
         << " 4 - nieruchomosc \n"
         << " 5 - konto emerytalne \n"
         << " inne - cofnij do menu \n";
    cin >> wybor;

    string nazwa;
    int data[3];
    getchar();
    cout << "Podaj nazwe aktywa: ";
    getline(cin, nazwa);
    while(true) {
        cout << "Podaj date (zakupienie aktywa / zalozenie konta) \n";
        cout << "Dzien: ";
        cin >> data[0];
        cout << "Miesiac: ";
        cin >> data[1];
        cout << "Rok: ";
        cin >> data[2];

        if(data[0] > 31 || data[1] > 12 || data[2] < 1980 || data[2] > 2018) {
            cout << "Podales zla date, sprobuj ponownie \n";
            continue;
        }
        break;
    }

    int wart;
    while(true) {
        cout << "Stan konta: " << wartosc << '\n';
        cout << "Podaj wartosc za jaka chcesz zakupic aktywo: ";
        cin >> wart;
        if(wart > wartosc) {
            cout << "Nie masz tyle srodkow na koncie! \n";
            continue;
        }
        break;
    }

    switch(wybor) {
        case 0:
            posiadaneAktywa += new Lokata(nazwa, wart, data);
            break;
        case 1:
            posiadaneAktywa += new JednostkiFunduszu(nazwa, wart, data);
            break;
        case 2:
            posiadaneAktywa += new ProduktStrukturyzowany(nazwa, wart, data);
            break;
        case 3:
            posiadaneAktywa += new Kontrakt(nazwa, wart, data);
            break;
        case 4:
            posiadaneAktywa += new Nieruchomosc(nazwa, wart, data);
            break;
        case 5:
            posiadaneAktywa += new KontoEmerytalne(nazwa, wart, data);
            break;
        default:
            cout << "Polecenie zostalo zle wybrane \n";
            getchar(); getchar();
            return;
    }

    setWartosc(wartosc - wart);
    zapisz();
}

/*
 * usuniecie aktywa z portfela
 */
void Portfel::usun() {
    int nr;
    for(int i = 0; i < posiadaneAktywa.rozmiar(); i++)
    {
        cout << i << " ";
        posiadaneAktywa.getElementy().at(i)->opis();
    }
    cout << "\n Wybierz z podanych aktywo do usuniecia (podaj numer): ";
    cin >> nr;
    if(nr >= posiadaneAktywa.rozmiar()) {
        cout << "Podano zly numer aktywa \n";
        getchar(); getchar();
        return;
    }
    wartosc += posiadaneAktywa.element(nr)->getWartosc();
    posiadaneAktywa -= nr;
    zapisz();
}

/*
 * zmienienie danych aktywa
 */
void Portfel::zmien() {
    int nr;
    for(int i = 0; i < posiadaneAktywa.rozmiar(); i++)
    {
        cout << i << " ";
        posiadaneAktywa.getElementy().at(i)->opis();
    }
    cout << "\n Wybierz aktywo, ktore chcesz edytowac (podaj numer): ";
    cin >> nr;
    if(nr >= posiadaneAktywa.rozmiar()) {
        cout << "Podano zly numer aktywa \n";
        getchar(); getchar();
        return;
    }
    posiadaneAktywa.getElementy().at(nr)->edytuj();
    zapisz();
}

/*
 * stan konta (obecny)
 */
int Portfel::getWartosc()  {
    int obecnaWartosc = 0;
    for(int i = 0; i < posiadaneAktywa.rozmiar(); i++) {
        obecnaWartosc += posiadaneAktywa.getElementy().at(i)->getWartosc();
    }
    cout << "Obecna wartosc portfela: " << obecnaWartosc << '\n';
    return wartosc;
}

void Portfel::setWartosc(int wartosc) {
    Portfel::wartosc = wartosc;
    zapisz();
}
