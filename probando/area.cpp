#include<iostream> 
#include<conio.h> 
#include<math.h>
using namespace std;

int main(){
    float area, radio;

    cout << "Ingrese el radio del circulo: ";
    cin >> radio;

    area = 3.1416 * pow(radio,2);

    cout << "El area del circulo es " << area << endl;
}