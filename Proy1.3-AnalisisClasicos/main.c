/**
 * @file main.c
 * @brief Codigo del tema analisis de algoritmos clasicos
 * @details 
 * Unidad: Analisis de Algoritmos
 * Curso: Programacion 2
 * Institucion: CeRP del Suroeste
 * Este programa presenta un menú de selección para trabajar con arreglos o listas,
 * y dentro de cada opción, permite seleccionar entre Búsqueda binaria, Ordenamiento
 * burbuja y Quicksort.
 * @author Domingo Perez
 * @date 15 de abril de 2023
 */

#include <stdio.h>
#include <stdlib.h>
#include "arreglo.h"
#include "lista.h"
#include "algoritmosClasicos.h" 

/**
 * @brief Función para realizar la selección del tipo de estructura de datos.
 * @return Entero que representa la opción seleccionada.
 */
int seleccionar_estructura() {
    int opcion;
    printf("Seleccione una estructura de datos:\n");
    printf("1. Arreglos\n");
    printf("2. Listas\n");
    printf("Seleccione una opción: ");
    scanf("%d", &opcion);
    return opcion;
}

/**
 * @brief Función para realizar la selección del algoritmo a utilizar.
 * @return Entero que representa la opción seleccionada.
 */
int seleccionar_algoritmo(int est) {
    int opcion;
    printf("\nSeleccione un algoritmo:\n");
    printf("1. Búsqueda binaria\n");
    printf("2. Ordenamiento burbuja\n");
    printf("3. Quicksort\n");
    printf("4. Mergesort\n");
    if (est == 1) printf("5. Test arreglo\n");
    if (est == 2) printf("5. Test arreglo\n");
    printf("Seleccione una opción: ");
    scanf("%d", &opcion);
    opcion = est*10+opcion;
    return opcion;
}

/**
 * @brief Función principal del programa.
 * 
 * @return Entero que indica si la ejecución fue exitosa.
 */
int main() {
    int estructura = seleccionar_estructura();
    int algoritmo;
    int valor_buscar;
    int *int_encontrado;
    // Creamos un arreglo estándar con los primeros 10 números naturales
    array_t arr = {{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, ARRAY_SIZE};

    // Creamos una lista nula
    lista_t lista = {NULL, 0};

    // Insertamos los primeros 10 números naturales
    for (int i = 0; i < 10; i++) {
        lista_push_front(&lista, i);
    }

    switch (estructura) {
        case 1:
            printf("\nTrabajando con arreglos.\n");
            algoritmo = seleccionar_algoritmo(1);
            break;
        case 2:
            printf("\nTrabajando con listas.\n");
            algoritmo = seleccionar_algoritmo(2);
            break;
        default:
            printf("\nOpción inválida.\n");
            return 1;
    }

    //algoritmo = seleccionar_algoritmo();

    switch (algoritmo) {
        case 11:
            printf("\nUtilizando Búsqueda binaria.\n");
                
            // Buscamos un valor en la lista utilizando búsqueda binaria
            valor_buscar = 4;
            int_encontrado = array_binary_search(&arr, valor_buscar);
            arreglo_mostrar(arr);

            if (int_encontrado != -1) {
                printf("El valor %d se encuentra en el arreglo.\n", valor_buscar);
            } else {
                printf("El valor %d no se encuentra en el arreglo.\n", valor_buscar);
            }
            break;
        case 12:
            printf("\nUtilizando Ordenamiento burbuja.\n");
            intercambiar(&(arr.arreglo[3]), &(arr.arreglo[5]));
            arreglo_mostrar(arr);

            // Ejecutamos el Ordenamiento de Burbuja
            array_bubblesort(&arr);
            arreglo_mostrar(arr);
            break;
        case 13:
            printf("\nUtilizando Quicksort.\n");
            intercambiar(&(arr.arreglo[3]), &(arr.arreglo[5]));
            arreglo_mostrar(arr);

            // Ejecutamos el Ordenamiento de Quicksort
            array_quicksort(&arr);
            arreglo_mostrar(arr);
            break;
        case 14:
            printf("\nUtilizando Mergesort.\n");
            intercambiar(&(arr.arreglo[2]), &(arr.arreglo[8]));
            arreglo_mostrar(arr);

            // Ejecutamos el Ordenamiento de Mergesort
            array_mergesort(&arr, arr.size);
            arreglo_mostrar(arr);
            break; 
        case 15:
            printf("\nTest de arreglo.\n");
            arreglo_test(&arr);
            break;  
        case 21:
            lista_mostrar(lista); 

            lista_sort(&lista);
            for (nodo_t* nodo = lista.cabeza; nodo != NULL; nodo = nodo->siguiente) {
                printf("%d ", nodo->valor);
            }
            printf("\n");

            printf("\nUtilizando Búsqueda binaria.\n");
            // Buscamos un valor en la lista utilizando búsqueda binaria
            valor_buscar = 4;
            nodo_t *nodo_encontrado = (nodo_t*) malloc(sizeof(nodo_t));
            nodo_encontrado = lista_binary_search(&lista, valor_buscar);

            if (nodo_encontrado != NULL) {
                printf("El valor %d se encuentra en la lista.\n", valor_buscar);
            } else {
                printf("El valor %d no se encuentra en la lista.\n", valor_buscar);
            }
            break;
        case 22:
            printf("\nUtilizando Ordenamiento burbuja.\n");
            lista_remove(&lista, 4);
            lista_push_front(&lista, 4);

            // Imprimimos la lista NO ordenada
            printf("La lista NO ordenada es: ");

            for (nodo_t* nodo = lista.cabeza; nodo != NULL; nodo = nodo->siguiente) {
                printf("%d ", nodo->valor);
            }
            printf("\n");

            // Ordenamos la lista utilizando el algoritmo de ordenamiento de burbuja
            lista_bubblesort(&lista);

            // Imprimimos la lista ordenada
            printf("La lista ordenada es: ");
            for (nodo_t* nodo = lista.cabeza; nodo != NULL; nodo = nodo->siguiente) {
                printf("%d ", nodo->valor);
            }
            printf("\n");
            break;
        case 23:
            printf("\nUtilizando Quicksort.\n");
            printf("Quicksort lo implementaremos para Arreglos\n");             
            break;
        case 24:
            printf("\nUtilizando Ordenamiento Mergesort.\n");
            lista_remove(&lista, 4);
            lista_push_front(&lista, 4);

            // Imprimimos la lista NO ordenada
            printf("La lista NO ordenada es: ");

            for (nodo_t* nodo = lista.cabeza; nodo != NULL; nodo = nodo->siguiente) {
                printf("%d ", nodo->valor);
            }
            printf("\n");

            // Ordenamos la lista utilizando el algoritmo de ordenamiento de burbuja
            lista_mergesort(&lista);

            // Imprimimos la lista ordenada
            printf("La lista ordenada es: ");
            for (nodo_t* nodo = lista.cabeza; nodo != NULL; nodo = nodo->siguiente) {
                printf("%d ", nodo->valor);
            }
            printf("\n");
            break;
        case 25:
            printf("\nTest de Lista.\n");
            lista_test(&lista);
            break;    
        default:
            printf("\nOpción inválida.\n");
            return 1;
    }

    // Liberamos la memoria utilizada por la lista
    lista_clear(&lista);

    system("pause");
    return 0;
}