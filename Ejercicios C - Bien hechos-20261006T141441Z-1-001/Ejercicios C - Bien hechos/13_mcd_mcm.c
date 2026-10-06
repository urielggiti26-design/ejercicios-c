/* Video 13 - Maximo comun divisor y minimo comun multiplo
   Enunciado: funcion que reciba dos enteros (> 0) y devuelva el MCD y el MCM.
   Como hay que devolver dos valores, se usan parametros por referencia.
   Estrategia: revisar los divisores comunes desde 1 hasta la mitad del menor
   y quedarse con el mayor.  MCM = a * b / MCD.
   Ej: mcd(12, 16) = 4, mcm(12, 16) = 48 */
#include <stdio.h>

void mcd_mcm(int a, int b, int *mcd, int *mcm)
{
    int i, aux;

    /* Basta con mirar hasta la mitad del menor de los dos valores */
    if (a < b)
        aux = a / 2;
    else
        aux = b / 2;

    *mcd = 1;
    for (i = 1; i <= aux; i++)
        if (a % i == 0 && b % i == 0)   /* i divide a ambos */
            *mcd = i;                   /* nos quedamos con el mayor hasta ahora */

    /* Caso en que el menor divide al mayor (p. ej. 4 y 8): el MCD es el menor */
    if (a % b == 0)
        *mcd = b;
    else if (b % a == 0)
        *mcd = a;

    *mcm = a * b / *mcd;
}

/* Alternativa del video: trabajar con variables locales y copiar al final
   en los parametros por referencia (evita poner * en cada uso). */
void mcd_mcm_v2(int a, int b, int *mcd, int *mcm)
{
    int i, aux, m = 1;

    aux = (a < b) ? a / 2 : b / 2;
    for (i = 1; i <= aux; i++)
        if (a % i == 0 && b % i == 0)
            m = i;
    if (a % b == 0) m = b;
    else if (b % a == 0) m = a;

    *mcd = m;
    *mcm = a * b / m;
}

/* Ejemplo de uso */
int main()
{
    int x, y, mcd, mcm;

    printf("Dame dos numeros enteros positivos: ");
    scanf("%d %d", &x, &y);

    mcd_mcm(x, y, &mcd, &mcm);   /* se pasan las direcciones con & */
    printf("MCD = %d\n", mcd);
    printf("MCM = %d\n", mcm);

    return 0;
}
