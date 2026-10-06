/* Video 53 - Recorrido de matrices en lenguaje C
   Recorrido habitual: fila a fila y, dentro de cada fila, columna a columna
   (dos for anidados: el externo recorre filas y el interno columnas).
   Ejercicio: funcion maxMatriz que recibe una matriz de enteros y sus
   dimensiones y devuelve el valor maximo.
   Max se inicializa con m[0][0] (no con 0: fallaria si todos son negativos).
   Variacion: el minimo (solo cambia > por <). */
#include <stdio.h>
#define F 3
#define C 4

int maxMatriz(int m[][C], int fil, int col)   /* la 1a dimension puede ir vacia */
{
    int i, j, max;

    max = m[0][0];
    for (i = 0; i < fil; i++)
        for (j = 0; j < col; j++)
            if (m[i][j] > max)
                max = m[i][j];
    return max;
}

int minMatriz(int m[][C], int fil, int col)
{
    int i, j, min;

    min = m[0][0];
    for (i = 0; i < fil; i++)
        for (j = 0; j < col; j++)
            if (m[i][j] < min)
                min = m[i][j];
    return min;
}

int main()
{
    int m[F][C] = {{23, 45, 76, 11},
                   {98, 34, 12, 57},
                   {64,  5, 87, 30}};

    printf("Maximo: %d\n", maxMatriz(m, F, C));   /* 98 */
    printf("Minimo: %d\n", minMatriz(m, F, C));   /* 5 */
    return 0;
}
