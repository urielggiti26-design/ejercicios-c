/* Video 34 - Traza de llamadas a funciones
   Que muestra este codigo por pantalla? Cual es el cometido de f1 y de f2?
   Traza (se empieza por main):
     vec = {6, -4, -2, 7, 12}
     f1(vec, 5): x = 6; i=1 -> -4 < 6 -> x = -4; ningun otro es menor -> devuelve -4
       => muestra "f1: -4"
     f2(vec, 5, 7): i=0 (6), i=1 (-4), i=2 (-2) distintos de 7; i=3 -> 7 == 7 -> return 1
       => la condicion se cumple y muestra "Si"
   Cometido: f1 devuelve el valor minimo de un vector;
             f2 busca un valor y devuelve 1 si esta y 0 si no esta. */
#include <stdio.h>

int f1(int v[], int t)
{
    int i, x;

    x = v[0];
    for (i = 0; i < t; i++)
        if (v[i] < x)
            x = v[i];
    return x;
}

int f2(int v[], int t, int x)
{
    int i;

    for (i = 0; i < t; i++)
        if (v[i] == x)
            return 1;     /* return termina la funcion en ese momento */
    return 0;
}

int main()
{
    int vec[5] = {6, -4, -2, 7, 12};

    printf("f1: %d\n", f1(vec, 5));
    if (f2(vec, 5, 7) == 1)
        printf("Si\n");
    else
        printf("No\n");

    return 0;
}
