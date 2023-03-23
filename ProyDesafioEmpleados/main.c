/**
 * @file main.c
 * @brief Programa de gestión de empleados.
 * Este programa permite crear, modificar, eliminar y buscar empleados de una pequeña empresa,
 * utilizando una lista enlazada para almacenar los datos de los empleados.
 * Curso Programacion 2 - Año 2023 - CeRP del Suroeste
 * 
 * @author Domingo Pérez
 * @date 19/03/2023
 */

#include <stdio.h>
#include <stdlib.h>
#include "file_manager.h"

int main()
{
    ListaEmpleados *lista = crear_lista();

    // Cargar lista de empleados desde el archivo
    if (cargar_lista_empleados("ProyDesafioEmpleados/empleados.data", lista) != 0) {
        printf("Error al cargar el archivo de empleados.\n");
    }

    int opcion = 0;

    while (opcion != 6)
    {
        printf("\n--- MENU ---\n");
        printf("1. Agregar un nuevo empleado\n");
        printf("2. Modificar un empleado existente\n");
        printf("3. Eliminar un empleado\n");
        printf("4. Buscar un empleado\n");
        printf("5. Mostrar la lista completa de empleados\n");
        printf("6. Salir del programa\n");
        printf("Ingrese una opcion: ");

        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
        {
            char nombre[50];
            int id;
            float salario_mensual;
            printf("\nIngrese el nombre del nuevo empleado: ");
            scanf("%s", nombre);
            printf("Ingrese el ID del nuevo empleado: ");
            scanf("%d", &id);
            printf("Ingrese el salario mensual del nuevo empleado: ");
            scanf("%f", &salario_mensual);

            agregar_empleado(lista, nombre, id, salario_mensual);
            printf("\nEmpleado agregado con exito.\n");
            break;
        }
        case 2:
        {
            int id;
            char nuevo_nombre[50];
            float nuevo_salario;
            printf("\nIngrese el ID del empleado que desea modificar: ");
            scanf("%d", &id);

            Empleado *empleado_modificar = buscar_empleado(lista, id);
            if (empleado_modificar == NULL)
            {
                printf("\nEmpleado no encontrado.\n");
            }
            else
            {
                mostrar_empleado(empleado_modificar);
                printf("Ingrese el nuevo nombre del empleado: ");
                scanf("%s", nuevo_nombre);
                printf("Ingrese el nuevo salario mensual del empleado: ");
                scanf("%f", &nuevo_salario);

                int exito_modificacion = modificar_empleado(lista, id, nuevo_nombre, nuevo_salario);
                if (exito_modificacion)
                {
                    printf("\nEmpleado modificado con exito.\n");
                }
                else
                {
                    printf("\nError al modificar el empleado.\n");
                }
            }
            break;
        }
        case 3:
        {
            int id;
            printf("\nIngrese el ID del empleado que desea eliminar: ");
            scanf("%d", &id);

            eliminar_empleado_l(lista, id);
            printf("\nEmpleado eliminado con exito.\n");
            break;
        }
        case 4:
        {
            int id;
            printf("\nIngrese el ID del empleado que desea buscar: ");
            scanf("%d", &id);

            Empleado *empleado_buscar = buscar_empleado(lista, id);
            if (empleado_buscar == NULL)
            {
                printf("\nEmpleado no encontrado.\n");
            }
            else
            {
                mostrar_empleado(empleado_buscar);
            }
            break;
        }
        case 5:
        {
            mostrar_lista(lista);
            break;
        }
        case 6:
        { 
            // Guardar lista de empleados en el archivo
            if (guardar_lista_empleados("ProyDesafioEmpleados/empleados.data", lista) != 0) {
                printf("Error al guardar el archivo de empleados.\n");
            }
            
            liberar_lista(lista);
            printf("\nSaliendo del programa...\n");
            break;
        }
        default:
        {
            printf("\nOpcion invalida. Intente de nuevo.\n");
            break;
        }
        }
    }

    system("pause");

    return 0;
}
