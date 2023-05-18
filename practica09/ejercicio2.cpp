#include<iostream>
#include<string.h>
using namespace std;

struct nodo{
    int dato;
    nodo *sig;
};

//variable global
nodo *pL=NULL, *nuevo;

//funciones
void insertarLista(nodo* $pL, int num);
void mostrarLista(nodo* pL);

int main(){
    
    nodo *pL, *nuevo;
    int num;
    char rpta;
    cout<<endl<<endl;
    cout<<"------------------------------------"<<endl;
    cout<<"Ingrese datos de a la lista"<<endl;
    cout<<"------------------------------------"<<endl;

    do{
        cout<<endl;
        cout<<"Ingrese un número que desee agregar a la lista: ",
        cin>>num;
        cout<<endl;
        insertarLista(pL, num);
        do{
            cout<<"Desea agregar otro elemento a la lista? (S/N): ";
            cin>>rpta;
            rpta = toupper(rpta);
        }while(rpta!='s' && rpta!='S' && rpta!='n' && rpta!='N');
    }while(rpta=='s' || rpta=='S');

    cout<<endl<<endl;
    cout<<"------------------------------------"<<endl;
    cout<<"Mostrando datos de la lista"<<endl;
    cout<<"------------------------------------"<<endl;
    mostrarLista(pL);
    cout<<endl<<endl;
    system("pause");

    return 0;
}

void insertarLista(nodo* $pL, int num){
    nuevo = new nodo;
    nuevo->dato = num;
    nuevo->sig = pL;
    pL = nuevo;
    cout<<"=> Elemento "<<num<<" insertado correctamente a la lista!"<<endl<<endl;
}

void mostrarLista(nodo* pL){
    while(nuevo!=NULL){
        cout<<nuevo->dato<<"--";
        nuevo = nuevo->sig;
    }
    cout<<endl<<endl;
}