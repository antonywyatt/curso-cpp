// ListaCircularSimple.h
#include <iostream>
#ifndef LISTACIRCULARSIMPLE_H
#define LISTACIRCULARSIMPLE_H

struct Nodo {
    int dato;
    Nodo* siguiente;
};

class ListaCircularSimple {
public:
    ListaCircularSimple();
    ~ListaCircularSimple();
    void agregar(int valor);
    void eliminar(int valor);
    void imprimir();
private:
    Nodo* cabeza;
};

#endif

ListaCircularSimple::ListaCircularSimple() : cabeza(nullptr) {}

ListaCircularSimple::~ListaCircularSimple() {
    if (!cabeza) {
        return;
    }
    Nodo* actual = cabeza;
    Nodo* siguiente = cabeza->siguiente;
    while (siguiente != cabeza) {
        actual = siguiente;
        siguiente = siguiente->siguiente;
        delete actual;
    }
    delete cabeza;
}

void ListaCircularSimple::agregar(int valor) {
    Nodo* nuevoNodo = new Nodo{valor, nullptr};
    if (!cabeza) {
        cabeza = nuevoNodo;
        cabeza->siguiente = cabeza;
    } else {
        Nodo* actual = cabeza;
        while (actual->siguiente != cabeza) {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevoNodo;
        nuevoNodo->siguiente = cabeza;
    }
}

void ListaCircularSimple::eliminar(int valor) {
    if (!cabeza) {
        return; // Lista vacía, no se puede eliminar
    }

    if (cabeza->dato == valor) {
        Nodo* nodoEliminar = cabeza;
        if (cabeza->siguiente == cabeza) {
            cabeza = nullptr;
        } else {
            cabeza = cabeza->siguiente;
            Nodo* actual = cabeza;
            while (actual->siguiente != nodoEliminar) {
                actual = actual->siguiente;
            }
            actual->siguiente = cabeza;
        }
        delete nodoEliminar;
    } else {
        Nodo* actual = cabeza;
        while (actual->siguiente != cabeza && actual->siguiente->dato != valor) {
            actual = actual->siguiente;
        }
        if (actual->siguiente != cabeza) {
            Nodo* nodoEliminar = actual->siguiente;
            actual->siguiente = nodoEliminar->siguiente;
            delete nodoEliminar;
        }
    }
}

void ListaCircularSimple::imprimir() {
    if (!cabeza) {
        return;
    }
    Nodo* actual = cabeza;
    do {
        std::cout << actual->dato << " ";
        actual = actual->siguiente;
    } while (actual != cabeza);
    std::cout << std::endl;
}