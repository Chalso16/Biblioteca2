//
// Created by cbalb on 18/05/2026.
//

#ifndef BIBLIOTECA2_ESTANTERIA_H
#define BIBLIOTECA2_ESTANTERIA_H
#include <iostream>
#include <vector>
using namespace std;

template<class T>
class Estanteria {
private:
    T elemento1;
    T elemento2;
public:
    //constructores
    //Estanteria();
    Estanteria(const T& elemento1, const T& elemento2): elemento1(elemento1), elemento2(elemento2){}
    Estanteria(const Estanteria& estanteria):elemento1(estanteria.elemento1), elemento2(estanteria.elemento2){}
    ~Estanteria() = default;
    //getters
    T getElemento1() const {
        return elemento1;
    }
    T getElemento2() const {
        return elemento2;
    }
    //setters
    void setElemento1(const T& elemento1) {
        this->elemento1=elemento1;
    }
    void setElemento2(const T& elemento2) {
        this->elemento2=elemento2;
    }
    //metodos
    void mostrarContenido() const{
        cout << *elemento1 << endl;
        cout << *elemento2 << endl;
    }
};


#endif //BIBLIOTECA2_ESTANTERIA_H
