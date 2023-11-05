#include <iostream>
#include <string>

struct Nodo {
    std::string dato;
    Nodo* siguiente;
};

class Pila {
public:
    Pila();
    ~Pila();
    void push(const std::string& valor);
    void pop();
    std::string top();
    bool vacia();
private:
    Nodo* tope;
};

Pila::Pila() : tope(nullptr) {}

Pila::~Pila() {
    while (!vacia()) {
        pop();
    }
}

void Pila::push(const std::string& valor) {
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

std::string Pila::top() {
    if (vacia()) {
        return "";
    }
    return tope->dato;
}

bool Pila::vacia() {
    return tope == nullptr;
}
