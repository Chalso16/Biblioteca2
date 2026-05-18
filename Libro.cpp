//
// Created by cbalb on 18/05/2026.
//

#include "Libro.h"

//constructores
Libro::Libro():Material(), autor("Mahmoud"), precioUnidad(0), prestamosHistoricos(0) {
}

Libro::Libro(const string &titulo, const string &codigoIdentificador, const int &unidadesDisponibles, const string &autor, const double &precioUnidad, const int &prestamosHistoricos)
    : Material(titulo, codigoIdentificador, unidadesDisponibles)
    , autor(autor), precioUnidad(precioUnidad), prestamosHistoricos(precioUnidad){
    if (autor.empty()) {
        throw invalid_argument("Autor vacio");
    }
    if (precioUnidad<0) {
        throw invalid_argument("Precio menor a 0");
    }
    if (prestamosHistoricos<0) {
        throw invalid_argument("PrestamosHistoricos menor a 0");
    }
}

Libro::Libro(const Libro &libro): Material(libro), autor(libro.autor), precioUnidad(libro.precioUnidad), prestamosHistoricos(libro.prestamosHistoricos) {

}

//getters
string Libro::getAutor() const {
    return autor;
}

double Libro::getPrecioUnidad() const {
    return precioUnidad;
}

int Libro::getPrestamosHistoricos() const {
    return prestamosHistoricos;
}

//setters

void Libro::setAutor(const string &autor) {
    if (autor.empty()) {
        throw invalid_argument("Autor vacio");
    }
    this->autor=autor;
}

void Libro::setPrecioUnidad(const double &precioUnidad) {
    if (precioUnidad<0) {
        throw invalid_argument("Precio menor a 0");
    }
}

void Libro::setPrestamosHistoricos(const int &prestamosHistoricos) {
    if (prestamosHistoricos<0) {
        throw invalid_argument("PrestamosHistoricos menor a 0");
    }
    this->prestamosHistoricos=prestamosHistoricos;
}

//sobrecarga
Libro &Libro::operator++() {
    setUnidadesDisponibles(getUnidadesDisponibles()+1);
    return *this;
}

//metodos
double Libro::calcularValor() const {
    return (getUnidadesDisponibles()*getPrecioUnidad()+(getPrestamosHistoricos()*5));
}

void Libro::retirar(int cantidad) {
    if (cantidad<0) {
        throw invalid_argument("Cantidad menor a 0");
    }
    if (cantidad>getUnidadesDisponibles()) {
        throw invalid_argument("Cantidad a descontar mayor a UnidadesDisponibles");
    }
    setUnidadesDisponibles(getUnidadesDisponibles()-cantidad);
}

void Libro::prestar() {
    if (getUnidadesDisponibles()==0) {
        throw invalid_argument("UnidadesDisponibles 0");
    }
    setUnidadesDisponibles(getUnidadesDisponibles()-1);
    setPrestamosHistoricos(getPrestamosHistoricos()+1);
}

