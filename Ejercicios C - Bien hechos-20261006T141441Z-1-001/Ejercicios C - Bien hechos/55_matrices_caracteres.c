/* Video 55 - Matrices de caracteres en C
   Una matriz de caracteres se puede tratar como un vector de cadenas:
   nombres[i] es la fila i, es decir, una cadena.
   Funcion tamMaxCad: recibe una matriz de caracteres (una cadena por fila)
   y su numero de filas; muestra la cadena mas larga y devuelve su tamano.
   Basta un solo bucle (no hacen falta dos anidados). */
#include <stdio.h>
#include <string.h>
#define COL 30

int tamMaxCad(char nombres[][COL], int n)
{
    int i, max = 0, iMax = 0;

    for (i = 0; i < n; i++)
        if (strlen(nombres[i]) > max) {
            max = strlen(nombres[i]);
            iMax = i;                     /* posicion de la mas larga */
        }
    printf("Cadena mas larga: %s\n", nombres[iMax]);
    return max;
}

/* Alternativa del video: solo se guarda la posicion iMax */
int tamMaxCad2(char nombres[][COL], int n)
{
    int i, iMax = 0;

    for (i = 1; i < n; i++)
        if (strlen(nombres[i]) > strlen(nombres[iMax]))
            iMax = i;
    printf("Cadena mas larga: %s\n", nombres[iMax]);
    return strlen(nombres[iMax]);
}

int main()
{
    char nombres[6][COL] = {"Enrique Busca",
                            "Jose Gomez Gomez",
                            "Aitana Tarraga Minguez",
                            "Luis Perez",
                            "Ana Gil",
                            "Maria Ruiz Soler"};

    printf("Tamano: %d\n", tamMaxCad(nombres, 6));    /* 22 */
    printf("Tamano: %d\n", tamMaxCad2(nombres, 6));
    return 0;
}
