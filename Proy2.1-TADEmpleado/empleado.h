#ifndef EMPLEADO_H
#define EMPLEADO_H

typedef struct {
    int dia;
    int mes;
    int anio;
} Fecha;

typedef struct {
    char nombre[50];
    char apellido[50];
    int cedula;
    Fecha fechaNacimiento;
} Empleado;

/**
 * @brief Lee la información de un empleado desde la entrada estándar
 * @param empleado Puntero al empleado cuyos datos serán leídos
 */
void leerEmpleado(Empleado *empleado);

/**
 * @brief Imprime la información de un empleado en la salida estándar
 * @param empleado Puntero al empleado cuyos datos serán impresos
 */
void imprimirEmpleado(Empleado *empleado);

/**
 * @brief Obtiene la cédula de un empleado
 * @param empleado Puntero al empleado del que se desea obtener la cédula
 * @return La cédula del empleado
 */
int obtenerCedula(Empleado *empleado);

/**
 * @brief Obtiene la fecha de nacimiento de un empleado
 * @param empleado Puntero al empleado del que se desea obtener la fecha de nacimiento
 * @return La fecha de nacimiento del empleado
 */
Fecha obtenerFechaNacimiento(Empleado *empleado);

#endif // EMPLEADO_H
