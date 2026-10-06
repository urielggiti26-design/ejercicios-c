/* Video 30 - Ficheros en lenguaje C: ejemplo de fabrica de nanobots
   prod.txt tiene en cada linea los datos diarios de produccion:
       unidades_producidas  unidades_defectuosas  minutos_activa
   Calcular cuantos dias el porcentaje de defectuosas ha sido superior al 1%
   y el tiempo medio diario en que la fabrica ha estado activa. */
#include <stdio.h>

int main()
{
    FILE *f;
    int producidas, defectuosas, minutos;
    int contadorLineas = 0, sumaMinutos = 0, contadorMas1 = 0;   /* inicializadas a 0 */

    f = fopen("prod.txt", "r");
    if (f == NULL) {
        printf("Error al abrir el fichero\n");
        return 1;
    }

    /* Lectura linea a linea hasta el final del fichero */
    while (fscanf(f, "%d %d %d", &producidas, &defectuosas, &minutos) == 3) {
        contadorLineas++;
        sumaMinutos += minutos;
        /* (float) para que la division sea real y no entera */
        if ((float)defectuosas / producidas > 0.01)
            contadorMas1++;
    }
    fclose(f);

    printf("Dias con mas de un 1%% de unidades defectuosas: %d\n", contadorMas1);
    if (contadorLineas > 0)
        printf("Tiempo medio diario de actividad: %.0f minutos\n",
               (float)sumaMinutos / contadorLineas);

    return 0;
}
