/* Video 51 - Sustituir caracteres de una cadena por otros caracteres
   Funcion sustituir(origen, destino): crea destino igual que origen pero
   cambiando cada espacio en blanco por "**", y devuelve cuantas
   sustituciones ha hecho.
   Como destino es mas larga que origen se usan dos indices:
     a -> posicion que se lee de origen
     b -> posicion donde se escribe en destino */
#include <stdio.h>
#include <string.h>

int sustituir(char origen[], char destino[])
{
    int a, b = 0, tam, blancos = 0;

    tam = strlen(origen);
    for (a = 0; a < tam; a++)
        if (origen[a] != ' ') {        /* caracteres entre comillas simples */
            destino[b] = origen[a];
            b++;
        }
        else {
            blancos++;
            destino[b] = '*';
            destino[b + 1] = '*';
            b += 2;
        }
    destino[b] = '\0';                 /* no olvidar el fin de cadena */

    return blancos;
}

int main()
{
    char c1[50] = "Esto es un ejemplo de uso";
    char c2[100];
    int n;

    n = sustituir(c1, c2);
    printf("Sustituciones: %d\n", n);   /* 5 */
    printf("Origen:  %s\n", c1);
    printf("Destino: %s\n", c2);
    return 0;
}
