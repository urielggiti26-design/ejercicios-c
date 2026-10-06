/* Video 41 - Vectores dinamicos en lenguaje C
   Fases: 1) declarar el puntero  2) reservar memoria con malloc
          3) usar el vector con indices  4) liberar con free
   Ejemplo del video: pedir cuantos alumnos hay, reservar un vector dinamico
   para sus notas, pedirlas, mostrar la media y cuantos alumnos la superan. */
#include <stdio.h>
#include <stdlib.h>   /* malloc, free */

int main()
{
    float *v;              /* 1) puntero que controlara el vector */
    float media = 0;
    int n, i, superan = 0;

    printf("Numero de alumnos: ");
    scanf("%d", &n);

    /* 2) n * sizeof(float) bytes; casting a (float *) */
    v = (float *) malloc(n * sizeof(float));

    /* 3) Introduccion de notas y suma para la media */
    for (i = 0; i < n; i++) {
        printf("Nota del alumno %d: ", i);
        scanf("%f", &v[i]);
        media += v[i];
    }
    media = media / n;     /* (convendria comprobar que n != 0) */

    for (i = 0; i < n; i++)
        if (v[i] > media)
            superan++;

    printf("Media: %.2f\n", media);
    printf("Alumnos por encima de la media: %d\n", superan);

    /* 4) Liberar la memoria cuando ya no se usa el vector */
    free(v);
    return 0;
}
