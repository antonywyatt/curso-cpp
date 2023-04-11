#include <iostream>
#include <sys/stat.h> //para crear carpetas
#include <fstream> //para leer y escribir archivos
#include <filesystem> //para recorrer archivos
#include <string>
#include <locale> //para aceptar caracteres especiales
#define MAX 1000

using namespace std;

int organizarArchivos(string archivos[MAX],string tipo[MAX], int i);
string colorTexto(string texto, string color);

int main() {

    // Configurar la codificación de caracteres UTF-8 para que acepte caracteres especiales (á, é, í, ó, ú, ñ, etc.)
    setlocale(LC_ALL, "en_US.utf8");

    int opcion_menu, i, j, k;
    int total_archivos = 0;
    string archivos[MAX];
    string tipo[MAX];

    do
    {
        cout << colorTexto("===============MENU===============", "verde") << endl;
        cout << "Bienvenido al programa de organizacion de archivos" << endl;
        cout << "Por favor seleccione una opcion" << endl;
        cout << "1. Organizar archivos" << endl;
        cout << "2. Ver archivos en general" << endl;
        cout << "3. Ver archivos por tipo" << endl;
        cout << "4. Integrantes" << endl;
        cout << "0. Salir" << endl;
        cout << colorTexto("==================================", "verde") << endl;
        cout << "Opcion: ";
        cin >> opcion_menu;

        switch (opcion_menu)
        {
        case 1:
            cout<< colorTexto("Organizando archivos...", "amarillo") << endl;
            total_archivos = organizarArchivos(archivos, tipo, i);
            cout<< colorTexto("Archivos organizados correctamente", "verde") << endl;
            break;
        case 2:
            cout<< colorTexto("Mostrando archivos...", "amarillo") << endl;
            cout<< colorTexto("_______________________________________", "amarillo")<<endl;
            cout<<"Nombre\t\tTipo"<<endl;
            cout<< colorTexto("_______________________________________", "amarillo")<<endl;
            for (j = 0; j < total_archivos; j++)
            {
                cout << colorTexto(archivos[j] + "\t" + tipo[j], "rojo") << endl;
            }
            break;
        case 3:
            cout<< "Mostrando archivos por tipo..." << endl;
            cout<<"_______________________________________"<<endl;
            for(j = 0; j < total_archivos; j++){
                //juntar los archivos con la misma extension en un solo arreglo
                string archivos_tipo[MAX];
                int contador = 0;

                for(k = 0; k < total_archivos; k++){
                    if(tipo[j] == tipo[k]){
                        archivos_tipo[contador] = archivos[k];
                        contador++;
                    }
                }
                //mostrar los archivos con la misma extension
                cout << "Archivos con extension " << tipo[j] << endl;
                for(k = 0; k < contador; k++){
                    cout << archivos_tipo[k] << endl;
                }


                cout << "_______________________________________" << endl;
            }
            break;
        case 4:
            cout<<colorTexto("Integrante: ", "rojo") << endl;
            cout<<colorTexto("_______________________________________", "rojo") <<endl;
            cout<<colorTexto("Nombre: Antony Elio Ayansi Huisa - 77021318", "rojo") << endl;
            cout<<colorTexto("Nombre: Albert feliberto Cáceres Quispe - 74158959", "rojo") << endl;
            cout<<colorTexto("Nombre: Anthony Dennis Oyola Saloma - 75389246", "rojo") << endl;
            cout<<colorTexto("Nombre: Huillca Pérez Fabricio - 71341848", "rojo") << endl;
            cout<<colorTexto("_______________________________________", "rojo") <<endl;
            break;
        default:
            cout << "Hasta luego!" << endl;
            break;
        }
    } while (opcion_menu != 0);

    return 0;
}


int organizarArchivos(string archivos[MAX], string tipo[MAX], int i){
    //abrimos la caperta archivos
    string directorio = filesystem::current_path().string() + "/archivos"; 
    i = 0;

    //recorrer todos los archivos
    for (const auto& archivo : filesystem::directory_iterator(directorio)) {

        string nombre_archivo = archivo.path().filename().string();
        //obtner la extension del archivo
        string extension = nombre_archivo.substr(nombre_archivo.find_last_of(".") + 1);

        //guardar el nombre del archivo en un arreglo
        archivos[i] = nombre_archivo;
        //guardar la extension del archivo en un arreglo
        tipo[i] = extension;
        //crear la carpeta con el nombre de la extension
        string nombre_carpeta = directorio + "/" + extension;
        
        // crear la carpeta para cada extension
        int resultado = mkdir(nombre_carpeta.c_str()); // resultado = 0 si se creo la carpeta, -1 si no se creo

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

        // mover el archivo a la carpeta creada con su extension
        filesystem::rename(archivo.path(), "archivos/" + extension + "/" + nombre_archivo);
        i++; //incrementar 1 por cada archivo
    }

    return i;
}

string colorTexto(string texto, string color){
    if(color == "rojo"){
        texto = "\033[1;31m" + texto + "\033[0m";
    }else if(color == "verde"){
        texto = "\033[1;32m" + texto + "\033[0m";
    }else if(color == "amarillo"){
        texto = "\033[1;33m" + texto + "\033[0m";
    }

    return texto;
}