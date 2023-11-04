// Cola.h
#include <iostream>
#ifndef COLA_H
#define COLA_H

struct Nodo {
    int dato;
    Nodo* siguiente;
};

class Cola {
public:
    Cola();
    ~Cola();
    void push(int valor);
    void pop();
    int front();
    bool vacia();
private:
    Nodo* frente;
    Nodo* final;
};

#endif

Cola::Cola() : frente(nullptr), final(nullptr) {}

Cola::~Cola() {
    while (!vacia()) {
        pop();
    }
}

void Cola::push(int valor) {
    Nodo* nuevoNodo = new Nodo{valor, nullptr};
    if (vacia()) {
        frente = nuevoNodo;
    } else {
        final->siguiente = nuevoNodo;
    }
    final = nuevoNodo;
}

void Cola::pop() {
    if (vacia()) {
        return;
    }

    Nodo* nodoEliminar = frente;
    frente = frente->siguiente;
    delete nodoEliminar;
}

int Cola::front() {
    if (vacia()) {
        return -1;
    }
    return frente->dato;
}

bool Cola::vacia() {
    return frente == nullptr;
}