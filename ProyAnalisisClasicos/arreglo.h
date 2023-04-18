/**
 * @file arreglo.h
 * @brief Definición de la interfaz de un arreglo.
 * <\link https://en.cppreference.com/w/cpp/container/array Documentación de array en c++>\endlink
 */

#ifndef ARREGLO_H_INCLUDED
#define ARREGLO_H_INCLUDED

#include <stdbool.h>
#include <stddef.h>

#define ARRAY_SIZE 10 /**< Tamaño por defecto del arreglo */

typedef struct {
    int arreglo[ARRAY_SIZE]; /**< Arreglo de enteros */
    size_t size; /**< Tamaño del arreglo */
} array_t;

/**
 * @brief Devuelve un puntero al elemento en la posición especificada.
 * @param arr Puntero al arreglo.
 * @param index Índice del elemento.
 * @return Puntero al elemento en la posición especificada.
 */
int* array_at(array_t* arr, size_t index);

/**
 * @brief Devuelve el valor del elemento en la posición especificada.
 * @param arr Arreglo.
 * @param index Índice del elemento.
 * @return Valor del elemento en la posición especificada.
 */ 
int array_get(array_t arr, size_t index);

/**
 * @brief Asigna el valor especificado al elemento en la posición especificada.
 * @param arr Arreglo.
 * @param index Índice del elemento.
 * @param value Valor a asignar.
 */
void array_set(array_t* arr, size_t index, int value);

/**
 * @brief Devuelve el primer elemento del arreglo.
 * @param arr Arreglo.
 * @return Valor del primer elemento del arreglo.
 */
int array_front(array_t arr);

/**
 * @brief Devuelve el último elemento del arreglo.
 * @param arr Arreglo.
 * @return Valor del último elemento del arreglo.
 */
int array_back(array_t arr);

/**
 * @brief Devuelve un puntero al primer elemento del arreglo.
 * @param arr Puntero al arreglo.
 * @return Puntero al primer elemento del arreglo.
 */
int* array_data(array_t* arr);

/**
 * @brief Indica si el arreglo está vacío o no.
 * @param arr Arreglo.
 * @return true si el arreglo está vacío, false si no lo está.
 */
bool array_empty(array_t arr);

/**
 * @brief Devuelve el tamaño del arreglo.
 * @param arr Arreglo.
 * @return Tamaño del arreglo.
 */
size_t array_size(array_t arr);

/**
 * @brief Devuelve el tamaño máximo del arreglo.
 * @param arr Arreglo.
 * @return Tamaño máximo del arreglo.
 */
size_t array_max_size(array_t arr);

/**
 * @brief Asigna el valor especificado a todos los elementos del arreglo.
 * @param arr Arreglo.
 * @param value Valor a asignar.
 */
void array_fill(array_t* arr, int value);

/**
 * @brief Intercambia el contenido de dos arreglos del mismo tamaño y tipo.
 * @param arr1 Puntero al primer arreglo.
 * @param arr2 Puntero al segundo arreglo.
 */
void array_swap(array_t* arr1, array_t* arr2);

/**
 * @brief Función que muestra en pantalla el arreglo.
 * @param arr Puntero al arreglo.
 */
void arreglo_mostrar(array_t arr);

/**
 * @brief Función de prueba para todas las funciones del arreglo.
 * @param arr Arreglo.
 */
void arreglo_test(array_t* arr);

#endif // ARREGLO_H_INCLUDED
