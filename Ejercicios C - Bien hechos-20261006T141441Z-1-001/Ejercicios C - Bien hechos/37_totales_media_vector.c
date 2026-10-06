/* Video 37 - Totales y media de los elementos de un vector numerico
   1) Funcion sumaElementos: recibe un vector de float y su tamano y devuelve
      la suma total de sus elementos (acumulador inicializado a 0).
      Traza del video: {7.8, 0.2, -1, 2.4, 1.1} -> 7.8, 8, 7, 9.4, 10.5
   2) Variacion: devolver la media (total / tam).
   3) Cuidado: con un vector de enteros, total y tam son int y la division
      seria entera -> hacer un casting a float. */
#include <stdio.h>

float sumaElementos(float v[], int tam)
{
    int i;
    float total = 0;          /* no olvidar inicializarla a 0 */

    for (i = 0; i < tam; i++)
        total += v[i];
    return total;
}

float mediaElementos(float v[], int tam)
{
    int i;
    float total = 0;

    for (i = 0; i < tam; i++)
        total += v[i];
    return total / tam;       /* unica diferencia con la anterior */
}

/* Version para enteros: casting a float para que la division sea real */
float mediaEnteros(int v[], int tam)
{
    int i, total = 0;

    for (i = 0; i < tam; i++)
        total += v[i];
    return (float)total / tam;
}

int main()
{
    float v[5] = {7.8, 0.2, -1, 2.4, 1.1};
    int w[4] = {1, 2, 3, 5};

    printf("Total: %.1f\n", sumaElementos(v, 5));        /* 10.5 */
    printf("Media: %.1f\n", mediaElementos(v, 5));       /* 2.1 */
    printf("Media enteros: %.2f\n", mediaEnteros(w, 4)); /* 2.75 */
    return 0;
}
