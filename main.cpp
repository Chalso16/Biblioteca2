#include "Material.h"
#include "Libro.h"
#include "Revista.h"
#include "Estanteria.h"
#include <iostream>
#include <memory>
using namespace std;

int main() {
    try {
        //1.
        cout << "1."<<endl;
        shared_ptr<Material> libroAntiguo = make_shared<Libro>("Pupi", "123XYZ", 15, "JK", 10.95, 30);
        shared_ptr<Material> revistaAntigua = make_shared<Revista>("Marca", "321ABC", 10, "Mbappe", 1, 7.99);

        //2.
        cout << "2."<<endl;
        cout << *libroAntiguo <<"Valor: "<< libroAntiguo->calcularValor() << "\n" << endl;
        cout << *revistaAntigua <<"Valor: "<< revistaAntigua->calcularValor() << "\n" << endl;

        //3.
        cout << "3."<<endl;
        libroAntiguo->retirar(5);
        cout << *libroAntiguo << endl;
        revistaAntigua->retirar(5);
        cout << *revistaAntigua << endl;

        //4.
        cout << "4."<<endl;
        try {
            libroAntiguo->retirar(1000);
            cout << *libroAntiguo << endl;
        }catch (const invalid_argument& error) {
            cout << "ERROR, " << error.what() << endl;
        }

        //5.
        cout << "5."<<endl;
        shared_ptr<Libro> libroNuevo = dynamic_pointer_cast<Libro>(libroAntiguo);
        libroNuevo->prestar();
        ++(*libroNuevo);
        cout << *libroNuevo << endl;

        shared_ptr<Revista> revistaNueva = dynamic_pointer_cast<Revista>(revistaAntigua);
        revistaNueva->nuevaEdicion();
        cout << *revistaNueva << endl;

        //6.
        cout << "6."<<endl;
        Estanteria<shared_ptr<Material>> estanteria(revistaNueva, libroNuevo);
        cout << *estanteria.getElemento1() << endl;
        cout << *estanteria.getElemento2() << endl;
        estanteria.mostrarContenido();

        // Estanteria<shared_ptr<Material>> estanteria2(make_shared<Libro>("El retorno de Pupi", "456QRS", 100, "Yolanda", 23.98, 999), libroNuevo);
        // cout << *estanteria2.getElemento1() << endl;


    }catch (const invalid_argument& e) {
        cout << "ERROR, " << e.what()<<endl;
    }
    return 0;
}
