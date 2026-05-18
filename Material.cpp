//
// Created by cbalb on 17/05/2026.
//

#include "Material.h"

//constructores
Material::Material():titulo("x"), codigoIdentificador("123xxx"), unidadesDisponibles(0) {

}

Material::Material(const string &titulo, const string &codigoIdentificador, const int &unidadesDisponibles)
    : titulo(titulo), codigoIdentificador(codigoIdentificador), unidadesDisponibles(unidadesDisponibles){
    if (unidadesDisponibles<0) {
        throw invalid_argument("Unidades disponibles fuera de rango");
    }
    if (titulo.empty()) {
        throw invalid_argument("Titulo vacio");
    }
    if (codigoIdentificador.empty()) {
        throw invalid_argument("CodigoIdentificador vacio");
    }
}

Material::Material(const Material &material)
    :   titulo(material.titulo), codigoIdentificador(material.codigoIdentificador), unidadesDisponibles(material.unidadesDisponibles) {

}

//getters

string Material::getTitulo() const {
    return titulo;
}

string Material::getCodigoIdentificador() const {
    return codigoIdentificador;
}

int Material::getUnidadesDisponibles() const {
    return unidadesDisponibles;
}

//setters

void Material::setTitulo(const string &titulo) {
    if (titulo.empty()) {
        throw invalid_argument("Titulo vacio");
    }
    this->titulo=titulo;
}

void Material::setCodigoIdentificador(const string &codigoIdentificador) {
    if (codigoIdentificador.empty()) {
        throw invalid_argument("CodigoIdentificador vacio");
    }
    this->codigoIdentificador=codigoIdentificador;
}

void Material::setUnidadesDisponibles(const int &unidadesDisponibles) {
    if (unidadesDisponibles<0) {
        throw invalid_argument("Unidades disponibles fuera de rango");
    }
    this->unidadesDisponibles=unidadesDisponibles;
}

//sobrecarga
ostream &operator<<(ostream &os, const Material &material) {
    os << "-->Titulo: " << material.titulo << endl;
    os << "-->CodigoIdentificador: " << material.codigoIdentificador << endl;
    os << "-->UnidadesDisponibles: " << material.unidadesDisponibles << endl;
    return os;
}

//metodos
void Material::retirar(int cantidad) {
    if (cantidad<0) {
        throw invalid_argument("Cantidad menor a 0");
    }
    if (cantidad> getUnidadesDisponibles()) {
        throw invalid_argument("Cantidad a retirar mayor a existencias");
    }
    setUnidadesDisponibles(getUnidadesDisponibles()-cantidad);
}
