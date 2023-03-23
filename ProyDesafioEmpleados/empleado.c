/**
 * @file empleado.c
 * @author Domingo Pérez
 * @date 16 de marzo de 2023
 * @brief Implementación de la estructura Empleado y sus operaciones.
 * @course Programación 2
 * @year 2023
 * @center CeRP del Suroeste
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleado.h"

Empleado *crear_empleado(const char *nombre, int id, float salario_mensual) {
    Empleado *empleado = (Empleado *) malloc(sizeof(Empleado));
    if (empleado == NULL) {
        fprintf(stderr, "Error: no se pudo asignar memoria para el empleado\n");
        exit(EXIT_FAILURE);
    }
    strcpy(empleado->nombre, nombre);
    empleado->id = id;
    empleado->salario_mensual = salario_mensual;
    return empleado;
}

void mostrar_empleado(const Empleado *empleado) {
    printf("Nombre: %s\n", empleado->nombre);
    printf("ID: %d\n", empleado->id);
    printf("Salario mensual: $%.2f\n", empleado->salario_mensual);
}

void eliminar_empleado(Empleado *empleado) {
    free(empleado);
}
