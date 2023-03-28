/**
 * @file medicion_tiempo.c
 * @brief Código para medir el tiempo de ejecución de una función
 * @details Este código mide el tiempo de ejecución de la función "suma"
 *          para distintos valores de N y almacena los tiempos en un arreglo.
 *          Finalmente, imprime los tiempos medidos en pantalla.
 * Unidad: Análisis de Algoritmos
 * Curso: Programación 2
 * Institución: CeRP del Suroeste
 * @date 27 de marzo de 2023
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <math.h>

#define N 2
#define TAM 10000


/**
 * @brief Función que calcula la suma de los primeros n números enteros positivos
 * @param n La cantidad de números enteros positivos a sumar
 * @return La suma de los primeros n números enteros positivos
 */
int sumatoria(int n){
  int res = 0;
  for(int i=1;i<=n;i++){
    res = res + i; // res += i;
  }

  return res;
}

/**
 * @brief Función 2
 * @param arr[] arreglo de numeros
 * @return min el minimo valor del arreglo
 */
int minimo(int arr[]){
  int min = 0;
  min = arr[0];
  for(int i=1;i<TAM;i++){
    if(min>arr[i]) min = arr[i];
  }

  return min;
}

/**
 * @brief Función para determinar el tipo de crecimiento en un arreglo de tiempos medidos
 * 
 * @param tiempos Arreglo de tiempos medidos
 * @param n Tamaño del arreglo
 */

/**
 * Determina el tipo de crecimiento de una secuencia de tiempos.
 *
 * @param tiempos arreglo de tiempos.
 * @param n longitud del arreglo.
 */
void determinar_tipo_crecimiento(int tiempos[], int n) {
  int i;
  double Delta;
  Delta = tiempos[1] - tiempos[0];
  Delta = Delta/tiempos[0];
    
  //printf("\n Delta %f - %d - %d\n", Delta, tiempos[1], tiempos[0]);

  if (fabs(Delta) < 1) {
    printf("Aumento lineal %f\n", fabs(Delta));
  } else if (fabs(Delta) > 1.5) {
    printf("Aumento exponencial %f\n", fabs(Delta));
  } else if (fabs(Delta) < 0.1) {
    printf("Constante\n");
  } else {
    printf("Aumento logaritmico %f\n", fabs(Delta) );
  }
}

/**
 * @brief Función principal
 */
int main() {
  // Definir el arreglo de tiempos y el tamaño de N
  int tiempos[N];
  int n = 10000;

  
  
  // Medir el tiempo para distintos valores de N
  for (int i = 0; i < N; i++) {
    int arreglo[n];
    for(int i=0;i<n;i++){
      arreglo[i]=i+5;
    }
    struct timeval start_time, end_time;
    gettimeofday(&start_time, NULL);
    int resultado = minimo(arreglo);
    gettimeofday(&end_time, NULL);
    tiempos[i] = (end_time.tv_sec - start_time.tv_sec) * 1000000 + (end_time.tv_usec - start_time.tv_usec);
    n *= 2;
  }
  
  
  //int resultado = minimo(arreglo);
  //printf("\n El menor valor es %d\n", resultado);

  // Imprimir los tiempos medidos
  printf("Tiempos de ejecución:\n");
  for (int i = 0; i < N; i++) {
    printf("\t   %d\t", tiempos[i]);
  }

  // Determinar el tipo de crecimiento
  determinar_tipo_crecimiento(tiempos, N);
  
 
  system("pause");
  return 0;
}