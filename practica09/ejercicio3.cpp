#include <iostream>
using namespace std;

struct Nodo {
    int dato;
    Nodo* siguiente;
};

//declarar funciones
void ingresarElemento(Nodo*& lista, int elemento);
void mostrarElementos(Nodo* lista);
void buscarElemento(Nodo* lista, int elemento);

int main() {
    Nodo* lista = nullptr;
    char opcion, rpta;
    int elemento;

    do {
        cout << "------------------------" << endl;
        cout << "MENU DE LISTAS" << endl;
        cout << "------------------------" << endl;
        cout << "1. Ingresar elementos" << endl;
        cout << "2. Mostrar elementos" << endl;
        cout << "3. Buscar elemento" << endl;
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
                    ingresarElemento(lista, elemento);
                    do{
                        cout<<"Desea agregar otro elemento a la lista? (S/N): ";
                        cin>>rpta;
                        rpta = toupper(rpta);
                    }while(rpta!='s' && rpta!='S' && rpta!='n' && rpta!='N');
                }while(rpta=='s' || rpta=='S');
                break;
            case '2':
                mostrarElementos(lista);
                break;
            case '3':
                cout << "Ingrese el elemento a buscar: ";
                cin >> elemento;
                buscarElemento(lista, elemento);
                break;
            case '8':
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opción inválida. Intente de nuevo." << endl;
        }
    } while (opcion != '8');

    return 0;
}

//desarrollo de funciones
void ingresarElemento(Nodo*& lista, int elemento) {
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

void mostrarElementos(Nodo* lista) {
    Nodo* actual = lista;
    if (actual == nullptr) {
        cout << "La lista esta vacía." << endl;
    } else {
        cout << "Elementos de la lista:" << endl;
        while (actual != nullptr) {
            cout << actual->dato << " - ";
            actual = actual->siguiente;
        }
        cout << endl;
    }
}

void buscarElemento(Nodo* lista, int elemento) {
    bool encontrado = false;
    Nodo* actual = lista;
    while (actual != nullptr) {
        if (actual->dato == elemento) {
            encontrado = true;
        }
        actual = actual->siguiente;
    }
    if(encontrado){
        cout<<"El elemento "<<elemento<<" se encuentra en la lista."<<endl;
    }else{
        cout<<"El elemento "<<elemento<<" no se encuentra en la lista."<<endl;
    }
}