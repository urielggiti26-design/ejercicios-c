/* Video 11 - Sentencia if ... else en lenguaje C
   Ejemplos del video: edad (if simple -> if/else, llaves cuando la sentencia
   tiene mas de una instruccion) y numero de trabajos (if/else anidados). */
#include <stdio.h>

int main()
{
    int edad, trab;

    /* Ejemplo 1: edad */
    printf("Dime tu edad: ");
    scanf("%d", &edad);

    /* Version con dos if:
       if (edad < 18)
           printf("Eres menor\n");
       if (edad >= 18) {
           printf("Eres mayor de edad\n");
           printf("Puedes votar\n");
       }
       Como las condiciones son opuestas, se sustituye por if ... else: */
    if (edad < 18)
        printf("Eres menor\n");             /* una instruccion: llaves opcionales */
    else {
        printf("Eres mayor de edad\n");     /* dos instrucciones: llaves obligatorias */
        printf("Puedes votar\n");
    }

    /* Ejemplo 2: numero de trabajos (if anidados: se ejecuta una y solo una) */
    printf("\nDime cuantos trabajos tienes: ");
    scanf("%d", &trab);

    if (trab < 0)
        printf("Error\n");
    else if (trab == 0)          /* == compara, = asignaria */
        printf("Ponte a buscar\n");
    else if (trab == 1)
        printf("Enhorabuena\n");
    else                         /* no hace falta "else if (trab >= 2)" */
        printf("Eres pluriempleado\n");

    return 0;
}
