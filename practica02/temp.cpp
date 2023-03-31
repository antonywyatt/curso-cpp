#include<iostream>

using namespace std;

int main(){
    float sueldo_base, importe_ventas, comision, sueldo_neto;
    cout<<"Ingrese el sueldo base: ";
    cin>>sueldo_base;
    cout<<"Ingrese el importe de las ventas: ";
    cin>>importe_ventas;
    comision=importe_ventas*0.08;
    sueldo_neto=sueldo_base+comision;
    cout<<"El sueldo neto es: "<<sueldo_neto<<endl;

    return 0;
}