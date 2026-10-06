/* Video 28 - Programas para el calculo de la serie de Fibonacci
   Mostrar los n primeros terminos de la sucesion de Fibonacci (0 1 1 2 3 5 ...),
   con n pedido al usuario y positivo (se repite la peticion con do ... while).
   Terminos predefinidos: 0 y 1. Terminos calculados: suma de los dos anteriores. */
#include <stdio.h>

int main()
{
    int n, contador, nuevo, ultimo, penultimo;

    /* Peticion del numero de terminos: repetir mientras no sea positivo */
    do {
        printf("Numero de terminos a mostrar: ");
        scanf("%d", &n);
    } while (n <= 0);

    printf("Terminos de la serie de Fibonacci:\n");

    /* Primer termino (seguro, porque n > 0) */
    printf("0 ");
    if (n == 1) {
        printf("\n");
        return 0;
    }

    /* Segundo termino */
    printf("1 ");

    /* Resto de terminos (si n == 2 no entra en el while) */
    contador = 2;       /* terminos mostrados hasta ahora */
    ultimo = 1;
    penultimo = 0;
    while (contador < n) {
        nuevo = ultimo + penultimo;
        printf("%d ", nuevo);
        penultimo = ultimo;   /* este orden no se puede cambiar */
        ultimo = nuevo;
        contador++;
    }
    printf("\n");

    return 0;
}
