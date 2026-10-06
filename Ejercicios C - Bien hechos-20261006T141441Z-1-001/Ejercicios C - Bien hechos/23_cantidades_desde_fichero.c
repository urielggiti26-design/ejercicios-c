/* Video 23 - Calculo de cantidades a partir de datos guardados en un fichero
   calificaciones.txt guarda notas de alumnos (5.6, 4.2, 8.9, ...).
   Contar suspensos [0,5), aprobados [5,7), notables [7,9),
   sobresalientes [9,10] y notas erroneas (fuera de 0-10). */
#include <stdio.h>

int main()
{
    FILE *f;
    float fNota;
    int iSus = 0, iAprob = 0, iNot = 0, iSob = 0, iErr = 0;   /* contadores a 0 */

    f = fopen("calificaciones.txt", "r");
    if (f) {                       /* f es NULL si no se ha podido abrir */
        /* Recorrer el fichero dato a dato hasta el final */
        while (fscanf(f, "%f", &fNota) == 1) {
            if (fNota < 0 || fNota > 10)
                iErr++;
            else if (fNota < 5)
                iSus++;
            else if (fNota < 7)    /* ya se sabe que es >= 5 */
                iAprob++;
            else if (fNota < 9)
                iNot++;
            else
                iSob++;
        }

        /* Resultados despues del bucle, no dentro */
        printf("Suspensos: %d\n", iSus);
        printf("Aprobados: %d\n", iAprob);
        printf("Notables: %d\n", iNot);
        printf("Sobresalientes: %d\n", iSob);
        printf("Notas erroneas: %d\n", iErr);

        fclose(f);                 /* solo se cierra si se abrio bien */
    }
    else
        printf("Error al abrir el fichero\n");

    return 0;
}
