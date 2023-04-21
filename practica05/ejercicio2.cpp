#include <iostream>
#define MAX 100

using namespace std;

struct sCliente{
    string nombre;
    char categoria;
    int edad;
    float monto_c;
    float monto_d;
    float monto_p;
};

sCliente agregarCliente();
void mostrarGeneralCliente(sCliente clientes[MAX], int total_cliente);

int main(){

    int total_cliente = 0, i;
    sCliente clientes[MAX];

    cout << "Ingrese el total de cliente: ";
    cin >> total_cliente;

    for(i = 0; i < total_cliente; i++){
        clientes[i] = agregarCliente();
    }

    mostrarGeneralCliente(clientes, total_cliente);

    return 0;
}

sCliente agregarCliente(){
    sCliente cliente;
    cliente.monto_d = 0;
    cliente.monto_p = 0;

    cout << "Ingrese el nombre del cliente: " ;
    cin >> cliente.nombre;
    cout << "Ingrese la categoria del cliente (A/B/C): ";
    cin >> cliente.categoria;
    cout << "Ingrese la edad: ";
    cin >> cliente.edad;
    cout << "Ingrese el monto de compra: ";
    cin >> cliente.monto_c;
    cout << "==============================================" << endl;

    if(cliente.categoria == 'A'){
        cliente.monto_d = cliente.monto_c * 0.10;
    }else if(cliente.categoria == 'B'){
        cliente.monto_d = cliente.monto_c * 0.20;
    }else if(cliente.categoria == 'C'){
        cliente.monto_d = cliente.monto_c * 0.30;
    }

    cliente.monto_p = cliente.monto_c - cliente.monto_d;

    return cliente;
}

void mostrarGeneralCliente(sCliente clientes[MAX], int total_cliente){
    
    int cant_a = 0;
    int total_p_a = 0;
    int cant_A_mayor25 = 0;
    int cant_A_menor25 = 0;

    cout << "Nombre \t\tCategoria\tEdad\tMonto de Compra\t\tMonto de Descuento\t\tMonto a Pagar" << endl;
    for(int i = 0; i < total_cliente; i++){
        cout << clientes[i].nombre << "\t\t" << clientes[i].categoria << "\t" << clientes[i].edad << "\t" << clientes[i].monto_c << "\t\t" << clientes[i].monto_d << "\t\t" << clientes[i].monto_p << endl;
        
        if(clientes[i].categoria == 'A'){
            cant_a++;
            total_p_a += clientes[i].monto_p;
        }

        if(clientes[i].categoria == 'A' && clientes[i].edad > 25){
            cant_A_mayor25++;
        }

        if(clientes[i].categoria == 'A' && clientes[i].edad <= 25){
            cant_A_menor25 += clientes[i].monto_p;
        }
    }

    cout << "Cantidad de clientes de categoria A: " << cant_a << endl;
    cout << "Cantidad de clientes de categoría A con edades mayores a 25: " << cant_A_mayor25 << endl;
    cout << "Total de monto a pagar de clientes de categoría A: " << total_p_a << endl;
    cout << "Total de monto a pagar de clientes de categoría A con edades menores o iguales a 25: " << cant_A_menor25 << endl;

    cout << "==============================================";
}