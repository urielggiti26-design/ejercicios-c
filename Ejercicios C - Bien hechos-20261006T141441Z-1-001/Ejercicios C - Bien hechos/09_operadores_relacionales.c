/* Video 9 - Operadores relacionales en lenguaje C
   >  <  >=  <=  ==  !=   Devuelven 1 (cierto) o 0 (falso).
   Precedencia: aritmeticos > (> < >= <=) > (== !=); a igual precedencia,
   de izquierda a derecha. Todas las expresiones son las del video. */
#include <stdio.h>

int main()
{
    int v = 3;

    printf("Ejemplos sencillos:\n");
    printf("4 < 5            -> %d\n", 4 < 5);         /* 1 */
    printf("5.7 <= 6         -> %d\n", 5.7 <= 6);      /* 1 */
    printf("'x' == 'w'       -> %d\n", 'x' == 'w');    /* 0: codigos ASCII distintos */
    printf("v != 7 (v = 3)   -> %d\n\n", v != 7);      /* 1 */

    printf("Primera tanda:\n");
    printf("27 <= 21         -> %d\n", 27 <= 21);      /* 0 */
    printf("'4' < 'e'        -> %d\n", '4' < 'e');     /* 52 < 101 -> 1 */
    printf("'d' < -23        -> %d\n", 'd' < -23);     /* ASCII entre 0 y 255 -> 0 */
    printf("(4 / 5) > 0      -> %d\n", (4 / 5) > 0);   /* division entera 0 > 0 -> 0 */
    printf("8.05 != 8        -> %d\n", 8.05 != 8);     /* 1 */
    /* 7 =< 7  -> error de compilacion: el igual va detras ( <= ) */
    printf("'A' == 'a'       -> %d\n\n", 'A' == 'a');  /* 65 != 97 -> 0 */

    printf("Segunda tanda (con operadores aritmeticos):\n");
    printf("2 == 5 / 2       -> %d\n", 2 == 5 / 2);        /* 2 == 2 -> 1 */
    printf("(2 == 5) / 2     -> %d\n", (2 == 5) / 2);      /* 0 / 2 -> 0 */
    printf("1 == 8 > 2       -> %d\n", 1 == 8 > 2);        /* 1 == 1 -> 1 */
    printf("2 + 1 < 3 %% 7    -> %d\n", 2 + 1 < 3 % 7);    /* 3 < 3 -> 0 */
    /* 7 > 6 > 5 no es como en matematicas: (7 > 6) -> 1 y 1 > 5 -> 0 */
    printf("7 > 6 > 5        -> %d\n", (7 > 6) > 5);       /* 0 */
    printf("5 < 6 < 7        -> %d\n", (5 < 6) < 7);       /* 1 */

    return 0;
}
