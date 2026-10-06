/* Video 39 - Busqueda de maximo y minimo en un vector
   1) Funcion que devuelve el maximo: se parte del primer elemento y se
      actualiza si se encuentra uno mayor.
   2) Funcion que devuelve el minimo (igual, comparando con <).
   3) Una sola funcion que devuelve los dos valores mediante dos parametros
      por referencia. */
#include <stdio.h>

/* 1) y 2): una funcion para cada valor */
int Minimo(int v[], int tam)
{
    int i, min = v[0];

    for (i = 1; i < tam; i++)
        if (v[i] < min)
            min = v[i];
    return min;
}

int Maximo(int v[], int tam)
{
    int i, max = v[0];

    for (i = 1; i < tam; i++)
        if (v[i] > max)
            max = v[i];
    return max;
}

/* 3) Una sola funcion: maximo y minimo por referencia */
void MaxMin(int v[], int tam, int *max, int *min)
{
    int i;

    *max = v[0];
    *min = v[0];
    for (i = 1; i < tam; i++)
        if (v[i] > *max)
            *max = v[i];
        else if (v[i] < *min)
            *min = v[i];
}

int main()
{
    int valores[] = {12, 45, 2, 89, 4, 23};
    int tam = 6, maximo, minimo;

    printf("Con dos funciones -> max: %d  min: %d\n", Maximo(valores, tam), Minimo(valores, tam));

    MaxMin(valores, tam, &maximo, &minimo);
    printf("Con punteros      -> max: %d  min: %d\n", maximo, minimo);
    return 0;
}
