//
// Created by cbalb on 18/05/2026.
//

#ifndef BIBLIOTECA2_LIBRO_H
#define BIBLIOTECA2_LIBRO_H
#include "Material.h"
#include <iostream>
using namespace std;

class Libro : public Material{
private:
    string autor;
    double precioUnidad;
    int prestamosHistoricos;
public:
    //constructores
    Libro();
    Libro(const string& titulo, const string& codigoIdentificador, const int& unidadesDisponibles
        , const string& autor, const double& precioUnidad, const int& prestamosHistoricos);
    Libro(const Libro& libro);
    ~Libro() override = default;
    //getters
    string getAutor() const;
    double getPrecioUnidad() const;
    int getPrestamosHistoricos() const;
    //setters
    void setAutor(const string& autor);
    void setPrecioUnidad(const double& precioUnidad);
    void setPrestamosHistoricos(const int& prestamosHistoricos);
    //sobrecarga
    Libro& operator++();
    //metodos
    double calcularValor() const override;
    void retirar(int cantidad) override;
    void prestar();
};


#endif //BIBLIOTECA2_LIBRO_H
