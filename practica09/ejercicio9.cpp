#include <iostream>
#include <string.h>
using namespace std;

struct nodoLibro
{
    char titulo[50];
    char autor[50];
    int anho;
    struct nodoLibro *sig;
};

struct tListaLibros
{
    nodoLibro *primero;
};

void menu();
void regLibro();
void listarLibros();

tListaLibros *lista = NULL;
int main()
{
    setlocale(LC_CTYPE, "Spanish");
    lista = new tListaLibros();
    lista->primero = NULL;
    menu();
    system("pause");
    return 0;
}
void menu()
{
    int op;
    do
    {
        cout << "LIBRERIA EL SABIO" << endl;
        cout << "1.Añadir libro" << endl;
        cout << "2.Mostrar libros" << endl;
        cout << "3.Salir" << endl;
        cout << "Ingrese una opcion" << endl;
        cin >> op;
        switch (op)
        {
        case 1:
            cout << "Registrar libro" << endl;

            regLibro();
            break;
        case 2:
            cout << "Libros registrados:" << endl
                 << endl;
            listarLibros();
            break;
        case 3:
            cout << "Vuelva pronto..." << endl;
            break;
        }
        system("pause");
        system("cls");
    } while (op != 3);
}
// REGISTRO DE LIBROS
void regLibro()
{
    int an;
    char tit[50];
    char aut[50];
    // INGRESAR DATOS
    cout << "Ingrese año de publicacion del libro : ";
    cin >> an;
    cout << "Ingrese título del libro: ";
    fflush(stdin); // LIBERA EL BUFFER/ESPACIO DE MEMORIA
    cin.getline(tit, 50, '\n');
    cout << "Ingrese autor: ";
    fflush(stdin);
    cin.getline(aut, 50, '\n');
    nodoLibro *nuevo = new nodoLibro();
    // INGRESANDO LOS DATOS A LA LISTA
    nuevo->anho = an;
    strcpy(nuevo->autor, aut); // COPIAMOS LO ESCRITO EN LA ESTRUCTURA nodoLibro
    strcpy(nuevo->titulo, tit);
    // APUNTAMOS EL SIGUIENTE NODO DE NUEVO A NULL
    nuevo->sig = NULL;
    if (lista->primero == NULL)
    {
        lista->primero = nuevo; // SI LA LISTA ESTA VACIA lista->primero APUNTA A NUEVO;
    }
    else
    {
        nodoLibro *aux = lista->primero; //
        while (aux->sig != NULL)
        {
            aux = aux->sig; // PARA QUE AUXILIAR APUNTE A NULL
        }
        aux->sig = nuevo; // LE ASIGNAMOS A NUEVO QUE ES UN NODO QUE YA CREAMOS
    }
}
void listarLibros()
{
    int i = 1;
    if (lista->primero == NULL)
    { // EN CASO DE QUE LA LISTE ESTE VACIA
        cout << "Lista vacia" << endl;
    }
    else
    { // SI LA LISTA NO ESTA VACIA CREAMOS UN AUXILIAR Y LO IGUALAMOS AL PRIMER NODO
        nodoLibro *aux = lista->primero;
        cout << " ____________________________________________________________________" << endl;
        cout << "| TITULO / AÑO / AUTOR |" << endl;
        cout << "|_______________________/_____________________/______________________|" << endl;
        do
        {
            cout << "Libro " << i << ": " << aux->titulo << " / " << aux->anho << " / " << aux->autor << endl;
            aux = aux->sig;    // PARA IR AL SIGUIENTE NODO
            i++;               // CONTADOR DE LIBROS
        } while (aux != NULL); // HACER HASTA QUE AUX SEA NULL
    }
}
