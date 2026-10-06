/* Video 18 - Calculo del numero de dias entre dos fechas sobre ficheros
   Lee dos fechas (dia mes anio) del fichero fechas.txt, calcula los dias que
   hay entre la segunda y la primera y escribe el resultado en dias.txt.
   Simplificacion del video: todos los anios tienen 365 dias y los meses 30.
   Estrategia: dias desde el inicio de la era hasta cada fecha y restarlos.
     20/11/1972 -> 1972*365 + (11-1)*30 + 20 = 720100 dias */
#include <stdio.h>

int main()
{
    FILE *f;
    int d1, m1, a1, d2, m2, a2;   /* primera y segunda fecha */
    int dias1, dias2;             /* dias desde el inicio de la era */

    /* 1. Lectura de datos */
    f = fopen("fechas.txt", "r");
    if (f == NULL) {
        printf("Error al abrir fechas.txt\n");
        return 1;
    }
    fscanf(f, "%d %d %d", &d1, &m1, &a1);
    fscanf(f, "%d %d %d", &d2, &m2, &a2);
    fclose(f);

    /* 2. Calculos */
    dias1 = a1 * 365 + (m1 - 1) * 30 + d1;
    dias2 = a2 * 365 + (m2 - 1) * 30 + d2;

    /* 3. Escritura del resultado (se reutiliza la variable f) */
    f = fopen("dias.txt", "w");
    if (f == NULL) {
        printf("Error al abrir dias.txt\n");
        return 1;
    }
    fprintf(f, "Dias entre fechas: %d\n", dias2 - dias1);
    fclose(f);

    /* Alternativa del video (menos legible): un solo fscanf con 6 %d
       y los calculos directamente dentro del fprintf:
       fscanf(f, "%d %d %d %d %d %d", &d1, &m1, &a1, &d2, &m2, &a2);
       fprintf(f, "Dias entre fechas: %d\n",
               (a2 * 365 + (m2 - 1) * 30 + d2) - (a1 * 365 + (m1 - 1) * 30 + d1)); */

    printf("Resultado guardado en dias.txt\n");
    return 0;
}
