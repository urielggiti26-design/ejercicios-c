/* Video 1 - Variables en lenguaje C
   Ejemplos del video: tipos basicos (char, int, float, double), calificadores
   (signed/unsigned, short/long), declaracion de variables (con y sin valor
   inicial, varias en la misma linea) y variables globales/locales. */
#include <stdio.h>

int contador_global = 0;   /* global: se declara fuera de las funciones */

int main()
{
    /* Declaraciones del video */
    int edad;
    float sueldo;
    char inicial;
    unsigned int produccion_diaria;
    unsigned long int produccion_total;

    /* Declarar y despues asignar valor */
    edad = 19;

    /* Varias variables del mismo tipo en una linea, separadas por comas */
    int a = 19, b = 18;
    int x = 9, y, z = 38;          /* y queda indefinida */
    char c1 = 'A', c2;             /* c2 queda indefinida */
    float r1, r2, bp = 3.5;        /* r1 y r2 quedan indefinidas */

    /* signed long int == long int == long */
    signed long int l1 = 100000;
    long int l2 = 100000;
    long l3 = 100000;

    sueldo = 1250.50;
    inicial = 'J';
    produccion_diaria = 150;
    produccion_total = 45000;

    printf("edad = %d, sueldo = %.2f, inicial = %c\n", edad, sueldo, inicial);
    printf("produccion diaria = %u, produccion total = %lu\n",
           produccion_diaria, produccion_total);
    printf("a = %d, b = %d, x = %d, z = %d\n", a, b, x, z);
    printf("c1 = %c, bp = %.1f\n", c1, bp);
    printf("l1 = %ld, l2 = %ld, l3 = %ld\n", l1, l2, l3);
    printf("contador_global = %d\n", contador_global);

    /* Tamano en memoria de cada tipo */
    printf("\nchar: %d bytes, int: %d bytes, float: %d bytes, double: %d bytes\n",
           (int)sizeof(char), (int)sizeof(int), (int)sizeof(float), (int)sizeof(double));

    /* Identificadores del video:
       validos:    area, valor_1, longitud_circulo, _a, valorAuxiliar
       no validos: 2lados (empieza por numero), char (palabra reservada),
                   segunda_posición (tilde), años (ñ), 1medida (empieza por numero) */
    (void)y; (void)c2; (void)r1; (void)r2;
    return 0;
}
