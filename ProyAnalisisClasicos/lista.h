/**
 * @file lista.h
 * @brief Definición de la interfaz de una lista simplemente enlazada.
 * <\link https://en.cppreference.com/w/cpp/container/forward_list Documentación de forward list en c++>\endlink
 */

#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include <stdbool.h>
#include <stddef.h>

/**
 * @brief Estructura que representa un nodo de la lista.
 * Cada nodo tiene un valor y un puntero al siguiente nodo en la lista.
 */
typedef struct nodo {
    int valor; /**< Valor almacenado en el nodo */
    struct nodo* siguiente; /**< Puntero al siguiente nodo en la lista */
} nodo_t;

/**
 * @brief Estructura que representa una lista simplemente enlazada.
 * La lista está compuesta por un puntero a la cabeza de la lista y un entero que indica el largo de la lista.
 */
typedef struct {
    nodo_t* cabeza; /**< Puntero al primer nodo de la lista */
    size_t largo; /**< Largo de la lista */
} lista_t;

/**
 * @brief Inserta un valor al principio de la lista.
 * @param lista Puntero a la lista.
 * @param valor Valor a insertar.
 */
void lista_push_front(lista_t* lista, int valor);

/**
 * @brief Elimina el primer elemento de la lista.
 * @param lista Puntero a la lista.
 */
void lista_pop_front(lista_t* lista);

/**
 * @brief Devuelve una referencia al primer elemento de la lista.
 * @param lista Puntero a la lista.
 * @return Referencia al primer elemento de la lista.
 */
int lista_front(const lista_t* lista);

/**
 * @brief Devuelve el largo de la lista.
 * @param lista Puntero a la lista.
 * @return Largo de la lista.
 */
size_t lista_size(const lista_t* lista);

/**
 * @brief Indica si la lista está vacía o no.
 * @param lista Puntero a la lista.
 * @return true si la lista está vacía, false si no lo está.
 */
bool lista_empty(const lista_t* lista);

/**
 * @brief Elimina todos los elementos de la lista.
 * @param lista Puntero a la lista.
 */
void lista_clear(lista_t* lista);

/**
 * @brief Inserta un nodo con un valor después del nodo especificado.
 * @param nodo Puntero al nodo después del cual se insertará el nuevo nodo.
 * @param valor Valor del nuevo nodo.
 */
void lista_insert_after(nodo_t* nodo, int valor);

/**
 * @brief Elimina el nodo después del nodo especificado.
 * @param nodo Puntero al nodo antes del nodo que se eliminará.
 * @return Void.
 */
void lista_erase_after(nodo_t* nodo);

/**
 * @brief Intercambia el contenido de dos listas.
 * @param lista1 Puntero a la primera lista.
 * @param lista2 Puntero a la segunda lista.
 */
void lista_swap(lista_t* lista1, lista_t* lista2);

/**
 * @brief Elimina todas las ocurrencias del valor especificado de la lista.
 * @param lista Puntero a la lista.
 * @param valor Valor a eliminar.
 */
void lista_remove(lista_t* lista, int valor);

/**
 * @brief Elimina todas las ocurrencias del valor especificado de la lista.
 * @param lista Puntero a la lista.
 * @param valor Valor a eliminar.
 */
void lista_assign(lista_t *lista, int valor);

/**
 * @brief Elimina todos los elementos duplicados adyacentes de la lista.
 * @param lista Puntero a la lista.
 */
void lista_unique(lista_t* lista);

/**
 * @brief Fusiona dos listas ordenadas en una sola lista ordenada.
 * @param lista1 Puntero a la primera lista.
 * @param lista2 Puntero a la segunda lista.
 */
void lista_merge(lista_t* lista1, lista_t* lista2);

/**
 * @brief Ordena los elementos de la lista de forma ascendente.
 * @param lista Puntero a la lista.
 */
void lista_sort(lista_t* lista);

/**
 * @brief Invierte el orden de los elementos de la lista.
 * @param lista Puntero a la lista.
 */
void lista_reverse(lista_t* lista);

/**
 * @brief Función de prueba para todas las funciones de lista.
 * @param arr Puntero a lista.
 */
void lista_test(lista_t *lista);

#endif // LISTA_H_INCLUDED