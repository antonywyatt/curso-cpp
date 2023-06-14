#include<iostream>

using namespace std;

/**
    Elaborar un programa, para una empresa que para cada cliente ofrece un descuento, de acuerdo a la 
    tabla siguiente, y de acuerdo al tipo de producto. Mostrar el monto bruto, el monto de descuento y el 
    monto total a pagar por cliente. Además, mostrar la cantidad de veces que se seleccionó cada producto 
    y el acumulado de los montos totales. Puedes usar librerías de programación, variables globales, menú 
    principal, sub menú, función o procedimiento, con o sin argumentos, según requiera el caso.

    Tipo de Producto	% de Descuento
    [A] Mouse            8%
    [B] Teclado          10%
    [C] Disco Duro       11%
    [D] Monitor          15%
*/

// Variables globales
int cantMouse = 0, cantTeclado = 0, cantDiscoDuro = 0, cantMonitor = 0;
float montoTotal = 0;

int main(){

    // Variables locales
    char tipoProducto;
    float montoBruto, montoDescuento, montoPagar;
    
    //menu
    
    do{
        cout << "Ingrese el tipo de producto: ";
        cin >> tipoProducto;
        cout << "Ingrese el monto bruto: ";
        cin >> montoBruto;

        switch (tipoProducto)
        {
        case 'A':
            montoDescuento = montoBruto * 0.08;
            montoPagar = montoBruto - montoDescuento;
            cantMouse++;
            break;
        case 'B':
            montoDescuento = montoBruto * 0.10;
            montoPagar = montoBruto - montoDescuento;
            cantTeclado++;
            break;
        case 'C':
            montoDescuento = montoBruto * 0.11;
            montoPagar = montoBruto - montoDescuento;
            cantDiscoDuro++;
            break;
        case 'D':
            montoDescuento = montoBruto * 0.15;
            montoPagar = montoBruto - montoDescuento;
            cantMonitor++;
            break;
        default:
            cout << "Tipo de producto no valido" << endl;
            break;
        }

        montoTotal += montoPagar;

        cout << "Monto bruto: " << montoBruto << endl;
        cout << "Monto descuento: " << montoDescuento << endl;
        cout << "Monto a pagar: " << montoPagar << endl;
    }while(tipoProducto != 'X');

    cout << "Cantidad de Mouse: " << cantMouse << endl;
    cout << "Cantidad de Teclado: " << cantTeclado << endl;
    cout << "Cantidad de Disco Duro: " << cantDiscoDuro << endl;
    cout << "Cantidad de Monitor: " << cantMonitor << endl;
    cout << "Monto total: " << montoTotal << endl;

    return 0;
}