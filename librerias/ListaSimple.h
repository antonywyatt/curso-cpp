// ListaSimple.h
#ifndef LISTASIMPLE_H
#define LISTASIMPLE_H
#include <iostream>

using namespace std;

struct Nodo {
    int dato;
    Nodo* siguiente;
};

class ListaSimple {
public:
    ListaSimple();
    ~ListaSimple();
    void agregar(int valor);
    void eliminar(int valor);
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

void ListaSimple::agregar(int valor) {
    Nodo* nuevoNodo = new Nodo{valor, nullptr};
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

void ListaSimple::eliminar(int valor) {
    if (!cabeza) {
        return; // Lista vacía, no se puede eliminar
    }

    if (cabeza->dato == valor) {
        Nodo* nodoEliminar = cabeza;
        cabeza = cabeza->siguiente;
        delete nodoEliminar;
    } else {
        Nodo* actual = cabeza;
        while (actual->siguiente && actual->siguiente->dato != valor) {
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
    while (actual) {
        cout << actual->dato << " ";
        actual = actual->siguiente;
    }
}