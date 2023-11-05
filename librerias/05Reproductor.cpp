#include <iostream>
#include "CircularDoble.h"

using namespace std;

struct Cancion {
    int id;
    string titulo;
    string artista;
};

class Reproductor {
public:
    Reproductor();
    void agregarCancion(Cancion cancion);
    void eliminarCancion(int id);
    void reproducir();
    void siguiente();
    void anterior();
    void mostrarPlaylist();
    void mostrarMenu();
private:
    ListaCircularDoble playlist;
};

Reproductor::Reproductor() {
    
}

void Reproductor::agregarCancion(Cancion cancion) {
    Nodo nuevoNodo;
    nuevoNodo.dato = cancion.id;
    nuevoNodo.valor1 = cancion.titulo;
    nuevoNodo.valor2 = cancion.artista;
    nuevoNodo.valor3 = "ruta_del_archivo.mp3";
    playlist.agregar(nuevoNodo);
}

void Reproductor::eliminarCancion(int id) {
    playlist.eliminar(id);
}

void Reproductor::siguiente() {
    playlist.next();
    cout << "Reproduciendo: " << playlist.cabeza->valor1 << " - " << playlist.cabeza->valor2 << endl;
}

void Reproductor::anterior() {
    playlist.prev();
    cout << "Reproduciendo: " << playlist.cabeza->valor1 << " - " << playlist.cabeza->valor2 << endl;
}

void Reproductor::reproducir() {
    if (playlist.cabeza) {
        cout << "Reproduciendo: " << playlist.cabeza->valor1 << " - " << playlist.cabeza->valor2 << endl;
    } else {
        cout << "La playlist está vacía." << endl;
    }
}

void Reproductor::mostrarPlaylist() {
    playlist.imprimir();
}

void Reproductor::mostrarMenu() {
    cout << "----- Menú del Reproductor de Música -----" << endl;
    cout << "1. Agregar canción" << endl;
    cout << "2. Eliminar canción" << endl;
    cout << "3. Reproducir" << endl;
    cout << "4. Reproducir Siguiente" << endl;
    cout << "5. Reproducir Anterior" << endl;
    cout << "6. Mostrar playlist" << endl;
    cout << "7. Salir" << endl;
}

int main() {
    Reproductor reproductor;
    int cancionID = 1;
    int opcion;

    do {
        reproductor.mostrarMenu();
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                {
                    Cancion cancion;
                    cancion.id = cancionID++;
                    cout << "Ingrese el título de la canción: ";
                    cin.ignore();  // Limpia el buffer del teclado
                    getline(cin, cancion.titulo);
                    cout << "Ingrese el nombre del artista: ";
                    getline(cin, cancion.artista);
                    reproductor.agregarCancion(cancion);
                    cout << "Canción agregada con éxito." << endl;
                }
                break;
            case 2:
                {
                    int id;
                    cout << "Ingrese el ID de la canción a eliminar: ";
                    cin >> id;
                    reproductor.eliminarCancion(id);
                }
                break;
            case 3:
                reproductor.reproducir();
                break;
            case 4: 
                reproductor.siguiente();
                break;
            case 5:
                reproductor.anterior();
                break;
            case 6:
                reproductor.mostrarPlaylist();
                break;
            case 7:
                cout << "Saliendo del reproductor." << endl;
                break;
            default:
                cout << "Opción no válida. Por favor, elija una opción válida." << endl;
        }
    } while (opcion != 7);

    return 0;
}
