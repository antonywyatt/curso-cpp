#include<iostream>
#include<conio.h>

using namespace std;

int main(){
	int x, y;
	int *p1, *p2;
	x = -42;
	cout<<"El valor de x es: "<< x <<endl;
	y = 163;
	cout<<"El valor de y es: "<< y <<endl;
	p1 = &x;
	cout<<"El valor de p1 = &x es: " << p1 <<endl;
	p2 = &y;
	cout<<"El valor de p2 = &y es: " << p2 <<endl;
	*p1 = 17;
	cout<<"El valor asignado a *p1 es: " << *p1 << " | Direccion: "<< p1 <<endl;
	*p2 = x + 5; 
	cout<<"El valor asignado a *p2 es: " << *p2 << " | Direccion: "<< p2 <<endl;
	cout<<"El nuevo valor de x es: "<< x <<endl;
	cout<<"El nuevo valor de y es: "<< y <<endl;
	
	*p1 = *p2;
	cout<<"El nuevo valor del puntero *p1 = *p2 es: "<< *p1 <<endl;
	p1 = p2;
	cout<<"El nuevo valor de la direccion p1 = p2 es: "<< p1 <<endl;
    	cout<<"Limpiando direcciones..."<<endl;
	p1 = NULL;
	p2 = NULL;
	cout<<"El nuevo valor de p1 es: "<< p1 <<endl;
	cout<<"El nuevo valor de p2 es: "<< p2 <<endl;
}
