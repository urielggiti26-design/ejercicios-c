/* Video 24 - Calculo del maximo y minimo de los valores guardados en un fichero
   estacion.txt guarda temperaturas de una estacion meteorologica (puede haber
   negativas). Mostrar la maxima y la minima. Indicar si hay error al abrir el
   fichero o si no se ha podido leer ningun valor (fichero vacio).
   Con el fichero de ejemplo: maxima 14.6, minima -4.7 */
#include <stdio.h>

int main()
{
    FILE *f;
    float fTemp, fMin, fMax;
    int iLeidoAlgo;      /* "booleano": 0 = aun no se ha leido nada */

    f = fopen("estacion.txt", "r");
    if (f) {             /* equivale a if (f != NULL) */
        iLeidoAlgo = 0;
        while (fscanf(f, "%f", &fTemp) == 1) {
            if (iLeidoAlgo == 0) {
                /* primer valor: inicializa minimo y maximo */
                iLeidoAlgo = 1;
                fMin = fTemp;
                fMax = fTemp;
            }
            else if (fTemp < fMin)
                fMin = fTemp;
            else if (fTemp > fMax)
                fMax = fTemp;
        }

        if (iLeidoAlgo == 0)
            printf("No se ha podido leer ningun valor\n");
        else {
            printf("Temperatura maxima: %.1f\n", fMax);
            printf("Temperatura minima: %.1f\n", fMin);
        }

        fclose(f);       /* dentro del if: solo si se abrio bien */
    }
    else
        printf("Error al abrir el fichero\n");

    return 0;
}
