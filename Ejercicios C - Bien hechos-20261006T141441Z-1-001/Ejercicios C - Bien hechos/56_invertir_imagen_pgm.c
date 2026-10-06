/* Video 56 - Invertir una imagen pgm
   Formato PGM de texto:  P2 / columnas filas / nivel maximo de gris (255) /
   los pixeles (0 = negro, 255 = blanco).
   1) Cargar imagen.pgm en una matriz (y obtener filas y columnas).
   2) Invertir la imagen: cada pixel pasa a ser 255 - pixel.
   3) Guardar el resultado en imagen2.pgm.
   Se asumen imagenes de 256 tonos y como maximo 256 x 256 pixeles.
   Las funciones de fichero devuelven -1 si hay error y 0 si todo va bien. */
#include <stdio.h>
#define MAX 256

int cargarImagen(int m[][MAX], int *fil, int *col)
{
    FILE *f;
    char tipo[3];
    int i, j, nf, nc, gris;

    f = fopen("imagen.pgm", "r");
    if (f == NULL)
        return -1;

    fscanf(f, "%s", tipo);           /* P2 */
    fscanf(f, "%d %d", &nc, &nf);    /* columnas y filas */
    fscanf(f, "%d", &gris);          /* nivel maximo de gris */

    for (i = 0; i < nf; i++)
        for (j = 0; j < nc; j++)
            fscanf(f, "%d", &m[i][j]);

    *fil = nf;                       /* parametros por referencia */
    *col = nc;
    fclose(f);
    return 0;
}

void invertirImagen(int m[][MAX], int fil, int col)
{
    int i, j;

    for (i = 0; i < fil; i++)
        for (j = 0; j < col; j++)
            m[i][j] = 255 - m[i][j];     /* gris complementario */
}

int guardarImagen(int m[][MAX], int fil, int col)
{
    FILE *f;
    int i, j;

    f = fopen("imagen2.pgm", "w");
    if (f == NULL)
        return -1;

    fprintf(f, "P2\n");
    fprintf(f, "%d %d\n", col, fil);
    fprintf(f, "255\n");
    for (i = 0; i < fil; i++) {
        for (j = 0; j < col; j++)
            fprintf(f, "%d ", m[i][j]);  /* espacio entre valores */
        fprintf(f, "\n");                /* salto al acabar cada fila */
    }
    fclose(f);
    return 0;
}

int main()
{
    int imagen[MAX][MAX];
    int fil, col;

    if (cargarImagen(imagen, &fil, &col) == 0) {
        invertirImagen(imagen, fil, col);
        if (guardarImagen(imagen, fil, col) == 0)
            printf("Imagen invertida guardada en imagen2.pgm\n");
        else
            printf("Error al guardar la imagen\n");
    }
    else
        printf("Error al cargar la imagen\n");

    return 0;
}
