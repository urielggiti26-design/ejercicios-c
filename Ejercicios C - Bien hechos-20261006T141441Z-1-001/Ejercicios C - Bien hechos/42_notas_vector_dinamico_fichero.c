/* Video 42 - Cargar notas en un vector dinamico a partir de un fichero con
   una cantidad indeterminada de valores
   notas.txt tiene calificaciones (no se sabe cuantas). Cargarlas en un
   vector dinamico y mostrar su contenido.
   Problema: para reservar memoria hay que saber cuantas notas hay, y para
   saberlo hay que leer el fichero entero. Solucion: recorrer el fichero
   DOS veces (al cerrarlo y volver a abrirlo se empieza desde el principio). */
#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *f;
    float *v, nota;
    int total = 0, i;

    /* 1er recorrido: contar las notas */
    f = fopen("notas.txt", "r");
    if (f == NULL) {
        printf("Error al abrir el fichero\n");
        return 1;
    }
    while (fscanf(f, "%f", &nota) == 1)
        total++;
    fclose(f);

    if (total == 0) {
        printf("No hay notas en el fichero\n");
        return 0;
    }

    /* Reservar memoria para total notas */
    v = (float *) malloc(total * sizeof(float));
    if (v == NULL) {
        printf("Error al reservar memoria\n");
        return 1;
    }

    /* 2o recorrido: guardar las notas (ya sabemos cuantas hay: for) */
    f = fopen("notas.txt", "r");
    if (f == NULL) {
        printf("Error al abrir el fichero\n");
        free(v);
        return 1;
    }
    for (i = 0; i < total; i++)
        fscanf(f, "%f", &v[i]);
    fclose(f);

    /* Mostrar el vector */
    for (i = 0; i < total; i++)
        printf("v[%d] = %.2f\n", i, v[i]);

    free(v);   /* liberar la memoria reservada */
    return 0;
}
