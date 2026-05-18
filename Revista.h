//
// Created by cbalb on 18/05/2026.
//

#ifndef BIBLIOTECA2_REVISTA_H
#define BIBLIOTECA2_REVISTA_H
#include "Material.h"
#include <iostream>
#include <stdexcept>
using namespace std;

class Revista : public Material{
private:
    string editorial;
    int numeroEdicion;
    double precioSuscripcion;
public:
    //constructores
    Revista();
    Revista(const string& titulo, const string& codigoIdentificador, const int& unidadesDisponibles
        , const string& editorial, const int& numeroEdicion, const double& precioSuscripcion);
    Revista(const Revista& revista);
    ~Revista() override = default;
    //getters
    string getEditorial() const;
    int getNumeroEdicion() const;
    double getPrecioSuscripcion() const;
    //setters
    void setEditorial(const string& editorial);
    void setNumeroEdicion(const int& numeroEdicion);
    void setPrecioSuscripcion(const double& precioSuscripcion);
    //metodos
    double calcularValor() const override;
    void retirar(int cantidad) override;
    void nuevaEdicion();
};


#endif //BIBLIOTECA2_REVISTA_H
