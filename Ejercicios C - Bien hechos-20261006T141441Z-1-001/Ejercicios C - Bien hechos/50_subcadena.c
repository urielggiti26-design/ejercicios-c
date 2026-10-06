/* Video 50 - Obtencion de una subcadena a partir de una cadena
   Funcion subcadena(cad, subcad, ini, fin): copia en subcad los caracteres
   de cad desde la posicion ini hasta la posicion fin (ambas incluidas).
   Devuelve 0 si hay problemas con los indices y 1 si todo va bien.
   Ej: cad = "Adriana", ini = 2, fin = 4 -> subcad = "ria"
   Se usan dos indices: i recorre la cadena origen y j la de destino. */
#include <stdio.h>
#include <string.h>   /* strlen */

int subcadena(char cad[], char subcad[], int ini, int fin)
{
    int i, j;

    /* Indices incoherentes */
    if (ini > fin || ini < 0 || fin >= strlen(cad))
        return 0;

    j = 0;
    for (i = ini; i <= fin; i++) {
        subcad[j] = cad[i];
        j++;
    }
    subcad[j] = '\0';    /* fin de cadena */

    return 1;
}

int main()
{
    char c1[10] = "Adriana", c2[10];

    if (subcadena(c1, c2, 2, 4) == 0)
        printf("Error en los indices\n");
    else
        printf("%s\n", c2);    /* ria */

    return 0;
}
