#include <iostream>
#include <sys/stat.h>
#include <fstream>
#include <filesystem>
#include <string>

using namespace std;

int main() {
    string directorio = filesystem::current_path().string() + "/archivos";

    for (const auto& archivo : filesystem::directory_iterator(directorio)) {
        string nombre_archivo = archivo.path().filename().string();
        string extension = nombre_archivo.substr(nombre_archivo.find_last_of(".") + 1);

        string nombre_carpeta = directorio + "/" + extension;
        
        int resultado = mkdir(nombre_carpeta.c_str());
        if(resultado == -1 && errno == EEXIST){
            // la carpeta ya existe, no hacemos nada
            cout << "La carpeta ya existe" << endl;
        }else if(resultado == 0){
            // carpeta creada exitosamente
            cout << "Carpeta creada exitosamente " << endl;
        }else{
            // hubo un error al crear la carpeta
            cout << "No se pudo crear la carpeta" << endl;
        }

        filesystem::rename(archivo.path(), "archivos/" + extension + "/" + nombre_archivo);
    }

    return 0;
}
