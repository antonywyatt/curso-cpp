// Pila.h
#ifndef PILA_H
#define PILA_H
#include <iostream>

struct Nodo {
    int dato;
    Nodo* siguiente;
};

class Pila {
public:
    Pila();
    ~Pila();
    void push(int valor);
    void pop();
    int top();
    bool vacia();
private:
    Nodo* tope;
};

#endif

Pila::Pila() : tope(nullptr) {}

Pila::~Pila() {
    while (!vacia()) {
        pop();
    }
}

void Pila::push(int valor) {
    Nodo* nuevoNodo = new Nodo{valor, tope};
    tope = nuevoNodo;
}

void Pila::pop() {
    if (vacia()) {
        return;
    }

    Nodo* nodoEliminar = tope;
    tope = tope->siguiente;
    delete nodoEliminar;
}

int Pila::top() {
    if (vacia()) {
        return -1;
    }
    return tope->dato;
}

bool Pila::vacia() {
    return tope == nullptr;
}