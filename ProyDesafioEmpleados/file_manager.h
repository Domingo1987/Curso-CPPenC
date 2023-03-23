/**
 * @file file_manager.h
 * @brief Funciones para guardar y cargar la lista de empleados desde un archivo.
 */

#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include "lista_empleados.h"

/**
 * @brief Guarda la lista de empleados en un archivo.
 * 
 * @param filename Nombre del archivo en el que se guardará la lista de empleados.
 * @param lista Puntero a la lista de empleados.
 * @return int Retorna 0 si la operación fue exitosa, -1 si hubo un error al abrir el archivo.
 */
int guardar_lista_empleados(const char *filename, ListaEmpleados *lista);

/**
 * @brief Carga la lista de empleados desde un archivo.
 * 
 * @param filename Nombre del archivo del cual se cargará la lista de empleados.
 * @param lista Puntero a la lista de empleados.
 * @return int Retorna 0 si la operación fue exitosa, -1 si hubo un error al abrir el archivo.
 */
int cargar_lista_empleados(const char *filename, ListaEmpleados *lista);

#endif // FILE_MANAGER_H
