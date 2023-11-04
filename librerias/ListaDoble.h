// ListaDoble.h
#include <iostream>
#ifndef LISTADOBLE_H
#define LISTADOBLE_H

using namespace std;

struct Nodo {
    int dato;
    Nodo* siguiente;
    Nodo* anterior;
};

class ListaDoble {
public:
    ListaDoble();
    ~ListaDoble();
    void agregar(int valor);
    void eliminar(int valor);
    void imprimir();
private:
    Nodo* cabeza;
    Nodo* cola;
};

#endif

ListaDoble::ListaDoble() : cabeza(nullptr), cola(nullptr) {}

ListaDoble::~ListaDoble() {
    while (cabeza) {
        Nodo* nodoEliminar = cabeza;
        cabeza = cabeza->siguiente;
        delete nodoEliminar;
    }
}

void ListaDoble::agregar(int valor) {
    Nodo* nuevoNodo = new Nodo{valor, nullptr, nullptr};
    if (!cabeza) {
        cabeza = nuevoNodo;
        cola = nuevoNodo;
    } else {
        nuevoNodo->anterior = cola;
        cola->siguiente = nuevoNodo;
        cola = nuevoNodo;
    }
}

void ListaDoble::eliminar(int valor) {
    if (!cabeza) {
        return; // Lista vacía, no se puede eliminar
    }

    if (cabeza->dato == valor) {
        Nodo* nodoEliminar = cabeza;
        cabeza = cabeza->siguiente;
        if (cabeza) {
            cabeza->anterior = nullptr;
        }
        delete nodoEliminar;
    } else if (cola->dato == valor) {
        Nodo* nodoEliminar = cola;
        cola = cola->anterior;
        if (cola) {
            cola->siguiente = nullptr;
        }
        delete nodoEliminar;
    } else {
        Nodo* actual = cabeza;
        while (actual->siguiente && actual->siguiente->dato != valor) {
            actual = actual->siguiente;
        }
        if (actual->siguiente) {
            Nodo* nodoEliminar = actual->siguiente;
            actual->siguiente = nodoEliminar->siguiente;
            if (actual->siguiente) {
                actual->siguiente->anterior = actual;
            }
            delete nodoEliminar;
        }
    }
}

void ListaDoble::imprimir() {
    Nodo* actual = cabeza;
    while (actual) {
        cout << actual->dato << " ";
        actual = actual->siguiente;
    }
    cout << endl;
}