/* Video 17 - Comprobar si el caracter es una vocal
   Pide un caracter y dice si es vocal minuscula, vocal mayuscula o no es
   vocal (se asume que no se introducen vocales con tilde).
   El video da dos soluciones: con if ... else y con switch. */
#include <stdio.h>

int main()
{
    char c;

    printf("Introduce un caracter: ");
    scanf("%c", &c);          /* %c para caracteres; tipo simple -> & */

    /* Solucion 1: if ... else (comillas simples para caracteres, == para comparar) */
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        printf("Es una vocal minuscula\n");
    else if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
        printf("Es una vocal mayuscula\n");
    else
        printf("No es una vocal\n");

    /* Solucion 2: switch. Un char se guarda como su codigo ASCII (entero),
       por eso se puede usar en un switch. case 'A' equivale a case 65. */
    switch (c) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            printf("Es una vocal minuscula\n");
            break;
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
            printf("Es una vocal mayuscula\n");
            break;
        default:
            printf("No es una vocal\n");
    }

    return 0;
}
