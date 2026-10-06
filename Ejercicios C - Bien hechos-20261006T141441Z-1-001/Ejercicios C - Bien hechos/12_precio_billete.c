/* Video 12 - Calculo precio billete
   Agencia de viajes: a partir del precio base del billete y de si el cliente
   es nacional (1) o no (0), mostrar el precio final. Si es nacional se aplica
   un 21% de IVA; si no, no se suma nada.
   Version final del video: si el codigo no es ni 1 ni 0 se muestra un error. */
#include <stdio.h>

int main()
{
    float precio, iva = 0.21;   /* IVA en tanto por 1 */
    int nacional;

    printf("Precio del billete: ");
    scanf("%f", &precio);       /* variables simples: con & */
    printf("Cliente nacional (1) o no nacional (0): ");
    scanf("%d", &nacional);

    if (nacional == 1) {        /* == compara (= asignaria) */
        precio *= (1 + iva);    /* equivale a precio = precio * (1 + iva) */
        printf("Precio final: %.2f euros\n", precio);
    }
    else if (nacional == 0)
        printf("Precio final: %.2f euros\n", precio);
    else
        printf("Error: codigo de cliente no valido\n");

    return 0;
}
