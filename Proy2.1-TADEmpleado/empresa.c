#include <stdio.h>
#include "empresa.h"

void agregarEmpleado(Empresa *empresa, Empleado *empleado) {
    empresa->empleados[empresa->cantidadEmpleados] = *empleado;
    empresa->cantidadEmpleados++;
}

void quitarEmpleado(Empresa *empresa, int cedula) {
    for (int i = 0; i < empresa->cantidadEmpleados; i++) {
        if (empresa->empleados[i].cedula == cedula) {
            for (int j = i; j < empresa->cantidadEmpleados - 1; j++) {
                empresa->empleados[j] = empresa->empleados[j + 1];
            }
            empresa->cantidadEmpleados--;
            break;
        }
    }
}

void imprimirEmpleadosCumpleanios(Empresa *empresa, Fecha *fecha) {
    for (int i = 0; i < empresa->cantidadEmpleados; i++) {
        if (empresa->empleados[i].fechaNacimiento.dia == fecha->dia && empresa->empleados[i].fechaNacimiento.mes == fecha->mes) {
            imprimirEmpleado(&empresa->empleados[i]);
            printf("\n");
        }
    }
}