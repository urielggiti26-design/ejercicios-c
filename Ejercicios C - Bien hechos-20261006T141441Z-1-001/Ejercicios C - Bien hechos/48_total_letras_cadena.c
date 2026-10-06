/* Video 48 - Calculo del total de letras de una cadena
   Funcion que devuelve cuantas letras tiene una cadena (sin contar espacios,
   comas, puntos...). Ej. del video: "Begoña, díselo por favor" -> 20 letras.
   1) Recorrer la cadena con un contador y un if con todas las letras
      posibles (condicion demasiado larga).
   2) Alternativa con los rangos ASCII 'a'-'z' y 'A'-'Z' (no cuenta la ñ ni
      las vocales con tilde).
   3) Solucion final modular: funcion esLetra que tiene en cuenta las
      particularidades del alfabeto espanol.
   (Las letras especiales se escriben con su codigo en Windows-1252/Latin-1,
    la codificacion de la consola de Windows en los ejemplos del video.) */
#include <stdio.h>

/* 2) Version con rangos ASCII */
int totalLetrasAscii(char cad[])
{
    int i, total = 0;

    for (i = 0; cad[i] != '\0'; i++)
        if ((cad[i] >= 'a' && cad[i] <= 'z') || (cad[i] >= 'A' && cad[i] <= 'Z'))
            total++;
    return total;
}

/* 3) Devuelve 1 si c es una letra del alfabeto espanol */
int esLetra(char c)
{
    unsigned char u = (unsigned char)c;

    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return 1;
    /* ñ Ñ á é í ó ú Á É Í Ó Ú ü Ü */
    if (u == 0xF1 || u == 0xD1 ||
        u == 0xE1 || u == 0xE9 || u == 0xED || u == 0xF3 || u == 0xFA ||
        u == 0xC1 || u == 0xC9 || u == 0xCD || u == 0xD3 || u == 0xDA ||
        u == 0xFC || u == 0xDC)
        return 1;
    return 0;
}

/* Funcion pedida: muy sencilla gracias a esLetra */
int totalLetras(char cad[])
{
    int i, total = 0;

    for (i = 0; cad[i] != '\0'; i++)
        if (esLetra(cad[i]))
            total++;
    return total;
}

int main()
{
    /* "Begoña, díselo por favor" en Windows-1252 */
    char cad[] = "Bego\xF1" "a, d\xEDselo por favor";

    printf("Letras (rangos ASCII): %d\n", totalLetrasAscii(cad));  /* 18: no cuenta ñ ni í */
    printf("Letras (esLetra):      %d\n", totalLetras(cad));       /* 20 */
    return 0;
}
