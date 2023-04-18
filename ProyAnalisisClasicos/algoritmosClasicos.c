#include "algoritmosClasicos.h" 
#include <stdlib.h>

// Algoritmos sobre listas
nodo_t *lista_binary_search(lista_t *lista, int valor) {
    if (lista == NULL || lista->cabeza == NULL) {
        return NULL;
    }

    int inicio = 0;
    int fin = lista->largo - 1;

    while (inicio <= fin) {
        int medio = inicio + (fin - inicio) / 2;
        
        nodo_t *nodo_medio = (nodo_t*) malloc(sizeof(nodo_t));
        nodo_medio = lista->cabeza;
        for (int i = 0; i < medio; i++) {
            nodo_medio = nodo_medio->siguiente;
        }

        if (nodo_medio->valor == valor) {
            return nodo_medio;
        }

        if (nodo_medio->valor < valor) {
            inicio = medio + 1;
        } else {
            fin = medio - 1;
        }
    }

    return NULL;
}

void lista_bubblesort(lista_t *lista) {
    if (lista == NULL || lista->cabeza == NULL) {
        return;
    }

    int intercambios;
    nodo_t *nodo_actual;
    nodo_t *nodo_siguiente = NULL;

    do {
        intercambios = 0;
        nodo_actual = lista->cabeza;

        while (nodo_actual->siguiente != nodo_siguiente) {
            if (nodo_actual->valor > nodo_actual->siguiente->valor) {
                int temp = nodo_actual->valor;
                nodo_actual->valor = nodo_actual->siguiente->valor;
                nodo_actual->siguiente->valor = temp;
                intercambios = 1;
            }
            nodo_actual = nodo_actual->siguiente;
        }
        nodo_siguiente = nodo_actual;
    } while (intercambios);
}

void lista_quicksort(lista_t *lista) {
    // no lo implementaremos para listas
}

/**
 * @brief Función auxiliar para mezclar dos sublistas ordenadas.
 * 
 * @param a Primer nodo de la primera sublista.
 * @param b Primer nodo de la segunda sublista.
 * @return nodo_t* Puntero al primer nodo de la lista mezclada.
 */
nodo_t* sorted_merge(nodo_t* a, nodo_t* b) {
    nodo_t* result = NULL;

    if (a == NULL) {
        return b;
    } else if (b == NULL) {
        return a;
    }

    if (a->valor <= b->valor) {
        result = a;
        result->siguiente = sorted_merge(a->siguiente, b);
    } else {
        result = b;
        result->siguiente = sorted_merge(a, b->siguiente);
    }

    return result;
}

/**
 * @brief Función auxiliar para dividir una lista en dos sublistas de tamaño similar.
 * @param source Puntero al primer nodo de la lista original.
 * @param front_ref Puntero al puntero al primer nodo de la primera sublista.
 * @param back_ref Puntero al puntero al primer nodo de la segunda sublista.
 */
void front_back_split(nodo_t* source, nodo_t** front_ref, nodo_t** back_ref) {
    nodo_t* fast;
    nodo_t* slow;
    slow = source;
    fast = source->siguiente;

    while (fast != NULL) {
        fast = fast->siguiente;
        if (fast != NULL) {
            slow = slow->siguiente;
            fast = fast->siguiente;
        }
    }

    *front_ref = source;
    *back_ref = slow->siguiente;
    slow->siguiente = NULL;
}

/**
 * @brief Función recursiva que ordena una lista mediante el algoritmo merge sort.
 * 
 * @param head_ref Puntero al puntero al primer nodo de la lista.
 */
void lista_merge_sort_recursive(nodo_t** head_ref) {
    nodo_t* head = *head_ref;
    nodo_t* a;
    nodo_t* b;

    if ((head == NULL) || (head->siguiente == NULL)) {
        return;
    }

    front_back_split(head, &a, &b);

    lista_merge_sort_recursive(&a);
    lista_merge_sort_recursive(&b);

    *head_ref = sorted_merge(a, b);
}

/**
 * @brief Ordena una lista mediante el algoritmo merge sort.
 * 
 * @param lista Puntero a la lista.
 */
void lista_mergesort(lista_t* lista) {
    if (!lista || !lista->cabeza || lista->largo <= 1) {
        return;
    }

    lista_merge_sort_recursive(&lista->cabeza);
}


// Algoritmos sobre arreglos
int array_binary_search(array_t* arr, int valor) {
    int izq = 0, der = arr->size - 1, medio;
    while (izq <= der) {
        medio = (izq + der) / 2;
        if (arr->arreglo[medio] == valor) {
            return medio;
        } else if (arr->arreglo[medio] < valor) {
            izq = medio + 1;
        } else {
            der = medio - 1;
        }
    }
    return -1;
}

void array_bubblesort(array_t* arr) {
  for (int i = 0; i < arr->size; i++) {
    for (int j = 0; j < arr->size - i - 1; j++) {
      if (arr->arreglo[j] > arr->arreglo[j + 1]) {
        int temp = arr->arreglo[j];
        arr->arreglo[j] = arr->arreglo[j + 1];
        arr->arreglo[j + 1] = temp;
      }
    }
  }
}

void array_quicksort(array_t* arr) {
    quicksort_helper(arr, 0, arr->size - 1);
}

void quicksort_helper(array_t* arr, int inicio, int fin) {
    if (inicio < fin) {
        int indiceParticion = particion(arr, inicio, fin);
        quicksort_helper(arr, inicio, indiceParticion - 1);
        quicksort_helper(arr, indiceParticion + 1, fin);
    }
}

void intercambiar(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int particion(array_t* arr, int inicio, int fin) {
    int pivote = arr->arreglo[fin];
    int i = inicio - 1;
    for (int j = inicio; j < fin; j++) {
        if (arr->arreglo[j] < pivote) {
            i++;
            intercambiar(&arr->arreglo[i], &arr->arreglo[j]);
        }
    }
    intercambiar(&arr->arreglo[i + 1], &arr->arreglo[fin]);
    return i + 1;
}

void array_mergesort(array_t* arr, int size) {
    if (size < 2) {
        return;
    }

    int mid = size / 2;

    array_t left_arr, right_arr;

    // Copiar elementos del arreglo original al arreglo izquierdo
    for (int i = 0; i < mid; i++) {
        left_arr.arreglo[i] = arr->arreglo[i];
    }
    left_arr.size = mid;

    // Copiar elementos del arreglo original al arreglo derecho
    for (int i = mid; i < size; i++) {
        right_arr.arreglo[i - mid] = arr->arreglo[i];
    }
    right_arr.size = size - mid;

    // Recursivamente ordenar el arreglo izquierdo y derecho
    array_mergesort(&left_arr, mid);
    array_mergesort(&right_arr, size - mid);

    // Mezclar los arreglos izquierdo y derecho ordenados en el arreglo original
    merge(arr, left_arr, right_arr, mid, size - mid);
}

void merge(array_t* arr, array_t left_arr, array_t right_arr, int left_size, int right_size) {
    int i = 0, j = 0, k = 0;

    // Mezclar los arreglos izquierdo y derecho en el arreglo original
    while (i < left_size && j < right_size) {
        if (left_arr.arreglo[i] <= right_arr.arreglo[j]) {
            arr->arreglo[k] = left_arr.arreglo[i];
            i++;
        } else {
            arr->arreglo[k] = right_arr.arreglo[j];
            j++;
        }
        k++;
    }

    // Copiar los elementos restantes del arreglo izquierdo al arreglo original
    while (i < left_size) {
        arr->arreglo[k] = left_arr.arreglo[i];
        i++;
        k++;
    }

    // Copiar los elementos restantes del arreglo derecho al arreglo original
    while (j < right_size) {
        arr->arreglo[k] = right_arr.arreglo[j];
        j++;
        k++;
    }
}

