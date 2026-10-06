/* Video 33 - Media de valores enteros mediante funciones
   1) Funcion media que recibe tres enteros y devuelve su media aritmetica.
      Ejemplo de uso del video: media(-4, 7, 1) -> 1.33
   2) Modificacion: la funcion recibe un vector de enteros y su tamano.
      (En el video ambas se llaman media; aqui la segunda se llama mediaVector
      porque en C no puede haber dos funciones con el mismo nombre.) */
#include <stdio.h>

/* Solucion 1: con variable auxiliar.
   Se divide entre 3.0 para que la division sea real (con 3 seria entera y daria 1) */
float media(int a, int b, int c)
{
    float m;

    m = (a + b + c) / 3.0;
    return m;
}

/* Alternativa: todo en el return
float media(int a, int b, int c)
{
    return (a + b + c) / 3.0;
}
*/

/* Modificacion: media de los elementos de un vector de tam elementos */
float mediaVector(int v[], int tam)
{
    int i;
    float m = 0;

    for (i = 0; i < tam; i++)
        m += v[i];
    return m / tam;
}

int main()
{
    int i1 = -4, i2 = 7, i3 = 1;
    float f;
    int v[5] = {-4, 7, 1, 10, 6};

    /* aqui se declararia la funcion pedida (zona del comentario del video) */
    f = media(i1, i2, i3);
    printf("Media: %.2f\n", f);

    /* main equivalente, sin variables: printf("Media: %.2f\n", media(-4, 7, 1)); */

    printf("Media del vector: %.2f\n", mediaVector(v, 5));
    return 0;
}
