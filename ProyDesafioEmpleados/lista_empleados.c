#include "lista_empleados.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

ListaEmpleados* crear_lista() {
    ListaEmpleados* lista = (ListaEmpleados*)malloc(sizeof(ListaEmpleados));
    lista->cabeza = NULL;
    lista->longitud = 0;
    
    return lista;
    //return NULL;
}

void agregar_empleado(ListaEmpleados* lista, const char* nombre, int id, float salario_mensual) {
    Nodo* nuevo_nodo = (Nodo*)malloc(sizeof(Nodo));
    Empleado *nuevo_empleado = crear_empleado(nombre, id, salario_mensual);
    nuevo_nodo->empleado = nuevo_empleado;
    nuevo_nodo->siguiente = lista->cabeza;
    lista->cabeza = nuevo_nodo;
    lista->longitud++;
}

Empleado* buscar_empleado(const ListaEmpleados* lista, int id) {
    Nodo* actual = lista->cabeza;
    while (actual != NULL) {
        if (actual->empleado->id == id) {
            return (actual->empleado);
        }
        actual = actual->siguiente;
    }
    return NULL;
}

int modificar_empleado(ListaEmpleados* lista, int id, char nuevoNombre[], float nuevoSalario) {
    Empleado* empleado_modificar = buscar_empleado(lista, id);
    if (empleado_modificar != NULL) {
        strcpy(empleado_modificar->nombre, nuevoNombre);
        empleado_modificar->salario_mensual = nuevoSalario;
        return 1;
    }
    return 0;
}

void eliminar_empleado_l(ListaEmpleados* lista, int id) {
    Nodo* actual = lista->cabeza;
    Nodo* anterior = NULL;
    while (actual != NULL) {
        if (actual->empleado->id == id) {
            if (anterior == NULL) {
                lista->cabeza = actual->siguiente;
            } else {
                anterior->siguiente = actual->siguiente;
            }
            eliminar_empleado(actual->empleado);
            free(actual);
            lista->longitud--;
            return;
        }
        anterior = actual;
        actual = actual->siguiente;
    }
}

void mostrar_lista(const ListaEmpleados* lista) {
    printf("Lista de empleados:\n");
    Nodo* actual = lista->cabeza;
    while (actual != NULL) {
        mostrar_empleado(actual->empleado);
        actual = actual->siguiente;
    }
}

void liberar_lista(ListaEmpleados* lista) {
    /*Nodo* actual = lista->cabeza;
    while (actual != NULL) {
        Nodo* siguiente = actual->siguiente;
        eliminar_empleado(actual->empleado);
        free(actual);
        actual = siguiente;
    }*/
    free(lista);
}
