/* Video 10 - Operadores logicos en lenguaje C
   &&  (y logico): cierto solo si ambos operandos son ciertos
   ||  (o logico): falso solo si ambos operandos son falsos
   !   (no logico): invierte el valor
   En C el 0 es falso y cualquier otro valor es cierto.
   Ejemplos del video con a = 0, b = 1, c = 2 y la tanda final. */
#include <stdio.h>

int main()
{
    int a = 0, b = 1, c = 2;

    printf("Operador && :\n");
    if (a && b) printf("cierto\n"); else printf("falso\n");                /* falso */
    if (b && c) printf("cierto\n"); else printf("falso\n");                /* cierto */
    if (a == 0 && b > c) printf("cierto\n"); else printf("falso\n");       /* falso */

    printf("\nOperador || :\n");
    if (a || b) printf("cierto\n"); else printf("falso\n");                /* cierto */
    if (b || c) printf("cierto\n"); else printf("falso\n");                /* cierto */
    if (a != 0 || b > c) printf("cierto\n"); else printf("falso\n");       /* falso */

    printf("\nOperador ! :\n");
    if (!a) printf("cierto\n"); else printf("falso\n");                    /* cierto */
    if (!c) printf("cierto\n"); else printf("falso\n");                    /* falso */
    if (!(b > c)) printf("cierto\n"); else printf("falso\n");              /* cierto */

    /* Ejemplos finales del video */
    printf("\nEjemplos finales:\n");
    printf("!(9 > 2)                -> %d\n", !(9 > 2));                   /* 0 */
    printf("!(!(9 > 2))             -> %d\n", !(!(9 > 2)));                /* 1 */
    printf("(1 > 7) || (3 <= 41)    -> %d\n", (1 > 7) || (3 <= 41));       /* 1 */
    printf("(!(9 > 8)) || (6 > 9)   -> %d\n", (!(9 > 8)) || (6 > 9));      /* 0 */
    printf("(9 >= 8) && (4 == 4)    -> %d\n", (9 >= 8) && (4 == 4));       /* 1 */
    printf("(8 >= 9) && (4 == 4)    -> %d\n", (8 >= 9) && (4 == 4));       /* 0 */
    printf("(72 > 4.3) && (7 > 222) -> %d\n", (72 > 4.3) && (7 > 222));    /* 0 */

    return 0;
}
