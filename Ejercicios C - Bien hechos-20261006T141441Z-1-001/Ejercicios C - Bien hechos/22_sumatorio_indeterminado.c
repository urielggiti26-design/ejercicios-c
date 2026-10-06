/* Video 22 - Sumatorio de un numero indeterminado de valores
   El usuario introduce enteros positivos; con 0 termina. Los negativos se
   indican como error y no se suman. Ej: 12, 28, -3 (error), 5, 0 -> 45
   Ampliacion del video: mostrar tambien la media de los valores validos. */
#include <stdio.h>

int main()
{
    int valor = 1;      /* distinto de 0 para entrar la primera vez en el while */
    int total = 0;      /* acumulador: hay que inicializarlo a 0 */
    int cantidad = 0;   /* cuantos valores correctos se han introducido */

    printf("Introduce valores enteros positivos (0 para terminar)\n");
    while (valor != 0) {
        printf("Valor: ");
        scanf("%d", &valor);
        if (valor < 0)
            printf("Error: valor negativo\n");
        else if (valor > 0) {      /* el 0 solo sirve para salir */
            total += valor;        /* total = total + valor */
            cantidad++;
        }
    }

    printf("Sumatorio: %d\n", total);
    if (cantidad > 0)
        /* (float) para que la division sea real y no entera */
        printf("Media: %.2f\n", (float)total / cantidad);

    return 0;
}
