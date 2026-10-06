/* Video 47 - Funciones mas habituales de la libreria string.h
   strlen(cad)        -> longitud de la cadena
   strcpy(dest, orig) -> copia orig en dest (se pierde lo que hubiera)
   strcat(dest, orig) -> anade orig al final de dest
   strcmp(c1, c2)     -> 0 si son iguales; >0 si c1 es mayor; <0 si es menor
   Ejemplo del video: a partir de primer apellido, segundo apellido y nombre,
   formar la cadena "Apellido1 Apellido2, N." */
#include <stdio.h>
#include <string.h>

void formato(char ape1[], char ape2[], char nombre[], char todo[])
{
    int tam;

    strcpy(todo, ape1);
    strcat(todo, " ");
    strcat(todo, ape2);
    strcat(todo, ", ");
    tam = strlen(todo);        /* posicion donde va la inicial */
    todo[tam] = nombre[0];
    todo[tam + 1] = '.';
    todo[tam + 2] = '\0';      /* fin de cadena */
}

int main()
{
    char cad[8] = "Ana", cad2[8], cad3[20] = "Adri", cad4[8] = "Mar";
    char todo[60];

    /* Ejemplos de cada funcion */
    printf("strlen(\"%s\") = %d\n", cad, (int)strlen(cad));    /* 3 */

    strcpy(cad2, cad);
    printf("strcpy -> cad2 = %s\n", cad2);                    /* Ana */

    strcat(cad3, "ana");
    printf("strcat -> %s\n", cad3);                           /* Adriana */

    if (strcmp(cad, cad4) == 0)
        printf("Las cadenas son iguales\n");
    else
        printf("Las cadenas son diferentes\n");

    /* Ejemplo final */
    formato("Garcia", "Lopez", "Maria", todo);
    printf("%s\n", todo);                                     /* Garcia Lopez, M. */
    return 0;
}
