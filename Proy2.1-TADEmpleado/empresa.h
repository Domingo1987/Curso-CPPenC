#ifndef EMPRESA_H
#define EMPRESA_H

#include "empleado.h"

typedef struct {
    Empleado empleados[100];
    int cantidadEmpleados;
} Empresa;

/**
 * @brief Agrega un empleado a la empresa
 * @param empresa Puntero a la estructura Empresa a la que se agregará el empleado
 * @param empleado Puntero al empleado que se agregará a la empresa
 */
void agregarEmpleado(Empresa *empresa, Empleado *empleado);

/**
 * @brief Quita un empleado de la empresa según su cédula
 * @param empresa Puntero a la estructura Empresa de la que se quitará el empleado
 * @param cedula La cédula del empleado que se desea quitar
 */
void quitarEmpleado(Empresa *empresa, int cedula);

/**
 * @brief Imprime la información de los empleados que cumplen años en una fecha dada
 * @param empresa Puntero a la estructura Empresa que contiene los empleados
 * @param fecha Puntero a la estructura Fecha con la fecha de cumpleaños deseada
 */
void imprimirEmpleadosCumpleanios(Empresa *empresa, Fecha *fecha);

#endif // EMPRESA_H
