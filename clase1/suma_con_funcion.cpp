#include<iostream>
#include<conio.h>

using namespace std;

int suma(int a, int b){
	return a + b;
}

int main(int argc, char** argv){
	int a;
	int b;
	int suma;
	
	cout<<"PROGRAMA SUMA SIN FUNCIONES"<<endl;
	cout<<"============================"<<endl;
	cout<<"Ingrese el primer valor: "<<endl;
	cin>>a;
	cout<<"Ingrese el segundo valor: "<<endl;
	cin>>b;
	cout<<"La suma es: "<< suma(a, b) << endl;
}

/**
int suma(int x, int y){
	int resp;
	resp = x + y;
	return resp;
}
*/
