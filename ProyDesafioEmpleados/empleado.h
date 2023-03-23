/**
 * @file empleado.h
 * @author Domingo Pérez
 * @date 16 de marzo de 2023
 * @brief Archivo de cabecera para la estructura Empleado y sus operaciones. Programación 2, año 2023, CeRP del Suroeste
 */

#ifndef EMPLEADO_H
#define EMPLEADO_H

/**
 * @struct Empleado
 * @brief Estructura que representa a un empleado con su nombre, id y salario mensual.
 */
typedef struct _empleado {
    char nombre[50]; /**< Nombre del empleado */
    int id; /**< Identificación única del empleado */
    float salario_mensual; /**< Salario mensual del empleado */
} Empleado;

/**
 * @brief Función para crear un nuevo empleado.
 * @param nombre Nombre del empleado.
 * @param id ID del empleado.
 * @param salario_mensual Salario mensual del empleado.
 * @return Puntero al empleado creado.
*/
Empleado *crear_empleado(const char *nombre, int id, float salario_mensual);

/**
 * @brief Función para mostrar los datos de un empleado.
 * @param empleado Puntero al empleado a mostrar.
*/
void mostrar_empleado(const Empleado *empleado);

/**
 * @brief Función para eliminar un empleado.
 * @param empleado Puntero al empleado a eliminar.
*/
void eliminar_empleado(Empleado *empleado);

#endif // EMPLEADO_H
