#include <iostream>
#define TOPE 100
using namespace std;
void capturaArreglo (int Arreglo[TOPE],int max, string nombre);
void mostrarArreglo (int Arreglo[TOPE],int max, string nombre);

int main(){
	int A[TOPE], B[TOPE], C[TOPE], i, nro;
	
	do{
		cout << "ingrese la cantidad de elementos [1,"<< TOPE << "]:";
		cin >> nro;
		if(nro >=100 || nro < 0){
			cout << "La cantidad a ingresar debe ser entre 1 y " <<TOPE <<endl;
		}
	}while(nro>=100 || nro < 0);
	
	capturaArreglo(A, nro, "A");
	capturaArreglo(B, nro, "B");
	//SUMAMOS
	for(i = 0; i < nro; i++){
		C[i] = A[i] + B[i];
	}
	//mostramps
	mostrarArreglo(A, nro, "A");
	mostrarArreglo(B, nro, "B");
	cout<<"La suma de los arreglos es: "<< endl;
	mostrarArreglo(C, nro, "C");
	
	return 0;
}
void capturaArreglo (int Arreglo[TOPE],int max, string nombre){
	cout << "Ingrese el arreglo "<< nombre << endl;
	//leemos datos
	for(int i = 0; i < max; i++){
		cout << "Ingrese el elemento ["<<i<<"]: ";
		cin >> Arreglo[i];
	}
}
void mostrarArreglo(int Arreglo[TOPE],int max, string nombre ){
	cout << "El arreglo"<< nombre <<endl;
	for(int i = 0; i < max; i++){
		cout << Arreglo[i] << "\t";
	}
	cout << endl;
}