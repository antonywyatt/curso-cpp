#include <iostream>

using namespace std;

struct nodo{
	int  nro;
	struct nodo *sgte;
};

struct cola{
	nodo *delante;
    nodo *atras;
};

struct cola q;

void encolar (int valor);

int main(){
	q.delante = NULL;
	q.atras = NULL;
	cout << "Ingresamos dato en a cola (Encolar)"<<endl;
	encolar(10);
	encolar(34);
	encolar(12);
	encolar(65);
	encolar(-5);
	cout<<"Primer elemento en ingresar a la cola "<<q.delante->nro <<endl;
	cout<<"Ultimo elemento en ingresar a la cola "<<q.atras->nro <<endl;
	return 0;	
}

void encolar(int valor){
	struct nodo*aux = new (struct nodo);
	aux->nro = valor;
	aux->sgte = NULL;
	
	if (q.delante ==NULL)
	    q.delante = aux;
    else
        (q.atras)->sgte =aux;
    q.atras = aux;
}
