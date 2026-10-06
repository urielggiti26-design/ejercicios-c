/* Video 2 - Operadores aritmeticos en lenguaje C
   Ejemplos del video: pre/post incremento, tipo del resultado segun los
   operandos, division entera vs real, resto y precedencia. */
#include <stdio.h>

int main()
{
    int a = 3, b = 3, r1, r2;

    /* ++ como pre-operador y como post-operador */
    r1 = ++a;   /* primero incrementa a (4) y despues lo devuelve: r1 = 4 */
    r2 = b++;   /* primero devuelve b (3) y despues lo incrementa: r2 = 3 */
    printf("a = %d, b = %d\n", a, b);       /* a = 4, b = 4 */
    printf("r1 = %d, r2 = %d\n\n", r1, r2); /* r1 = 4, r2 = 3 */

    /* Tipo del resultado segun el tipo de los operandos */
    printf("0.05 + 1 = %.2f\n", 0.05 + 1);  /* real + entero -> real: 1.05 */
    printf("-4 + 8   = %d\n", -4 + 8);      /* entero + entero -> entero: 4 */
    printf("10 / 5   = %d\n", 10 / 5);      /* division entera: 2 */
    printf("11 / 5   = %d\n", 11 / 5);      /* division entera: 2 (se pierde el ,2) */
    printf("11 / 5.0 = %.1f\n", 11 / 5.0);  /* division real: 2.2 */
    printf("11 %% 5   = %d\n\n", 11 % 5);   /* resto de la division entera: 1 */

    /* Precedencia: ++ -- ; luego * / % ; luego + -  (izquierda a derecha) */
    int w = 2, x = 3, y = 8, z = 4, v = 1;
    /* w * x + y / z - v  ->  ((w * x) + (y / z)) - v  = 6 + 2 - 1 = 7 */
    printf("w * x + y / z - v = %d\n", w * x + y / z - v);
    /* Los parentesis cambian la precedencia */
    printf("w * (x + y) / (z - v) = %d\n", w * (x + y) / (z - v));

    return 0;
}
