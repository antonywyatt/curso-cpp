#include <iostream>
using namespace std;
struct nodo
{
    int nro;
    struct nodo *sgte;
};
struct cola
{
    nodo *delante;
    nodo *atras;
};
struct cola q;
void encolar(int valor);
int main()
{
    struct nodo *aux; // nodo para recorrer la cola
    float acumulador;
    int n;                            // Nro de elementos que se ingresaran a la cola
    int nroAux;                       // variable auxiliar para insertar elementos a la cola
    encolar(nroAux); 
    int i = 1, j = 1; // Contador para saber que elemento estamos utilizando
    q.delante = NULL;
    q.atras = NULL;
    cout << "Ingrese el numero de elementos de la cola" << endl;
    cin >> n;
    while (n > 0)
    {
        cout << "Ingrese el elemento N? " << i << endl;
        cin >> nroAux;
        encolar(nroAux); // insertamos a la cola
        n--;
        i++;
    }
    n = i;
    // mostrar elementos de la cola
    cout << "********************" << endl;
    cout << "ELEMENTOS DE LA COLA" << endl;
    aux = q.delante;
    while (aux != NULL)
    {
        cout << aux->nro << " -> " << j << " elemento en ingresar y el " << j
             << " en salir " << endl;
        acumulador += aux->nro;
        aux = aux->sgte;
        j++;
    }
    cout << "El promedio de los números de la cola es: " << acumulador / (j - 1)
         << endl;
    cout << endl;
    // mayor y menor de la cola
    cout << "********************" << endl;
    cout << "MAYOR Y MENOR DE LA COLA" << endl;
    aux = q.delante;
    int mayor = aux->nro;
    int menor = aux->nro;
    while (aux != NULL)
    {
        if (aux->nro > mayor)
            mayor = aux->nro;
        if (aux->nro < menor)
            menor = aux->nro;
        aux = aux->sgte;
    }
    cout << "El mayor elemento de la cola es: " << mayor << endl;
    cout << "El menor elemento de la cola es: " << menor << endl;
    // vaciar la cola
    cout << "********************" << endl;
    cout << "VACIANDO LA COLA" << endl;
    while (q.delante != NULL){
        aux = q.delante;
        cout << "Elemento " << aux->nro << " eliminado" << endl;
        q.delante = (q.delante)->sgte;
        delete (aux);
    }
    cout << "La cola esta vacia" << endl;
    system("Pause");
    return 0;
}

void encolar(int valor)
{
    struct nodo *aux = new (struct nodo);
    aux->nro = valor;
    aux->sgte = NULL;

    if (q.delante == NULL)
        q.delante = aux;
    else
        (q.atras)->sgte = aux;
    q.atras = aux;
}