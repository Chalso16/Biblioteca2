//
// Created by cbalb on 18/05/2026.
//

#include "Revista.h"

//constructores
Revista::Revista():Material(), editorial("ComicSans"), numeroEdicion(1), precioSuscripcion(1) {

}

Revista::Revista(const string &titulo, const string &codigoIdentificador, const int &unidadesDisponibles, const string &editorial, const int &numeroEdicion, const double &precioSuscripcion)
    : Material(titulo, codigoIdentificador, unidadesDisponibles)
    , editorial(editorial), numeroEdicion(numeroEdicion), precioSuscripcion(precioSuscripcion) {
    if (editorial.empty()) {
        throw invalid_argument("Editorial vacia");
    }
    if (numeroEdicion<0) {
        throw invalid_argument("NumeroEdicion fuera de rango");
    }
    if (precioSuscripcion<0) {
        throw invalid_argument("PrecioSuscripcion fuera de rango");
    }
}

Revista::Revista(const Revista &revista): Material(revista), editorial(revista.editorial), numeroEdicion(revista.numeroEdicion), precioSuscripcion(revista.precioSuscripcion) {

}

//getters
string Revista::getEditorial() const {
    return editorial;
}

int Revista::getNumeroEdicion() const {
    return numeroEdicion;
}

double Revista::getPrecioSuscripcion() const {
    return precioSuscripcion;
}

//setters
void Revista::setEditorial(const string &editorial) {
    if (editorial.empty()) {
        throw invalid_argument("Editorial vacia");
    }
    this->editorial=editorial;
}

void Revista::setNumeroEdicion(const int &numeroEdicion) {
    if (numeroEdicion<0) {
        throw invalid_argument("NumeroEdicion fuera de rango");
    }
    this->numeroEdicion=numeroEdicion;
}

void Revista::setPrecioSuscripcion(const double &precioSuscripcion) {
    if (precioSuscripcion<0) {
        throw invalid_argument("PrecioSuscripcion fuera de rango");
    }
    this->precioSuscripcion=precioSuscripcion;
}

//metodos
double Revista::calcularValor() const {
    return getPrecioSuscripcion()*getNumeroEdicion();
}

void Revista::retirar(int cantidad) {
    if (cantidad<0) {
        throw invalid_argument("Cantidad menor a 0");
    }
    if (getUnidadesDisponibles()<cantidad) {
        throw invalid_argument("Cantidad a retirar mayor a UnidadesDisponibles");
    }
    setUnidadesDisponibles(getUnidadesDisponibles()-cantidad);
}

void Revista::nuevaEdicion() {
    setNumeroEdicion(getNumeroEdicion()+1);
    setUnidadesDisponibles(10);
}
