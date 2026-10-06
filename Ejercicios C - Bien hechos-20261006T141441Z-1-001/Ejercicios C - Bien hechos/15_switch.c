/* Video 15 - Sentencia switch en lenguaje C
   Ejemplo 1 (menu): pedir un entero, mostrar un menu (mitad, doble, triple)
   y mostrar el resultado de la opcion elegida.
   Ejemplo 2 (multiopcion): impuesto segun el numero de vehiculos
   (0 -> 0, 1 -> 50, 2 o 3 -> 100, mas de 3 -> 150 euros). */
#include <stdio.h>

int main()
{
    int valor, opc, vehic, imp;

    /* ---- Ejemplo 1: menu ---- */
    printf("Dame un valor entero: ");
    scanf("%d", &valor);

    printf("1. Mitad\n");
    printf("2. Doble\n");
    printf("3. Triple\n");
    printf("Elige opcion: ");
    scanf("%d", &opc);

    switch (opc) {
        case 1:
            printf("Resultado: %.1f\n", valor / 2.0);   /* 2.0 -> division real */
            break;                                       /* sin break seguiria con el case 2 */
        case 2:
            printf("Resultado: %d\n", valor * 2);
            break;
        case 3:
            printf("Resultado: %d\n", valor * 3);
            break;
        default:
            printf("Opcion incorrecta\n");
    }

    /* ---- Ejemplo 2: multiopcion (varias etiquetas, mismo codigo) ---- */
    printf("\nNumero de vehiculos: ");
    scanf("%d", &vehic);

    switch (vehic) {
        case 0:
            imp = 0;
            break;
        case 1:
            imp = 50;
            break;
        case 2:          /* sin instrucciones ni break: continua en el case 3 */
        case 3:
            imp = 100;
            break;
        default:
            imp = 150;
    }
    printf("Impuesto a pagar: %d euros\n", imp);

    return 0;
}
