/* Video 35 - Calculo del producto vectorial en C
   a) Funcion productoVectorial que recibe tres vectores de 3 reales y guarda
      en el tercero el producto vectorial de los dos primeros.
        v3 = (v1y*v2z - v1z*v2y,  v1z*v2x - v1x*v2z,  v1x*v2y - v1y*v2x)
   b) Programa que pide los componentes de dos vectores y muestra el resultado.
   Los vectores se pasan siempre por referencia: los cambios en v3 permanecen. */
#include <stdio.h>

void productoVectorial(float v1[], float v2[], float v3[])
{
    /* solo calcula; no muestra nada por pantalla */
    v3[0] = v1[1] * v2[2] - v1[2] * v2[1];
    v3[1] = v1[2] * v2[0] - v1[0] * v2[2];
    v3[2] = v1[0] * v2[1] - v1[1] * v2[0];
}

int main()
{
    float a[3], b[3], c[3];

    /* Un vector se lee elemento a elemento (con & por ser float) */
    printf("Componentes del primer vector: ");
    scanf("%f %f %f", &a[0], &a[1], &a[2]);
    printf("Componentes del segundo vector: ");
    scanf("%f %f %f", &b[0], &b[1], &b[2]);

    productoVectorial(a, b, c);   /* sin corchetes; los nombres no tienen que coincidir */

    printf("(%.2f, %.2f, %.2f) x (%.2f, %.2f, %.2f) = (%.2f, %.2f, %.2f)\n",
           a[0], a[1], a[2], b[0], b[1], b[2], c[0], c[1], c[2]);
    return 0;
}
