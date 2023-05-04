#include <iostream>
#include <string>

using namespace std;

int main() {
    string mensaje;
    cout << "Ingrese el mensaje cifrado: ";
    getline(cin, mensaje);

    // Convertir mensaje a mayuscula
    for (int i = 0; i < mensaje.length(); i++) {
        mensaje[i] = toupper(mensaje[i]);
    }

    // Descifrar el mensaje
    for (int i = 0; i < mensaje.length(); i++) {
        if (mensaje[i] >= 'A' && mensaje[i] <= 'Y') {
            mensaje[i] = mensaje[i] + 1;
        } else if (mensaje[i] == 'Z') {
            mensaje[i] = 'A';
        } else if (mensaje[i] >= '0' && mensaje[i] <= '8') {
            mensaje[i] = mensaje[i] + 1;
        } else if (mensaje[i] == '9') {
            mensaje[i] = '0';
        }
    }

    cout << "El mensaje descifrado es: " << mensaje << endl;

    return 0;
}
