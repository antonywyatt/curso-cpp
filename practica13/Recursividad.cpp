#include<iostream>

using namespace std;

double factorial(int n){
	if(n == 0)
	return 1;
	else
	return n * factorial(n-1);
}

double potencia(int b, int e){ //base - potencia
	if(e == 0)
	return 1;
	else
	return b * potencia(b, e-1);
}

double fibonacci(int n){
	if(n == 0)
	return 0;
	else if(n == 1)
	return 1;
	else
	return fibonacci(n-1) + fibonacci(n-2);
}

double multiplicacion(int a, int b){
	if(b == 0)
	return 0;
	else
	return a + multiplicacion(a, b-1);
}

double division(int a, int b){
	if(a < b)
	return 0;
	else
	return 1 + division(a-b, b);
}