#include "arreglo.h"
#include <stdio.h>

int* array_at(array_t* arr, size_t index) {
    if (index >= arr->size) {
        return NULL;
    }
    return &arr->arreglo[index];
}

int array_get(array_t arr, size_t index) {
    if (index >= arr.size) {
        return 0;
    }
    return arr.arreglo[index];
}

void array_set(array_t* arr, size_t index, int value) {
    if (index < arr->size) {
        arr->arreglo[index] = value;
    }
}

int array_front(array_t arr) {
    if (arr.size > 0) {
        return arr.arreglo[0];
    }
    return 0;
}

int array_back(array_t arr) {
    if (arr.size > 0) {
        return arr.arreglo[arr.size - 1];
    }
    return 0;
}

int* array_data(array_t* arr) {
    return &arr->arreglo[0];
}

bool array_empty(array_t arr) {
    return arr.size == 0;
}

size_t array_size(array_t arr) {
    return arr.size;
}

size_t array_max_size(array_t arr) {
    return ARRAY_SIZE;
}

void array_fill(array_t* arr, int value) {
    for (size_t i = 0; i < arr->size; i++) {
    arr->arreglo[i] = value;
    }
}

void array_swap(array_t* arr1, array_t* arr2) {
    array_t temp;
    temp = *arr1;
    *arr1 = *arr2;
    *arr2 = temp;
}

void arreglo_test(array_t* arr) {
    // Usamos las funciones del arreglo para imprimir el arreglo y algunos de sus elementos
    printf("El arreglo es: ");
    for (size_t i = 0; i < array_size(*arr); i++) {
        printf("%d ", array_get(*arr, i));
    }
    printf("\n");
    
    printf("El elemento en la posición 4 es: %d\n", *array_at(arr, 4));
    printf("El puntero a la posición 4 es: %p\n", array_at(arr, 4));
    
    printf("El primer elemento es: %d\n", array_front(*arr));
    
    printf("El último elemento es: %d\n", array_back(*arr));
    
    printf("El puntero al primer elemento es: %p\n", array_data(arr));
    
    printf("El arreglo %s está vacío.\n", array_empty(*arr) ? "" : "no");
    
    printf("El tamaño del arreglo es: %lu\n", array_size(*arr));
    
    printf("El tamaño máximo del arreglo es: %lu\n", array_max_size(*arr));
    
    array_fill(arr, 42);
    printf("El arreglo después de llenarlo con el valor 42 es: ");
    for (size_t i = 0; i < array_size(*arr); i++) {
        printf("%d ", array_get(*arr, i));
    }
    printf("\n");
    
    // Creamos un segundo arreglo con los números del 10 al 1
    array_t arr2 = {{10, 9, 8, 7, 6, 5, 4, 3, 2, 1}, ARRAY_SIZE};
    
    printf("El segundo arreglo es: ");
    for (size_t i = 0; i < array_size(arr2); i++) {
        printf("%d ", array_get(arr2, i));
    }
    printf("\n");
    
    // Intercambiamos el contenido de los dos arreglos
    array_swap(arr, &arr2);
    
    printf("El arreglo después de intercambiar con el segundo arreglo es: ");
    for (size_t i = 0; i < array_size(*arr); i++) {
        printf("%d ", array_get(*arr, i));
    }
    printf("\n");
    
    printf("El segundo arreglo después de intercambiar con el arreglo es: ");
    for (size_t i = 0; i < array_size(arr2); i++) {
        printf("%d ", array_get(arr2, i));
    }
    printf("\n");
}

void arreglo_mostrar (array_t arr){
    for (size_t i = 0; i < array_size(arr); i++) {
        printf("%d ", array_get(arr, i));
    }  printf("\n");
}