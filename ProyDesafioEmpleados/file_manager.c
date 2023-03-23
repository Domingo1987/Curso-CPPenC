#include <stdio.h>
#include <stdlib.h>
#include "file_manager.h"

int guardar_lista_empleados(const char *filename, ListaEmpleados *lista) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        return -1; // Error al abrir el archivo
    }

    Nodo *current = lista->cabeza;
    while (current) {
        fwrite(current->empleado, sizeof(Empleado), 1, file);
        current = current->siguiente;
    }

    fclose(file);
    return 0;
}

int cargar_lista_empleados(const char *filename, ListaEmpleados *lista) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        return -1; // Error al abrir el archivo
    }

    Empleado *empleado = (Empleado *) malloc(sizeof(Empleado));
    while (fread(empleado, sizeof(Empleado), 1, file) == 1) {
        agregar_empleado(lista, empleado->nombre, empleado->id,  empleado->salario_mensual);
    }

    fclose(file);
    return 0;
}
