//
// Created by PC on 2018-01-28.
//

#ifndef PORTFELPROJEKT_LISTA_H
#define PORTFELPROJEKT_LISTA_H
#include <iostream>
#include <vector>
using namespace std;

template <class T> class Lista {

private:
    vector<T*> elementy;

public:
    Lista() {}

    ~Lista() {}

    vector<T*> getElementy()  {
        return elementy;
    }

    int rozmiar() {
        return elementy.size();
    }

    T* element(int nr) {
        return elementy.at(nr);
    }

    vector<T*> & operator+=(T *el){
        elementy.push_back(el);
        return elementy;
    }

    vector<T*> & operator-=(int nr){
        delete elementy.at(nr);
        elementy.erase(elementy.begin() + nr);
    }
};

#endif //PORTFELPROJEKT_LISTA_H
