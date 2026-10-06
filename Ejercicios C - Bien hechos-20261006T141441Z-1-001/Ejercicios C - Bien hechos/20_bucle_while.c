/* Video 20 - Implementacion de bucles en C con while
   La condicion se comprueba ANTES de cada iteracion (minimo 0 iteraciones).
   Ejemplo 1: mostrar los numeros del 1 al 3.
   Ejemplo 2 (condicion compuesta): mostrar los multiplos de 3 entre dos
   limites pedidos al usuario, hasta un maximo de 5 multiplos. */
#include <stdio.h>

int main()
{
    int i, inf, sup, total;

    /* ---- Ejemplo 1 ---- */
    i = 1;
    while (i <= 3) {          /* sin ; despues del parentesis */
        printf("%d\n", i);
        i++;
    }

    /* ---- Ejemplo 2 ---- */
    printf("\nLimite inferior: ");
    scanf("%d", &inf);
    printf("Limite superior: ");
    scanf("%d", &sup);

    total = 0;               /* cuantos multiplos se han mostrado */
    i = inf;
    while (i <= sup && total < 5) {
        if (i % 3 == 0) {    /* es multiplo de 3 */
            printf("%d ", i);
            total++;
        }
        i++;
    }
    printf("\n");

    return 0;
}
