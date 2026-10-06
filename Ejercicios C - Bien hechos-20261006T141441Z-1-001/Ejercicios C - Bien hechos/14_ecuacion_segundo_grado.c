/* Video 14 - Resolucion de ecuaciones de segundo grado en C
   Se piden los terminos a, b y c y se calculan las soluciones segun el
   discriminante D = b^2 - 4ac:
     D == 0 -> una solucion real   -b / 2a
     D >  0 -> dos soluciones reales
     D <  0 -> dos soluciones complejas (parte real e imaginaria)
   (Como en el video, se supone a != 0.) */
#include <stdio.h>
#include <math.h>    /* sqrt */

int main()
{
    float a, b, c, D;

    /* 1. Introduccion de datos */
    printf("Ecuaciones de segundo grado\n");
    printf("ax^2 + bx + c = 0\n\n");
    printf("Introduce el valor de a: ");
    scanf("%f", &a);
    printf("Introduce el valor de b: ");
    scanf("%f", &b);
    printf("Introduce el valor de c: ");
    scanf("%f", &c);

    /* 2. Calculo del discriminante (b*b, tambien valdria pow(b, 2)) */
    D = b * b - 4 * a * c;

    /* 3. Soluciones segun el discriminante */
    if (D == 0)
        printf("Solucion: %.2f\n", -b / (2 * a));
    else if (D > 0) {
        printf("Solucion 1: %.2f\n", (-b + sqrt(D)) / (2 * a));
        printf("Solucion 2: %.2f\n", (-b - sqrt(D)) / (2 * a));
    }
    else {
        printf("Solucion 1: %.2f + %.2fi\n", -b / (2 * a), sqrt(-D) / (2 * a));
        printf("Solucion 2: %.2f - %.2fi\n", -b / (2 * a), sqrt(-D) / (2 * a));
    }

    return 0;
}
