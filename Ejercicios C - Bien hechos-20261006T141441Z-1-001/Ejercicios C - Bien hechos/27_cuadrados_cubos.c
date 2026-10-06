/* Video 27 - Cuadrados y cubos de numeros naturales
   Mostrar por pantalla los 10 primeros numeros naturales con su cuadrado y
   su cubo. Ampliacion del video: guardar tambien los datos en cubos.txt.
   (Alternativa: pow(i, 2) y pow(i, 3) de math.h, que devuelven double
   y se muestran con %.0f.) */
#include <stdio.h>

int main()
{
    int i;
    FILE *f;

    f = fopen("cubos.txt", "w");      /* modo w: vamos a escribir */
    if (f == NULL) {
        printf("Error al abrir el fichero\n");
        return 1;
    }

    for (i = 1; i < 11; i++) {        /* equivale a i <= 10 */
        printf("%d %d %d\n", i, i * i, i * i * i);
        fprintf(f, "%d %d %d\n", i, i * i, i * i * i);
    }

    fclose(f);
    return 0;
}
