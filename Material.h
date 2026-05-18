//
// Created by cbalb on 17/05/2026.
//

#ifndef BIBLIOTECA2_MATERIAL_H
#define BIBLIOTECA2_MATERIAL_H
#include <iostream>
#include <stdexcept>
#include <cmath>
using namespace std;

class Material {
protected:
    string titulo;
    string codigoIdentificador;
    int unidadesDisponibles;
public:
    //constructores
    Material();
    Material(const string& titulo, const string& codigoIdentificador, const int& unidadesDisponibles);
    Material(const Material& material);
    virtual ~Material() = default;
    //getters
    string getTitulo() const;
    string getCodigoIdentificador() const;
    int getUnidadesDisponibles() const;
    //setters
    void setTitulo(const string& titulo);
    void setCodigoIdentificador(const string& codigoIdentificador);
    void setUnidadesDisponibles(const int& unidadesDisponibles);
    //sobrecarga
    friend ostream& operator<< (ostream& os, const Material& material);
    //metodos
    virtual void retirar(int cantidad);
    virtual double calcularValor() const = 0;
};


#endif //BIBLIOTECA2_MATERIAL_H
