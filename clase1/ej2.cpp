#include<iostream> 
#include<conio.h> 
#include<math.h>
using namespace std;

int function(int x){
    float y;
    y = pow(x,3) + 4*x + 10;
    return y;
}

int main(){
    float y, x;
     
    cout << "Ingrese el valor de x: ";
    cin >> x;
    y = function(x);
    cout << "El resultado es: " << y << endl;
}