/**
 * @file main.c
 * @brief Codigo del tema nocion de orden de algoritmos
 * @details Este codigo plantea una solucion del tema nocion de orden de algoritmos
 * Unidad: Analisis de Algoritmos
 * Curso: Programacion 2
 * Institucion: CeRP del Suroeste
 * @date 10 de abril de 2023
 * 
 */

/**
 * @brief Ejemplo de primer Doxygen con enlace a contenido externo.
 * En este ejemplo se muestra como incluir un enlace a contenido externo en Doxygen.
 * Puedes consultar la \link https://www.1001problemas.com pagina de problemas de Lenguaje C \endlink
 * para encontrar ejercicios y soluciones en C.
 * @author Domingo Perez
 * @date 19/03/2023
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

// Funcion ingresarVentas
void ingresarVentas(float ventas[], int numDias)
{
    int i;
    for (i = 0; i < numDias; i++)
    {
        printf("Ingrese las ventas del dia %d: ", i + 1);
        scanf("%f", &ventas[i]);
    }
}

// Funcion calcularPromedio
float calcularPromedio(float ventas[], int numDias)
{
    float suma = 0;
    int i;
    for (i = 0; i < numDias; i++)
        suma += ventas[i];
    return suma / numDias;
}

// Funcion buscarMaximo
float buscarMaximo(float ventas[], int numDias)
{
    float maximo = ventas[0];
    int i;
    for (i = 1; i < numDias; i++)
        if (ventas[i] > maximo)
            maximo = ventas[i];
    return maximo;
}

// Funcion buscarMinimo
float buscarMinimo(float ventas[], int numDias) {
    float minimo = ventas[0];
    for (int i = 1; i < numDias; i++) {
        if (ventas[i] < minimo) {
            minimo = ventas[i];
        }
    }
    return minimo;
}

// Funcion buscarVenta
int buscarVenta(float ventas[], int numDias, float venta) {
    int inicio = 0, fin = numDias-1, medio;
    while (inicio <= fin) {
        medio = (inicio + fin) / 2;
        if (ventas[medio] == venta) {
            return medio;
        } else if (ventas[medio] < venta) {
            inicio = medio + 1;
        } else {
            fin = medio - 1;
        }
    }
    return -1;
}

// Funcion buscarVentaExponencial
int buscarVentaExponencial(float ventas[], int numDias, float venta) {
    if (numDias == 0) {
        return -1;
    }
    if (ventas[numDias-1] == venta) {
        return numDias-1;
    }
    float ultimo = ventas[numDias-1];
    ventas[numDias-1] = venta;
    int i = 0;
    while (ventas[i] != venta) {
        i++;
    }
    ventas[numDias-1] = ultimo;
    if (i < numDias-1 || ventas[numDias-1] == venta) {
        return i;
    }
    return -1;
}



int main()
{ 
    int numDias;
    float ventas[100], venta, promedio, maximo, minimo;
    int encontrado, encontradoExponencial;

    // Pedimos al usuario el número de dias
    printf("Ingrese el numero de dias a registrar: ");
    scanf("%d", &numDias);

    // Ingresamos las ventas de cada dia
    ingresarVentas(ventas, numDias);

    // Calculamos el promedio de ventas
    promedio = calcularPromedio(ventas, numDias);
    printf("El promedio de ventas es: %.2f\n", promedio);

    // Buscamos el maximo de las ventas
    maximo = buscarMaximo(ventas, numDias);
    printf("La venta maxima es: %.2f\n", maximo);

    // Buscamos el minimo de las ventas
    minimo = buscarMinimo(ventas, numDias);
    printf("La venta minima es: %.2f\n", minimo);

    // Buscamos una venta especifica
    printf("Ingrese una venta a buscar: ");
    scanf("%f", &venta);
    encontrado = buscarVenta(ventas, numDias, venta);
    if (encontrado == -1)
        printf("La venta no se encontro.\n");
    else
        printf("La venta se encontro en el dia %d.\n", encontrado);

    // Buscamos una venta especifica de manera exponencial
    printf("Ingrese una venta a buscar (metodo exponencial): ");
    scanf("%f", &venta);
    encontradoExponencial = buscarVentaExponencial(ventas, numDias, venta);
    if (encontradoExponencial == -1)
        printf("La venta no se encontro.\n");
    else
        printf("La venta se encontro en el dia %d.\n", encontradoExponencial);

  system("pause");
  return 0;
}




