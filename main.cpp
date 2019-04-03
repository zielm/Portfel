#include "Portfel.h"
#include "Aktywa.h"
#include <iostream>
#include <stdlib.h>
#include <windows.h>

using namespace std;

int main() {
    Portfel portfel;
    int wybor;
    int stanKonta;
    cout << "Symulacja portfela \n"
            "1 - stworz nowy portfel \n"
            "2 - wczytaj zapisany portfel \n"
            "inny klawisz - zamknij symulacje \n";
    cin >> wybor;

    if(wybor == 1) {
        cout << "Podaj poczatkowy stan konta: ";
        cin >> stanKonta;
        portfel.setWartosc(stanKonta);
    }

    else if(wybor == 2) {
        if(portfel.wczytaj() == -1) {
            cout << "Portfel nie istnieje, prosze stworzyc nowe konto. \n";
            cout << "Podaj poczatkowy stan konta: ";
            cin >> stanKonta;
            portfel.setWartosc(stanKonta);
        }
    }

    else {
        cout << "Dziekujemy za skorzystanie z symulacji!";
        return 0;
    }

    while(true) {
        system("cls");
        cout << "Symulacja portfela \n"
                "1 - wyswietl stan konta \n"
                "2 - ustaw nowy stan konta \n"
                "3 - wyswietl posiadane aktywa \n"
                "4 - dodaj aktywo \n"
                "5 - usun aktywo \n"
                "6 - edytuj posiadane aktywo \n"
                "7 - symuluj przyszly zysk \n"
                "inny klawisz - zamknij symulacje \n";
        cin >> wybor;

       switch(wybor) {
           case 1:
               cout << "****** \n";
               cout << "Obecny stan konta: " << portfel.getWartosc();
               getchar(); getchar();
               break;
           case 2:
               cout << "****** \n";
               cin.clear();
               cout << "Podaj nowy stan konta: ";
               cin >> stanKonta;
               portfel.setWartosc(stanKonta);
               break;
           case 3:
               cout << "****** \n";
               portfel.wyswietlZawartosc();
               getchar(); getchar();
               break;
           case 4:
               portfel.dodaj();
               break;
           case 5:
               portfel.usun();
               break;
           case 6:
               portfel.zmien();
               break;
           case 7:
               portfel.obliczZysk();
               getchar(); getchar();
               break;
           default:
            cout << "Dziekujemy za skorzystanie z symulacji!";
            return 0;
        }
    }




    return 0;
}