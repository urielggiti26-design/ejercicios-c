/* Video 26 - Implementacion de bucles en C con for
   for (inicializacion; condicion; actualizacion)
   Ejemplo 1: cuenta atras de 3 a 0.
   Ejemplo 2: numeros naturales menores que 200 multiplos de 3 y de 7,
   con dos alternativas (la segunda mas eficiente). */
#include <stdio.h>

int main()
{
    int i;

    /* ---- Ejemplo 1: cuenta atras ---- */
    for (i = 3; i >= 0; i--)
        printf("%d\n", i);

    /* ---- Ejemplo 2, alternativa 1: 199 iteraciones, 2 comprobaciones ---- */
    printf("\nMultiplos de 3 y 7 menores que 200 (alternativa 1):\n");
    for (i = 1; i < 200; i++)
        if (i % 3 == 0 && i % 7 == 0)
            printf("%d ", i);

    /* ---- Ejemplo 2, alternativa 2: i va de 7 en 7 (siempre multiplo de 7);
            28 iteraciones y 1 comprobacion ---- */
    printf("\n\nMultiplos de 3 y 7 menores que 200 (alternativa 2):\n");
    for (i = 7; i < 200; i += 7)
        if (i % 3 == 0)
            printf("%d ", i);
    printf("\n");

    return 0;
}
