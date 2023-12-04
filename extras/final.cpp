#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool verificarBalance(const string& secuencia) {
    stack<char> pila;

    for (size_t i = 0; i < secuencia.length(); ++i) {
        char caracter = secuencia[i];
        if (caracter == '(' || caracter == '[') {
            pila.push(caracter);
        } else if (caracter == ')' || caracter == ']') {
            if (pila.empty()) {
                return false;
            }

            char apertura = pila.top();
            pila.pop();

            if ((caracter == ')' && apertura != '(') || (caracter == ']' && apertura != '[')) {
                return false;
            }
        }
    }

    return pila.empty();
}

int main() {
    string secuencia;
    cout << "Ingrese la secuencia de paréntesis y corchetes (terminando con punto): ";
    getline(cin, secuencia);

    if (verificarBalance(secuencia)) {
        cout << "CIERTO" << endl;
    } else {
        cout << "FALSO" << endl;
    }

    return 0;
}