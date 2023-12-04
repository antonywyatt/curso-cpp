#include<iostream>
#include<string>
#include<sstream>

using namespace std;

template <typename T>
string to_string_custom(const T& value) {
    stringstream ss;
    ss << value;
    return ss.str();
}

string decimalToHexadecimal(int num) {
    if (num == 0) {
        return "0";
    }
    else if (num > 0 && num < 16) {
        const string hexDigits = "0123456789ABCDEF";
        return string(1, hexDigits[num]);
    }
    else {
        return decimalToHexadecimal(num / 16) + decimalToHexadecimal(num % 16);
    }
}

string decimalToBaseB(int num, int base) {
    if (base < 2 || base > 9) {
        return "Base no válida. Ingresa una base entre 2 y 9.";
    }
    if (num == 0) {
        return "0";
    }
    else if (num > 0 && num < base) {
        return to_string_custom(num);
    }
    else {
        return decimalToBaseB(num / base, base) + to_string_custom(num % base);
    }
}

int main() {
    int numero;

    cout << "Ingresa un número decimal: ";
    cin >> numero;

    cout << "En hexadecimal: " << decimalToHexadecimal(numero) << endl;

    int baseB;
    cout << "Ingresa la base B (entre 2 y 9): ";
    cin >> baseB;

    cout << "En base " << baseB << ": " << decimalToBaseB(numero, baseB) << endl;

    return 0;
}
