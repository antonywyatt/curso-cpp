#include <iostream>
using namespace std;

struct Nodo {
    int dato;
    Nodo* siguiente;
};

//variable global
Nodo* lista = nullptr;

//declarar funciones
void ingresarElemento(int elemento);
void mostrarElementos();

int main() {
    char opcion, rpta;
    int elemento;

    do {
        cout << "------------------------" << endl;
        cout << "MENU DE LISTAS" << endl;
        cout << "------------------------" << endl;
        cout << "1. Ingresar elementos" << endl;
        cout << "2. Mostrar elementos" << endl;
        cout << "8. Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case '1':
                do{
                    cout<<endl;
                    cout<<"Ingrese un numero que desee agregar a la lista: ",
                    cin>>elemento;
                    cout<<endl;
                    ingresarElemento(elemento);
                    do{
                        cout<<"Desea agregar otro elemento a la lista? (S/N): ";
                        cin>>rpta;
                        rpta = toupper(rpta);
                    }while(rpta!='s' && rpta!='S' && rpta!='n' && rpta!='N');
                }while(rpta=='s' || rpta=='S');
                break;
            case '2':
                mostrarElementos();
                break;
            case '8':
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opcion invalida. Intente de nuevo." << endl;
        }
    } while (opcion != '8');

    return 0;
}

//desarrollo de funciones
void ingresarElemento(int elemento) {
    Nodo* nuevoNodo = new Nodo();
    nuevoNodo->dato = elemento;
    nuevoNodo->siguiente = nullptr;

    if (lista == nullptr) {
        lista = nuevoNodo;
    } else {
        Nodo* actual = lista;
        while (actual->siguiente != nullptr) {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevoNodo;
    }
}

void mostrarElementos() {
    Nodo* actual = lista;
    if (actual == nullptr) {
        cout << "La lista esta vacia." << endl;
    } else {
        cout << "Elementos de la lista:" << endl;
        while (actual != nullptr) {
            cout << actual->dato << " - ";
            actual = actual->siguiente;
        }
        cout << endl;
    }
}