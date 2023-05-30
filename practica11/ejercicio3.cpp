#include <iostream>
using namespace std;
struct nodo
{
  int nro;
  struct nodo *sgte;
};

struct cola
{
  nodo *delante;
  nodo *atras;
};

void mostrarCola(struct cola q);
void encolar(struct cola &q, int valor);
int desencolar(struct cola &q);
void eliminarCola(struct cola &q);

int main()
{
    struct cola q;
    char opc;
    int numero, menu;

    q.delante = NULL;
    q.atras = NULL;


    do{
        cout << "*******COLAS******" << endl;
        cout << "======== MENU =========="<< endl;
        cout << "1. Insertar elementos en la cola" << endl;
        cout << "2. Mostrar elementos de la cola" << endl;
        cout << "3. Eliminar elementos de la cola" << endl;
        cout << "4. Salir" << endl;
        cout << "=========================" << endl;
        cout << "Ingrese una opcion: ";
        cin >> menu;

        switch (menu)
        {
        case 1:
            char seguir; // con opcion de N y S
            do{
                cout << "Ingrese un numero: ";
                cin >> numero;
                encolar(q, numero);
                cout << "Desea ingresar otro numero? (S/N): ";
                cin >> seguir;
            } while (seguir == 'S' || seguir == 's');

            break;
        case 2:
            cout << "Mostrando elementos de la cola: " << endl;
            mostrarCola(q);
            break;
        case 3:
            cout << "Eliminando elementos de la cola: " << endl;
            eliminarCola(q);
            break;
        case 4: 
            cout << "Saliendo del programa" << endl;
            break;
        default:
            cout << "Opcion no valida" << endl;
            break;
        }
    }while(menu != 4);

    return 0;
}
// Funcion para insertar elementos en una cola
void encolar(struct cola &q, int valor){
    struct nodo *aux = new (struct nodo);
    aux->nro = valor;
    aux->sgte = NULL;
    if (q.delante == NULL)
        q.delante = aux; // encola el primero elemento
    else
        (q.atras)->sgte = aux;
    q.atras = aux; // puntero que siempre apunta al ultimo elemento
}

// Funcion para retirar elementos de una cola
int desencolar(struct cola &q){
    int num;
    struct nodo *aux;
    aux = q.delante; // aux apunta al inicio de la cola
    num = aux->nro;
    q.delante = (q.delante)->sgte;
    delete (aux); // libera memoria a donde apuntaba aux
    return num;
}

void mostrarCola(struct cola q){
    struct nodo *aux;
    aux = q.delante;
    while (aux != NULL)
    {
        cout << aux->nro << " -> ";
        aux = aux->sgte;
    }
    cout << endl;
}

void eliminarCola(struct cola &q){
    struct nodo *aux;
    while (q.delante != NULL)
    {
        aux = q.delante;
        cout << "Elemento " << aux->nro << " eliminado" << endl;
        q.delante = aux->sgte;
        delete (aux);
    }
    cout << "La cola esta vacia" << endl;
    q.delante = NULL;
    q.atras = NULL;
}