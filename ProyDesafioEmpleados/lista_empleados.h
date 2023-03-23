/**
 * @file lista_empleados.h
 * @brief Definición de la estructura ListaEmpleados y las funciones para manejarla.
 *
 * La estructura ListaEmpleados es una lista enlazada simple que contiene nodos que
 * a su vez contienen objetos de tipo Empleado. Las funciones definidas en este archivo
 * permiten crear, agregar, buscar, modificar, eliminar y mostrar la lista de empleados.
 *
 * @author Domingo Pérez
 * @date 2023-03-16
 * @version 1.0
 * @course Programacion 2
 * @center CeRP del Suroeste
 */

#ifndef LISTA_EMPLEADOS_H
#define LISTA_EMPLEADOS_H

#include "empleado.h"

/**
 * @struct Nodo
 * @brief Estructura que representa un nodo de la lista enlazada de empleados.
 * @var Nodo::empleado
 * Puntero a miembro que almacena al empleado en el nodo.
 * @var Nodo::siguiente
 * Puntero al siguiente nodo de la lista.
*/
typedef struct nodo {
    Empleado* empleado; /**< Empleado almacenado en el nodo */
    struct nodo *siguiente; /**< Puntero al siguiente nodo */
} Nodo;

/**
 * @struct ListaEmpleados
 * @brief Estructura de la lista enlazada.
 */
typedef struct listaEmpleados {
    Nodo* cabeza; /**< Puntero al primer nodo de la lista */
    int longitud; /**< Cantidad de nodos en la lista */
} ListaEmpleados;

/**
 * @brief Crea una nueva lista vacía.
 * @return Puntero a la nueva lista.
 */
ListaEmpleados* crear_lista();

/**
 * @brief Agrega un nuevo empleado a la lista.
 * @param lista Puntero a la lista en la que se agregará el empleado.
 * @param empleado Empleado a agregar.
 */
void agregar_empleado(ListaEmpleados* lista, const char* nombre, int id, float salario_mensual);

/**
 * @brief Busca un empleado por su identificación en una lista enlazada.
 * @param lista Puntero a la lista de empleados.
 * @param id Identificación del empleado a buscar.
 * @return Puntero al empleado encontrado o NULL si no se encontró.
 */
Empleado* buscar_empleado(const ListaEmpleados* lista, int id);

/**
 * @brief Modifica los datos de un empleado en una lista enlazada.
 * @param lista Puntero a la lista de empleados.
 * @param id Identificación del empleado a modificar.
 * @param nuevoNombre Nuevo nombre del empleado.
 * @param nuevoSalario Nuevo salario mensual del empleado.
 * @return 1 si se realizó la modificación correctamente, 0 si no se encontró el empleado.
 */
int modificar_empleado(ListaEmpleados* lista, int id, char nuevoNombre[], float nuevoSalario);

/**
 * @brief Elimina un empleado de una lista enlazada.
 * @param lista Puntero a la lista de empleados.
 * @param id Identificación del empleado a eliminar.
 * @return 1 si se realizó la eliminación correctamente, 0 si no se encontró el empleado.
 */
void eliminar_empleado_l(ListaEmpleados* lista, int id);

/**
 * @brief Muestra todos los empleados en una lista enlazada.
 * @param lista Puntero a la lista de empleados.
 */
void mostrar_lista(const ListaEmpleados* lista);

/**
 * @brief Libera la memoria ocupada por una lista enlazada y sus empleados.
 * @param lista Puntero a la lista de empleados.
 */
void liberar_lista(ListaEmpleados* lista);


#endif /* LISTA_EMPLEADOS_H */
