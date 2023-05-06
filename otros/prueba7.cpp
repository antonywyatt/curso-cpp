#include<iostream>

using namespace std;

int main(){

    // Declaracion de variables
    char categoria, genero;
    float montoBase, montoDescuento, montoPagar, descuento;
    int cantidadClientes = 0, cantidadClientesMasculino = 0, opcion;
    float totalMontosPagar = 0, totalMontosPagarFemenino = 0;

    // Proceso
    do{
        cout << "------- MENU --------" << endl;
        cout << "1. Procesar." << endl;
        cout << "2. Reportar." << endl;
        cout << "3. Salir." << endl;
        cout << "---------------------" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch(opcion){
            case 1:
                cout << "Ingrese la categoria del proyecto: ";
                cin >> categoria;
                cout << "Ingrese el monto base: ";
                cin >> montoBase;
                cout << "Ingrese el genero del cliente: ";
                cin >> genero;

                switch(categoria){
                    case 'V':
                    case 'v':
                        cout << "Vivienda" << endl;
                        descuento = 0.08;
                        break;
                    case 'R':
                    case 'r':
                        cout << "Recreativo" << endl;
                        descuento = 0.10;
                        break;
                    case 'P':
                    case 'p':
                        cout << "Piscina" << endl;
                        descuento = 0.13;
                        break;
                    case 'A':
                    case 'a':
                        cout << "Auditorio" << endl;
                        descuento = 0.20;
                        break;
                    case 'E':
                    case 'e':
                        cout << "Edificio" << endl;
                        descuento = 0.25;
                        break;
                    default:
                        cout << "Categoria no valida" << endl;
                        descuento = 0;
                        break;
                }

                montoDescuento = montoBase * descuento;
                montoPagar = montoBase - montoDescuento;

                cout << "Monto a pagar: " << montoPagar << endl;

                cantidadClientes++;
                totalMontosPagar += montoPagar;

                if(genero == 'M' || genero == 'm'){
                    cantidadClientesMasculino++;
                }else if(genero == 'F' || genero == 'f'){
                    totalMontosPagarFemenino += montoPagar;
                }

                break;
            case 2:
                cout << "==================== REPORTE ====================" << endl;
                cout << "Cantidad total de clientes: " << cantidadClientes << endl;
                cout << "Cantidad de clientes masculino: " << cantidadClientesMasculino << endl;
                cout << "Total acumulado de montos a pagar: " << totalMontosPagar << endl;
                cout << "Total acumulado de montos a pagar de clientes femenino: " << totalMontosPagarFemenino << endl;
                break;
            case 3:
                cout << "Gracias por usar el programa" << endl;
                break;
            default:
                cout << "Opcion no valida" << endl;
                break;
        }
    }while(opcion != 3);

    return 0;
}