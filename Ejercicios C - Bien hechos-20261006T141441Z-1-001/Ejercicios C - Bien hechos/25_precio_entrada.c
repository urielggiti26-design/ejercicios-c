/* Video 25 - Calculo de precio de entrada
   Parque de atracciones: precio base 35 euros; en junio, julio, agosto y
   septiembre (meses 6 a 9) 42.50 euros. Menores de 18 o con al menos 65 anios
   pagan 25 euros sea cual sea el mes (y no se les pide el mes).
   Modificacion del video: repetir la peticion del mes (do ... while) hasta
   que este entre 1 y 12. */
#include <stdio.h>

int main()
{
    float precio = 35;   /* precio base; real porque puede valer 42.5 */
    int edad, mes;

    printf("Edad del visitante: ");
    scanf("%d", &edad);

    if (edad < 18 || edad >= 65)
        precio = 25;
    else {
        do {
            printf("Mes de la visita: ");
            scanf("%d", &mes);
        } while (!(mes >= 1 && mes <= 12));   /* equivale a: mes < 1 || mes > 12 */

        if (mes > 5 && mes < 10)
            precio = 42.5;
    }

    printf("Precio de la entrada: %.2f euros\n", precio);
    return 0;
}
