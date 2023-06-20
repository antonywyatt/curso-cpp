#include <iostream>
#include <chrono>
#include <ctime>

using namespace std;

struct Node
{
    int value;
    Node *next;
};

// Listas de nodos
Node *ListaSinOrdenar = NULL;

Node *ListaBurbuja = NULL;
Node *ListaHeapSort = NULL;
Node *ListaMergeSort = NULL;
Node *ListaQuickSort = NULL;

// Variables para tiempos de ejecucion
double tiempoBurbuja = 0.0;
double tiempoHeapSort = 0.0;
double tiempoMergeSort = 0.0;
double tiempoQuickSort = 0.0;

// Funciones generales
void generarNodos();
void listarNodos(Node *Lista);
void intercambiarNodes(Node *a, Node *b);
Node *merge(Node *izquierda, Node *derecha);
void dividir(Node *source, Node **frontRef, Node **backRef);
Node *merge(Node *a, Node *b);
Node *getLastNode(Node *head);

// Funciones de ordenamiento
void ordenarXburbuja(int i);
void ordenarXHeadSort();
void ordenarXMergeSort(Node **headRef);
Node *quickSort(Node *head, Node *end);

// Funciones de calculo de tiempo
double calcularTiempo(clock_t start, clock_t end);

int main()
{

    generarNodos();
    listarNodos(ListaSinOrdenar);
    int opcion, i = 0;
    clock_t start, end;

    do
    {
        cout << "______________Menu de ordenamiento______________" << endl;
        cout << "1. Ordenar por BubbleSort" << endl;
        cout << "2. Ordenar por HeapSort" << endl;
        cout << "3. Ordenar por MergeSort" << endl;
        cout << "4. Ordenar por QuickSort" << endl;
        cout << "5. Ver tiempos de ejecucion" << endl;
        cout << "6. Salir" << endl;
        cout << "________________________________________________" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        start = clock();
        switch (opcion)
        {
        case 1:
            // barra de progreso dinamica
            cout << "==== Ordenando por BubbleSort ====" << endl;
            ListaBurbuja = ListaSinOrdenar;
            ordenarXburbuja(i);
            end = clock();
            listarNodos(ListaBurbuja);


            tiempoBurbuja = calcularTiempo(start, end);
            cout << "Tiempo de ejecucion: " << tiempoBurbuja << " segundos" << endl;
            break;
        case 2:
            cout << "==== Ordenando por HeapSort ====" << endl;
            ListaHeapSort = ListaSinOrdenar;
            ordenarXHeadSort();
            end = clock();
            listarNodos(ListaHeapSort);
            
            tiempoHeapSort = calcularTiempo(start, end);
            cout << "Tiempo de ejecucion: " << tiempoHeapSort << " segundos" << endl;
            break;
        case 3:
            cout << "==== Ordenando por MergeSort ====" << endl;
            ListaMergeSort = ListaSinOrdenar;
            ordenarXMergeSort(&ListaMergeSort);
            end = clock();
            listarNodos(ListaMergeSort);

            tiempoMergeSort = calcularTiempo(start, end);
            cout << "Tiempo de ejecucion: " << tiempoMergeSort << " segundos" << endl;
            break;
        case 4:
            cout << "==== Ordenando por QuickSort ====" << endl;
            ListaQuickSort = ListaSinOrdenar;
            ListaQuickSort = quickSort(ListaQuickSort, getLastNode(ListaQuickSort));
            end = clock();
            listarNodos(ListaQuickSort);

            tiempoQuickSort = calcularTiempo(start, end);
            cout << "Tiempo de ejecucion: " << tiempoQuickSort << " segundos" << endl;
            break;
        case 5:
            cout << "Ver tiempos de ejecucion" << endl;
            cout << "BubbleSort: " << tiempoBurbuja << " segundos" << endl;
            cout << "HeapSort: " << tiempoHeapSort << " segundos" << endl;
            cout << "MergeSort: " << tiempoMergeSort << " segundos" << endl;
            cout << "QuickSort: " << tiempoQuickSort << " segundos" << endl;
            break;
        case 6:
            cout << "Hasta la próxima😃!" << endl;
            break;
        default:
            cout << "Opcion incorrecta" << endl;
            break;
        }
    } while (opcion != 6);

    return 0;
}

void generarNodos()
{
    for (int i = 0; i < 15; i++)
    {
        Node *nuevo = new Node();
        nuevo->value = rand() % 100;
        nuevo->next = NULL;
        if (ListaSinOrdenar == NULL)
        {
            ListaSinOrdenar = nuevo;
        }
        else
        {
            Node *aux = ListaSinOrdenar;
            while (aux->next != NULL)
            {
                aux = aux->next;
            }
            aux->next = nuevo;
        }
    }
}

void listarNodos(Node *Lista)
{
    cout << "======= Mostrando lista =======" << endl;
    Node *aux = Lista;
    while (aux != NULL)
    {
        cout << aux->value << " ";
        aux = aux->next;
    }
    cout << endl;
}

void intercambiarNodes(Node *a, Node *b)
{
    int temp = a->value;
    a->value = b->value;
    b->value = temp;
}

void amontonar(Node *head, int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // Comparar el nodo raíz con sus hijos y encontrar el más grande
    if (left < n && head->value < head[left].value)
        largest = left;

    if (right < n && head[largest].value < head[right].value)
        largest = right;

    // Si el nodo más grande no es la raíz, intercambiarlos y ajustar el subárbol afectado
    if (largest != i)
    {
        intercambiarNodes(&head[i], &head[largest]);
        amontonar(head, n, largest);
    }
}

// Subfuncion para MergeSort
void dividir(Node *source, Node **frontRef, Node **backRef)
{
    Node *slow = source;
    Node *fast = source->next;

    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
}

Node *merge(Node *a, Node *b)
{
    Node *result = NULL;

    if (a == NULL)
        return b;
    if (b == NULL)
        return a;

    if (a->value <= b->value)
    {
        result = a;
        result->next = merge(a->next, b);
    }
    else
    {
        result = b;
        result->next = merge(a, b->next);
    }

    return result;
}

void swapNodes(Node *a, Node *b)
{
    int temp = a->value;
    a->value = b->value;
    b->value = temp;
}

Node *getLastNode(Node *head)
{
    while (head && head->next)
        head = head->next;
    return head;
}
// Función para particionar la lista en base a un pivote
Node *partition(Node *head, Node *end, Node **newHead, Node **newEnd)
{
    Node *pivot = end;
    Node *prev = NULL;
    Node *current = head;
    Node *tail = pivot;

    while (current != pivot)
    {
        if (current->value < pivot->value)
        {
            if (*newHead == NULL)
                *newHead = current;

            prev = current;
            current = current->next;
        }
        else
        {
            if (prev)
                prev->next = current->next;
            Node *temp = current->next;
            current->next = NULL;
            tail->next = current;
            tail = current;
            current = temp;
        }
    }

    if (*newHead == NULL)
        *newHead = pivot;

    *newEnd = tail;

    return pivot;
}

/*

Fuciones de ordenamiento

*/
void ordenarXburbuja(int i)
{
    bool swapped;
    Node *ptr1;
    Node *lptr = NULL;

    if (ListaBurbuja == NULL)
        return;

    do
    {
        swapped = false;
        ptr1 = ListaBurbuja;

        while (ptr1->next != lptr)
        {
            if (ptr1->value > ptr1->next->value)
            {
                intercambiarNodes(ptr1, ptr1->next);
                swapped = true;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

void ordenarXHeadSort()
{
    int n = 0;
    Node *current = ListaHeapSort;
    while (current != NULL)
    {
        current = current->next;
        n++;
    }

    Node *arr = new Node[n];
    current = ListaHeapSort;
    for (int i = 0; i < n; i++)
    {
        arr[i] = *current;
        current = current->next;
    }

    for (int i = n / 2 - 1; i >= 0; i--)
        amontonar(arr, n, i);

    for (int i = n - 1; i >= 0; i--)
    {
        intercambiarNodes(&arr[0], &arr[i]);
        amontonar(arr, i, 0);
    }

    current = ListaHeapSort;
    for (int i = 0; i < n; i++)
    {
        current->value = arr[i].value;
        current = current->next;
    }

    // Liberar memoria
    delete[] arr;
}

void ordenarXMergeSort(Node **headRef)
{
    Node *head = *headRef;
    Node *a;
    Node *b;

    if (head == NULL || head->next == NULL)
        return;

    dividir(head, &a, &b);

    ordenarXMergeSort(&a);
    ordenarXMergeSort(&b);

    *headRef = merge(a, b);
}

// Función principal para implementar el algoritmo QuickSort en la lista
Node *quickSort(Node *head, Node *end)
{
    if (!head || head == end)
        return head;

    Node *newHead = NULL;
    Node *newEnd = NULL;

    Node *pivot = partition(head, end, &newHead, &newEnd);

    if (newHead != pivot)
    {
        Node *temp = newHead;
        while (temp->next != pivot)
            temp = temp->next;
        temp->next = NULL;
        newHead = quickSort(newHead, temp);
        temp = getLastNode(newHead);
        temp->next = pivot;
    }

    pivot->next = quickSort(pivot->next, newEnd);

    return newHead;
}


//funcion para calcular el tiempo de ejecucion
double calcularTiempo(clock_t start, clock_t end)
{
    double tiempo = (double)(end - start) / CLOCKS_PER_SEC;
    return tiempo;
}