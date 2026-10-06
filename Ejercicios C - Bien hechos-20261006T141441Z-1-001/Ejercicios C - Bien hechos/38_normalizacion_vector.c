/* Video 38 - Normalizacion de los datos de un vector
   Funcion que recibe un vector de reales y su tamano y normaliza su
   contenido al intervalo [0, 1]:
        v[i] = (v[i] - min) / (max - min)
   El minimo pasa a ser 0 y el maximo 1. (Nombre sin tilde: "Normalizacion".)
   Ejemplo de uso del video: vector de 6 elementos, minimo 4 y maximo 12. */
#include <stdio.h>

void Normalizacion(float v[], int tam)
{
    int i;
    float min, max, amp;

    /* 1. Minimo y maximo: se parte del primer elemento */
    min = v[0];
    max = v[0];
    for (i = 1; i < tam; i++)
        if (v[i] < min)
            min = v[i];
        else if (v[i] > max)
            max = v[i];

    /* 2. La amplitud se calcula una sola vez */
    amp = max - min;

    /* 3. Normalizar cada elemento (el vector se pasa por referencia,
          asi que los cambios permanecen al volver de la funcion) */
    for (i = 0; i < tam; i++)
        v[i] = (v[i] - min) / amp;
}

int main()
{
    float v[6] = {10, 5, 4, 12, 7, 9};
    int i;

    Normalizacion(v, 6);

    for (i = 0; i < 6; i++)
        printf("%.3f ", v[i]);
    printf("\n");
    return 0;
}
