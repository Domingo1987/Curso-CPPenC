#include <stdio.h>
#include <string.h>
#include "empresa.h"

/**
 * @file main.c
 * @brief Programa de gestión de empleados para una empresa utilizando arreglos acotados
 * @author Domingo Perez
 * @date 2-5-2023
 */

int main() {
    Empresa empresa;
    empresa.cantidadEmpleados = 0;
    Empleado empleado;
    int opcion;
    Fecha fecha;

    // Menú interactivo
    while (1) {
        printf("\n1. Agregar empleado\n");
        printf("2. Quitar empleado\n");
        printf("3. Imprimir empleados que cumplen años en una fecha dada\n");
        printf("4. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);
        getchar(); // Limpiar el buffer de entrada

        switch (opcion) {
            case 1:
                // Leer datos del empleado y agregarlo a la empresa
                leerEmpleado(&empleado);
                agregarEmpleado(&empresa, &empleado);
                break;
            case 2:
                // Pedir cédula y eliminar el empleado con dicha cédula
                printf("Ingrese la cedula del empleado a quitar: ");
                scanf("%d", &empleado.cedula);
                quitarEmpleado(&empresa, empleado.cedula);
                break;
            case 3:
                // Pedir fecha y mostrar empleados que cumplen años en dicha fecha
                printf("Ingrese la fecha (dd mm aaaa): ");
                scanf("%d %d %d", &fecha.dia, &fecha.mes, &fecha.anio);
                imprimirEmpleadosCumpleanios(&empresa, &fecha);
                break;
            case 4:
                // Salir del programa
                return 0;
            default:
                printf("Opción no válida.\n");
        }
    }

    return 0;
}