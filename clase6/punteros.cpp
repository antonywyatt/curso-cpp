#include <iostream>

using namespace std;

struct Cliente{
    string nombre;
    char genero;
    int edad;
};

Cliente registrarCliente(Cliente *cliente);
void listarCliente(Cliente *cliente);

int main(){
    // Declaracion de variables
    int n;
    Cliente *clientes, aClientes[100];

    // Ingreso de datos
    cout << "Ingrese la cantidad de clientes: ";
    cin >> n;

    //Registrar los datos de los clientes
    //inicializar puntero en 0
    clientes = &aClientes[0];

    for(int i = 0; i < n; i++){
        //usar modulo para registrar los datos de los clientes
        aClientes[i] = registrarCliente(clientes);
        clientes++; 
    }

    //listar
    clientes = &aClientes[0];
    
    cout<< "Lista de clientes" << endl;
    for(int i = 0; i < n; i++){
        //usar modulo para listar los datos de los clientes
        listarCliente(clientes);
        clientes++;
    }


}

Cliente registrarCliente(Cliente *cliente){
    cout << "Ingrese el nombre del cliente: ";
    cin >> cliente->nombre;
    cout << "Ingrese el genero del cliente: ";
    cin >> cliente->genero;
    cout << "Ingrese la edad del cliente: ";
    cin >> cliente->edad;
    return *cliente;
}

void listarCliente(Cliente *cliente){
    cout << "Nombre: " << cliente->nombre << endl;
    cout << "Genero: " << cliente->genero << endl;
    cout << "Edad: " << cliente->edad << endl;
    cout << "--------------------------" << endl;
}