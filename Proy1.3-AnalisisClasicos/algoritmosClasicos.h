/**
 * @file algoritmosClasicos.h
 * @brief Implementaciones clásicas de algoritmos de búsqueda y ordenamiento para listas y arreglos.
 */

#ifndef ALGORITMOSCLASICOS_H
#define ALGORITMOSCLASICOS_H

#include "lista.h" 
#include "arreglo.h" 

/**
 * @brief Realiza una búsqueda binaria en una lista ordenada.
 * @param lista Puntero a la lista ordenada.
 * @param valor Valor a buscar.
 * @return Puntero al nodo encontrado o NULL si no se encuentra el valor.
 */
nodo_t *lista_binary_search(lista_t *lista, int valor);

/**
 * @brief Ordena una lista utilizando el algoritmo de ordenamiento de burbuja.
 * @param lista Puntero a la lista.
 */
void lista_bubblesort(lista_t *lista);

/**
 * @brief Ordena una lista utilizando el algoritmo de ordenamiento rápido (quicksort).
 * @param lista Puntero a la lista.
 */
void lista_quicksort(lista_t *lista);

/**
 * @brief Ordena una lista utilizando el algoritmo de ordenamiento por mezcla (mergesort).
 * @param lista Puntero a la lista.
 */
void lista_mergesort(lista_t *lista);

/**
 * @brief Realiza una búsqueda binaria en un arreglo ordenado.
 * @param arr Puntero al arreglo ordenado.
 * @param valor Valor a buscar.
 * @return Índice del elemento encontrado o -1 si no se encuentra el valor.
 */
int array_binary_search(array_t* arr, int valor);

/**
 * @brief Ordena el arreglo usando el algoritmo de burbuja.
 * @param arr Puntero al arreglo a ordenar.
 */
void array_bubblesort(array_t* arr);

/**
 * @brief Ordena un arreglo utilizando el algoritmo de ordenamiento rápido (quicksort).
 * @param arr Puntero al arreglo.
 */
void array_quicksort(array_t* arr);

/**
 * @brief Función auxiliar para el algoritmo de ordenamiento quicksort.
 * @param arr Puntero al arreglo.
 * @param inicio Índice del primer elemento del arreglo a ordenar.
 * @param fin Índice del último elemento del arreglo a ordenar.
 */
void quicksort_helper(array_t* arr, int inicio, int fin);

/**
 * @brief Intercambia los valores de dos variables enteras.
 * @param a Puntero al primer entero.
 * @param b Puntero al segundo entero.
 */
void intercambiar(int* a, int* b);

/**
 * @brief Función auxiliar para el algoritmo de ordenamiento quicksort.
 * @param arr Puntero al arreglo.
 * @param inicio Índice del primer elemento del arreglo a ordenar.
 * @param fin Índice del último elemento del arreglo a ordenar.
 * @return Índice de la partición.
 */
int particion(array_t* arr, int inicio, int fin);

/**
 * @brief Ordena el arreglo utilizando el algoritmo de mergesort.
 * @param arr Puntero al arreglo.
 * @param size Tamaño del arreglo.
 */
void array_mergesort(array_t* arr, int size);

/**
 * @brief Mezcla los arreglos izquierdo y derecho en el arreglo original.
 * @param arr Puntero al arreglo original.
 * @param left_arr Puntero al arreglo izquierdo.
 * @param right_arr Puntero al arreglo derecho.
 * @param left_size Tamaño del arreglo izquierdo.
 * @param right_size Tamaño del arreglo derecho.
 */
void merge(array_t* arr, array_t left_arr, array_t right_arr, int left_size, int right_size);

#endif // ALGORITMOSCLASICOS_H
