#include<iostream>
#include<vector>

using namespace std;

const int NUM_SUCURSALES = 3;
const int NUM_MESES = 12;

void ventasMensuales(const vector<vector<int> >& ventas) {
    for (int mes = 0; mes < NUM_MESES; ++mes) {
        int totalMensual = 0;
        for (int sucursal = 0; sucursal < NUM_SUCURSALES; ++sucursal) {
            totalMensual += ventas[sucursal][mes];
        }
        cout << "Ventas en el mes " << mes + 1 << ": " << totalMensual << endl;
    }
}

void totalVentas(const vector<vector<int> >& ventas) {
    int total = 0;
    for (int sucursal = 0; sucursal < NUM_SUCURSALES; ++sucursal) {
        for (int mes = 0; mes < NUM_MESES; ++mes) {
            total += ventas[sucursal][mes];
        }
    }
    cout << "Total de ventas de todas las sucursales: " << total << endl;
}

void sucursalMasVentasJulio(const vector<vector<int> >& ventas) {
    int maxVentas = 0;
    int sucursalMaxVentas = 0;

    for (int sucursal = 0; sucursal < NUM_SUCURSALES; ++sucursal) {
        if (ventas[sucursal][6] > maxVentas) {
            maxVentas = ventas[sucursal][6];
            sucursalMaxVentas = sucursal;
        }
    }

    cout << "Sucursal que vendió más en julio: Sucursal " << sucursalMaxVentas + 1 << endl;
}

void mesMayorVentas(const vector<vector<int> >& ventas) {
    int maxVentas = 0;
    int mesMaxVentas = 0;

    for (int mes = 0; mes < NUM_MESES; ++mes) {
        int totalMes = 0;
        for (int sucursal = 0; sucursal < NUM_SUCURSALES; ++sucursal) {
            totalMes += ventas[sucursal][mes];
        }

        if (totalMes > maxVentas) {
            maxVentas = totalMes;
            mesMaxVentas = mes;
        }
    }
    
    string meses[] = {"enero", "febrero", "marzo", "abril", "mayo", "junio", "julio",
                      "agosto", "septiembre", "octubre", "noviembre", "diciembre"};

    cout << "Mes con la mayor cantidad de ventas: Mes " << meses[mesMaxVentas] << endl;
}

int main() {
    vector<vector<int> > ventas(NUM_SUCURSALES, vector<int>(NUM_MESES, 0));

    for (int sucursal = 0; sucursal < NUM_SUCURSALES; ++sucursal) {
        cout << "Ingrese las ventas para la Sucursal " << sucursal + 1 << endl;
        for (int mes = 0; mes < NUM_MESES; ++mes) {
            cout << "Mes " << mes + 1 << ": ";
            cin >> ventas[sucursal][mes];
        }
    }

    int opcion;

    do {
        cout << "\n--- Menú ---\n";
        cout << "1. Ventas mensuales de la empresa\n";
        cout << "2. Total de ventas de todas las sucursales\n";
        cout << "3. Sucursal que vendió más en julio\n";
        cout << "4. Mes con la mayor cantidad de ventas\n";
        cout << "0. Salir\n";
        cout << "Ingrese la opción deseada: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                ventasMensuales(ventas);
                break;
            case 2:
                totalVentas(ventas);
                break;
            case 3:
                sucursalMasVentasJulio(ventas);
                break;
            case 4:
                mesMayorVentas(ventas);
                break;
            case 0:
                cout << "¡Hasta luego!\n";
                break;
            default:
                cout << "Opción no válida. Inténtalo de nuevo.\n";
        }

    } while (opcion != 0);

    return 0;
}
