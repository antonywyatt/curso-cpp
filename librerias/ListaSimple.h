// ListaSimple.h
#ifndef LISTASIMPLE_H
#define LISTASIMPLE_H
#include <iostream>

using namespace std;

struct Nodo {
    string codigo;
    string valor1;
    string valor2;
    string valor3;
    string valor4; //datos para uso de lista simple
    Nodo* siguiente;
};

class ListaSimple {
public:
    ListaSimple();
    ~ListaSimple();
    void agregar(Nodo valor);
    void eliminar(string valor);
    void imprimir();
private:
    Nodo* cabeza;
};

#endif

ListaSimple::ListaSimple() : cabeza(nullptr) {}

ListaSimple::~ListaSimple() {
    while (cabeza) {
        Nodo* nodoEliminar = cabeza;
        cabeza = cabeza->siguiente;
        delete nodoEliminar;
    }
}

void ListaSimple::agregar(Nodo valor) {
    Nodo* nuevoNodo = new Nodo{
        valor.codigo,
        valor.valor1,
        valor.valor2,
        valor.valor3,
        valor.valor4,
        nullptr
    };
    if (!cabeza) {
        cabeza = nuevoNodo;
    } else {
        Nodo* actual = cabeza;
        while (actual->siguiente) {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevoNodo;
    }
}

void ListaSimple::eliminar(string valor) {
    if (!cabeza) {
        return; 
    }

    if (cabeza->codigo == valor) {
        Nodo* nodoEliminar = cabeza;
        cabeza = cabeza->siguiente;
        delete nodoEliminar;
    } else {
        Nodo* actual = cabeza;
        while (actual->siguiente && actual->siguiente->codigo != valor) {
            actual = actual->siguiente;
        }
        if (actual->siguiente) {
            Nodo* nodoEliminar = actual->siguiente;
            actual->siguiente = nodoEliminar->siguiente;
            delete nodoEliminar;
        }
    }
}

void ListaSimple::imprimir() {
    Nodo* actual = cabeza;
    cout << "====== DATOS ======" << endl << endl;
    while (actual) {
        cout << actual->codigo << " | " << actual->valor1 << " | " << actual->valor2 << " | " << actual->valor3 << " | " << actual->valor4 << endl;
        actual = actual->siguiente;
    }
    cout << endl;
}