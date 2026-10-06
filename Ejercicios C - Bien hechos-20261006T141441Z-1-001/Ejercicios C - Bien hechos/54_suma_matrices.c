/* Video 54 - Suma de matrices en lenguaje C
   Funcion sumaMat que recibe tres matrices de reales (a, b y c) y sus
   dimensiones (f filas y c columnas) y guarda en c la suma a + b, elemento
   a elemento: c[i][j] = a[i][j] + b[i][j].
   En la cabecera la 2a dimension es obligatoria (constante COL).
   Ejemplo de uso: matrices 2x2; p. ej. 2 + (-1) = 1 y 10 + 9 = 19. */
#include <stdio.h>
#define FIL 2
#define COL 2

void sumaMat(float a[][COL], float b[][COL], float c[][COL], int f, int col)
{
    int i, j;

    for (i = 0; i < f; i++)            /* filas */
        for (j = 0; j < col; j++)      /* columnas */
            c[i][j] = a[i][j] + b[i][j];
}

int main()
{
    /* los valores entre llaves se asignan fila a fila */
    float a[FIL][COL] = {{2, 10}, {3, 4}};
    float b[FIL][COL] = {{-1, 9}, {5, 2}};
    float c[FIL][COL];
    int i, j;

    sumaMat(a, b, c, FIL, COL);   /* solo el nombre de las matrices */

    /* Mostrar el resultado */
    for (i = 0; i < FIL; i++) {
        for (j = 0; j < COL; j++)
            printf("%.1f ", c[i][j]);
        printf("\n");
    }
    return 0;
}
