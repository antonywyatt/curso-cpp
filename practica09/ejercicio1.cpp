#include <iostream>
using namespace std;

struct Nodo {
	int dato;
	Nodo *sig;
};

int main(){
	
	Nodo* primerNodo = new Nodo();

    Nodo* nodo1 = new Nodo();
	Nodo* nodo2 = new Nodo();
	Nodo* nodo3 = new Nodo();
	
	primerNodo->sig = nodo1;
	primerNodo->dato =10;
	
	nodo1->sig =  nodo2;
	nodo1->dato = 5;
	
	nodo2->sig =  nodo3;
	nodo2->dato = 2;
	
	nodo3->sig =  NULL;
	nodo3->dato = 15;
	
	cout<<" _______________________primerNodo->sig=nodo1_____________________________________________________"<<endl;
	cout<<"|           |           |                     |        |     |    |        |     |     |      |     |"<<endl;
	cout<<"|PrimerNodo |  sig      |         ->          |  nodo1 | sig | -> |  nodo2 | sig | ->  | nodo3| sig |"<<endl;
	cout<<"|__________ |___________|                     |________|_____|    |________|_____|     |______|_____|"<<endl;
	
	cout<<"IMPRIMIENDO VALORES"<<endl;
	Nodo *mostrar = primerNodo;
	while(mostrar!=NULL){
		cout<<mostrar->dato<<"->";
		mostrar = mostrar->sig;
	}
	cout<<endl;
	system("pause");
	return 0; 
}