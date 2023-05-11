#include <stdio.h>
#include <string.h>
#include "empleado.h"

/**
 * @brief Lee la información de un empleado desde la entrada estándar
 * @param empleado Puntero al empleado cuyos datos serán leídos
 */
void leerEmpleado(Empleado *empleado) {
    printf("Ingrese el nombre del empleado: ");
    fgets(empleado->nombre, 50, stdin);
    empleado->nombre[strcspn(empleado->nombre, "\n")] = 0;

    printf("Ingrese el apellido del empleado: ");
    fgets(empleado->apellido, 50, stdin);
    empleado->apellido[strcspn(empleado->apellido, "\n")] = 0;

    printf("Ingrese la cedula del empleado: ");
    scanf("%d", &empleado->cedula);

    printf("Ingrese la fecha de nacimiento (dd mm aaaa): ");
    scanf("%d %d %d", &empleado->fechaNacimiento.dia, &empleado->fechaNacimiento.mes, &empleado->fechaNacimiento.anio);

    getchar(); // Limpiar el buffer de entrada
}

void imprimirEmpleado(Empleado *empleado) {
    printf("Nombre: %s\n", empleado->nombre);
    printf("Apellido: %s\n", empleado->apellido);
    printf("Cedula: %d\n", empleado->cedula);
    printf("Fecha de nacimiento: %02d/%02d/%04d\n", empleado->fechaNacimiento.dia, empleado->fechaNacimiento.mes, empleado->fechaNacimiento.anio);
}

int obtenerCedula(Empleado *empleado) {
    return empleado->cedula;
}

Fecha obtenerFechaNacimiento(Empleado *empleado) {
    return empleado->fechaNacimiento;
}