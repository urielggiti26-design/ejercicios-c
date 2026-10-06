/* Video 52 - Ocurrencias de una palabra en un fichero
   Funcion que recibe el nombre de un fichero y una palabra y devuelve
   cuantas veces aparece esa palabra en el fichero.
   Se recorre el fichero palabra a palabra (fscanf con %s) y se compara cada
   una con strcmp (devuelve 0 si son iguales).
   Ojo: strcmp distingue mayusculas y minusculas. En vaca.txt "la" aparece
   5 veces, pero una es "La", asi que la funcion devuelve 4 (y es correcto). */
#include <stdio.h>
#include <string.h>

int ocurrencias(char fichero[], char palabra[])
{
    FILE *f;
    char palAux[50];
    int oc = 0;                 /* contador inicializado */

    f = fopen(fichero, "r");
    if (f) {
        while (fscanf(f, "%s", palAux) == 1)
            if (strcmp(palAux, palabra) == 0)
                oc++;
        fclose(f);              /* dentro del if: solo si se abrio */
    }
    else
        printf("Error al abrir el fichero\n");

    return oc;
}

int main()
{
    printf("Ocurrencias de \"la\": %d\n", ocurrencias("vaca.txt", "la"));
    return 0;
}
