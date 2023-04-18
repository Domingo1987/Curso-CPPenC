#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

void lista_push_front(lista_t* lista, int valor) {
    nodo_t* nuevo_nodo = (nodo_t*)malloc(sizeof(nodo_t));
    nuevo_nodo->valor = valor;
    nuevo_nodo->siguiente = lista->cabeza;
    lista->cabeza = nuevo_nodo;
    lista->largo++;
}

void lista_pop_front(lista_t* lista) {
    if (lista->cabeza != NULL) {
        nodo_t* nodo_a_eliminar = lista->cabeza;
        lista->cabeza = lista->cabeza->siguiente;
        free(nodo_a_eliminar);
        lista->largo--;
    }
}

int lista_front(const lista_t* lista) {
    return lista->cabeza->valor;
}

size_t lista_size(const lista_t* lista) {
    return lista->largo;
}

bool lista_empty(const lista_t* lista) {
    return lista->largo == 0;
}

void lista_clear(lista_t* lista) {
    nodo_t* nodo_actual = lista->cabeza;
    while (nodo_actual != NULL) {
        nodo_t* nodo_siguiente = nodo_actual->siguiente;
        free(nodo_actual);
        nodo_actual = nodo_siguiente;
    }
    lista->cabeza = NULL;
    lista->largo = 0;
}

void lista_insert_after(nodo_t* nodo, int valor) {
    nodo_t* nuevo_nodo = (nodo_t*)malloc(sizeof(nodo_t));
    nuevo_nodo->valor = valor;
    nuevo_nodo->siguiente = nodo->siguiente;
    nodo->siguiente = nuevo_nodo;
}

void lista_erase_after(nodo_t* nodo) {
    if (nodo->siguiente != NULL) {
        nodo_t* nodo_a_eliminar = nodo->siguiente;
        nodo->siguiente = nodo_a_eliminar->siguiente;
        free(nodo_a_eliminar);
    }
}

void lista_swap(lista_t* lista1, lista_t* lista2) {
    nodo_t* cabeza_temp = lista1->cabeza;
    size_t largo_temp = lista1->largo;
    lista1->cabeza = lista2->cabeza;
    lista1->largo = lista2->largo;
    lista2->cabeza = cabeza_temp;
    lista2->largo = largo_temp;
}

void lista_remove(lista_t* lista, int valor) {
    nodo_t* nodo_actual = lista->cabeza;
    while (nodo_actual != NULL && nodo_actual->siguiente != NULL) {
        if (nodo_actual->siguiente->valor == valor) {
            nodo_t* nodo_a_eliminar = nodo_actual->siguiente;
            nodo_actual->siguiente = nodo_a_eliminar->siguiente;
            free(nodo_a_eliminar);
            lista->largo--;
        } else {
            nodo_actual = nodo_actual->siguiente;
        }
    }
    if (lista->cabeza != NULL && lista->cabeza->valor == valor) {
        lista_pop_front(lista);
    }
}

void lista_assign(lista_t *lista, int valor) {
    nodo_t *nodo_actual = lista->cabeza;

    while (nodo_actual != NULL) {
        nodo_actual->valor = valor;
        nodo_actual = nodo_actual->siguiente;
    }
}

void lista_unique(lista_t* lista) {
    nodo_t* actual = lista->cabeza;
    while (actual != NULL && actual->siguiente != NULL) {
        if (actual->valor == actual->siguiente->valor) {
            nodo_t* nodo_eliminar = actual->siguiente;
            actual->siguiente = actual->siguiente->siguiente;
            free(nodo_eliminar);
            lista->largo--;
        } else {
            actual = actual->siguiente;
        }
    }
}

void lista_merge(lista_t* lista1, lista_t* lista2) {
    nodo_t* actual1 = lista1->cabeza;
    nodo_t* actual2 = lista2->cabeza;
    nodo_t* anterior = NULL;

    while (actual1 != NULL && actual2 != NULL) {
        if (actual2->valor < actual1->valor) {
            if (anterior == NULL) {
                lista1->cabeza = actual2;
            } else {
                anterior->siguiente = actual2;
            }
            actual2 = actual2->siguiente;
            anterior = (anterior == NULL) ? lista1->cabeza : anterior->siguiente;
            anterior->siguiente = actual1;
            lista1->largo++;
        } else {
            anterior = actual1;
            actual1 = actual1->siguiente;
        }
    }

    if (actual2 != NULL) {
        anterior->siguiente = actual2;
        lista1->largo += lista2->largo;
    }

    lista2->cabeza = NULL;
    lista2->largo = 0;
}

void lista_sort(lista_t* lista) {
        if (lista->cabeza == NULL || lista->cabeza->siguiente == NULL) {
        return;
    }

    lista_t lista_mitad = {NULL, 0};
    nodo_t *slow = lista->cabeza;
    nodo_t *fast = lista->cabeza;
    nodo_t *prev = NULL;

    while (fast != NULL && fast->siguiente != NULL) {
        prev = slow;
        slow = slow->siguiente;
        fast = fast->siguiente->siguiente;
    }

    lista_mitad.cabeza = slow;
    lista_mitad.largo = lista->largo / 2;
    lista->largo -= lista_mitad.largo;
    prev->siguiente = NULL;

    lista_sort(lista);
    lista_sort(&lista_mitad);
    lista_merge(lista, &lista_mitad);
}

void lista_reverse(lista_t* lista) {
    nodo_t* actual = lista->cabeza;
    nodo_t* anterior = NULL;

    while (actual != NULL) {
        nodo_t* siguiente = actual->siguiente;
        actual->siguiente = anterior;
        anterior = actual;
        actual = siguiente;
    }

    lista->cabeza = anterior;
}

void lista_test(lista_t *lista) {
    // Imprimimos la lista
    printf("La lista es: ");
    for (nodo_t* nodo = lista->cabeza; nodo != NULL; nodo = nodo->siguiente) {
        printf("%d ", nodo->valor);
    }
    printf("\n");

    // Eliminamos el primer elemento
    lista_pop_front(lista);

    // Imprimimos la lista
    printf("La lista después de eliminar el primer elemento es: ");
    for (nodo_t* nodo = lista->cabeza; nodo != NULL; nodo = nodo->siguiente) {
        printf("%d ", nodo->valor);
    }
    printf("\n");

    // Imprimimos el primer elemento
    printf("El primer elemento es: %d\n", lista_front(lista));

    // Imprimimos el tamaño de la lista
    printf("El tamaño de la lista es: %lu\n", lista_size(lista));

    // Imprimimos si la lista está vacía o no
    printf("La lista %s está vacía.\n", lista_empty(lista) ? "" : "no");

    // Asignamos el valor 42 a todos los elementos de la lista
    lista_assign(lista, 42);

    // Imprimimos la lista
    printf("La lista después de asignar el valor 42 a todos sus elementos es: ");
    for (nodo_t* nodo = lista->cabeza; nodo != NULL; nodo = nodo->siguiente) {
        printf("%d ", nodo->valor);
    }
    printf("\n");

    // Eliminamos todos los elementos de la lista
    lista_clear(lista);

    // Imprimimos la lista
    printf("La lista después de eliminar todos sus elementos es: ");
    if (!lista_empty(lista)){
        for (nodo_t* nodo = lista->cabeza; nodo != NULL; nodo = nodo->siguiente) {
            printf("%d ", nodo->valor);
        }
        printf("\n");
    }
    

    // Intercambiamos el contenido de dos listas
    lista_t lista2 = {NULL, 0};
    lista_push_front(&lista2, 99);
    lista_push_front(&lista2, 88);
    lista_push_front(&lista2, 77);
    lista_swap(lista, &lista2);

    // Imprimimos la lista
    printf("La lista después de intercambiar con la segunda lista es: ");
    for (nodo_t* nodo = lista->cabeza; nodo != NULL; nodo = nodo->siguiente) {
        printf("%d ", nodo->valor);
    }
    printf("\n");

    // Imprimimos la segunda lista
    if (!lista_empty(&lista2)){
        for (nodo_t* nodo = lista->cabeza; nodo != NULL; nodo = nodo->siguiente) {
            printf("%d ", nodo->valor);
        }
        printf("\n");
    }

    // Prueba de lista_remove
    lista_push_front(lista, 1);
    lista_push_front(lista, 2);
    lista_push_front(lista, 1);
    lista_remove(lista, 1);

    printf("La lista después de eliminar todos los '1' es: ");
    for (nodo_t* nodo = lista->cabeza; nodo != NULL; nodo = nodo->siguiente) {
        printf("%d ", nodo->valor);
    }
    printf("\n");

    // Prueba de lista_unique
    lista_push_front(lista, 2);
    lista_unique(lista);

    printf("La lista después de eliminar elementos duplicados adyacentes es: ");
    for (nodo_t* nodo = lista->cabeza; nodo != NULL; nodo = nodo->siguiente) {
        printf("%d ", nodo->valor);
    }
    printf("\n");

    // Prueba de lista_merge
    lista_t lista_ordenada1 = {NULL, 0};
    lista_t lista_ordenada2 = {NULL, 0};
    lista_push_front(&lista_ordenada1, 5);
    lista_push_front(&lista_ordenada1, 3);
    lista_push_front(&lista_ordenada1, 1);
    lista_push_front(&lista_ordenada2, 6);
    lista_push_front(&lista_ordenada2, 4);
    lista_push_front(&lista_ordenada2, 2);
    lista_merge(&lista_ordenada1, &lista_ordenada2);

    printf("La lista después de fusionar dos listas ordenadas es: ");
    for (nodo_t* nodo = lista_ordenada1.cabeza; nodo != NULL; nodo = nodo->siguiente) {
        printf("%d ", nodo->valor);
    }
    printf("\n");

    // Prueba de lista_sort
    lista_clear(lista);
    lista_push_front(lista, 3);
    lista_push_front(lista, 1);
    lista_push_front(lista, 2);
    lista_sort(lista);

    printf("La lista después de ordenar sus elementos es: ");
    for (nodo_t* nodo = lista->cabeza; nodo != NULL; nodo = nodo->siguiente) {
        printf("%d ", nodo->valor);
    }
    printf("\n");

    // Prueba de lista_reverse
    lista_reverse(lista);

    printf("La lista después de invertir sus elementos es: ");
    for (nodo_t* nodo = lista->cabeza; nodo != NULL; nodo = nodo->siguiente) {
        printf("%d ", nodo->valor);
    }
    printf("\n");
}

void lista_mostrar(lista_t lista){
    nodo_t* nodo = (nodo_t*)malloc(sizeof(nodo_t));
    for (nodo = lista.cabeza; nodo != NULL; nodo = nodo->siguiente) {
        printf("%d ", nodo->valor);
    }
    printf("\n");      
}