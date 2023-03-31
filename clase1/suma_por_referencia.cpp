#include<iostream>
#include<conio.h>

using namespace std;

int suma(int& x, int& y);

int main(){
    int a, b;
    int resultado;

	cout<<"Ingrese el primer valor: "<<endl;
	cin>>a;
	cout<<"Ingrese el segundo valor: "<<endl;
	cin>>b;
	resultado = suma(a, b);
	cout<<"La suma es: "<< resultado << endl;
	cout<<"El valor de A es: "<< a << endl;
	cout<<"El valor de B es: "<< b << endl;
}

int suma(int& x, int& y){
    int res;
    res = x + y;
    x = -7;
    y = -3;
    return res;
}
