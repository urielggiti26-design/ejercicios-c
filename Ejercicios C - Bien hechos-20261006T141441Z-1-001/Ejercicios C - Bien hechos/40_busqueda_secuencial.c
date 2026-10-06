/* Video 40 - Busqueda secuencial en vectores
   Funcion busqueda: recibe un vector de enteros, su tamano y el valor a
   buscar; devuelve la posicion de la PRIMERA ocurrencia o -1 si no esta.
   Variacion: buscar la ULTIMA ocurrencia recorriendo el vector al reves.
   Ej. del video: buscar 27 en {78, 27, ...} -> posicion 1 */
#include <stdio.h>

int busqueda(int v[], int tam, int valor)
{
    int i;

    for (i = 0; i < tam; i++)
        if (v[i] == valor)
            return i;      /* se sale en cuanto se encuentra */
    return -1;             /* solo se llega aqui si no esta */
}

/* Variacion: ultima ocurrencia (solo cambia el for) */
int busquedaUltima(int v[], int tam, int valor)
{
    int i;

    for (i = tam - 1; i >= 0; i--)
        if (v[i] == valor)
            return i;
    return -1;
}

int main()
{
    int v[6] = {78, 27, 5, 13, 27, 40};
    int valor;

    printf("Valor a buscar: ");
    scanf("%d", &valor);

    printf("Primera ocurrencia: %d\n", busqueda(v, 6, valor));
    printf("Ultima ocurrencia: %d\n", busquedaUltima(v, 6, valor));
    return 0;
}
