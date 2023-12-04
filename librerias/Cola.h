// Cola.h
#include <iostream>
#ifndef COLA_H
#define COLA_H

using namespace std;

struct Nodo {
    int dato;
    string valor1;
    string valor2;
    string valor3;
    Nodo* siguiente;
};

class Cola {
public:
    Cola();
    ~Cola();
    void push(Nodo valor);
    void pop();
    Nodo front();
    bool vacia();
private:
    Nodo* frente;
    Nodo* final;
};

#endif

Cola::Cola() : frente(NULL), final(NULL) {}

Cola::~Cola() {
    while (!vacia()) {
        pop();
    }
}

void Cola::push(Nodo valor) {
    Nodo* nuevoNodo = new Nodo;
    nuevoNodo->dato = valor.dato;
    nuevoNodo->valor1 = valor.valor1;
    nuevoNodo->valor2 = valor.valor2;
    nuevoNodo->valor3 = valor.valor3;
    nuevoNodo->siguiente = NULL;
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
    Nodo* temp = frente;
    frente = frente->siguiente;
    delete temp;
}

Nodo Cola::front() {
    if (vacia()) {
        return Nodo();
    }
    //retornar toda la estructura
    return *frente;
}

bool Cola::vacia() {
    return frente == NULL;
}
