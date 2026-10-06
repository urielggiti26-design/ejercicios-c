/* Video 32 - Evaluacion de numeros primos en lenguaje C
   Programa que muestra los numeros primos inferiores a 500.
   1) Funcion primo(n): devuelve 1 si n es primo y 0 si no lo es.
   2) Recorrer los numeros de 0 a 499 mostrando los que son primos.
   Mejora de eficiencia del video: basta buscar divisores hasta la raiz de n
   (para 104729: 322 comprobaciones en lugar de 104728). */
#include <stdio.h>
#include <math.h>    /* sqrt */

/* Primera version (correcta pero poco eficiente): divisores de 2 a n-1 */
int primo_v1(int n)
{
    int i;

    if (n < 2)               /* un primo tiene que ser mayor que 1 */
        return 0;
    for (i = 2; i < n; i++)
        if (n % i == 0)      /* tiene un divisor: no es primo */
            return 0;
    return 1;
}

/* Version mejorada: divisores de 2 hasta la raiz cuadrada de n */
int primo(int n)
{
    int i;

    if (n < 2)
        return 0;
    for (i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return 0;
    return 1;
}

int main()
{
    int i;

    for (i = 0; i < 500; i++)
        if (primo(i))
            printf("%d ", i);
    printf("\n");

    return 0;
}
