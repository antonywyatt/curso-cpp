#include<iostream> // Utilizaremos cout y cin
#include<conio.h> // interfaces de usuario y limpieza de pantalla
#include<math.h> // operaciones b�sicas
using namespace std;

int operations(int a, int b){
    int suma, resta, multiplicacion;
    float division, raiz, potencia;

    suma = a + b;
    resta = a - b;
    multiplicacion = a * b;
    division = a / b;
    //raiz cuadrada
    raiz = sqrt(suma);
    //potencia
    potencia = pow(a, 3);

    cout << "La suma es: " << suma << endl;
    cout << "La resta es: " << resta << endl;
    cout << "La multiplicacion es: " << multiplicacion << endl;
    cout << "La division es: " << division << endl;
    cout << "La raiz es: " << raiz << endl;
    cout << "El cubo de" << a << "es: " << potencia << endl;
    return 0;
}

int main(){
    int a, b;
    cout << "Ingrese el primer numero: ";
    cin >> a;
    cout << "Ingrese el segundo numero: ";
    cin >> b;
    operations(a, b);
    getch();
    return 0;
}