/* Video 8 - Guardar en fichero datos de temperaturas
   Pide al usuario dia, mes y temperatura media y los escribe en
   temperaturas.txt. Version del video: modo "w" (sobrescribe si existe,
   lo crea si no existe). Al final se indica la modificacion para anadir. */
#include <stdio.h>

int main()
{
    FILE *f;
    int dia, mes;
    float temp;

    /* 1. Abrir el fichero comprobando que se abre correctamente */
    f = fopen("temperaturas.txt", "w");
    if (f == NULL) {
        printf("Error al abrir el fichero\n");
        return 1;
    }

    /* 2. Pedir los datos al usuario */
    printf("Dia: ");
    scanf("%d", &dia);
    printf("Mes: ");
    scanf("%d", &mes);
    printf("Temperatura media: ");
    scanf("%f", &temp);

    /* 3. Escribir en el fichero y cerrarlo */
    fprintf(f, "%d/%d %.1f", dia, mes, temp);
    fclose(f);

    /* Modificacion del video: para no borrar los datos anteriores y guardar
       cada registro en una linea distinta:
         f = fopen("temperaturas.txt", "a");
         fprintf(f, "%d/%d %.1f\n", dia, mes, temp);                         */

    printf("Datos guardados en temperaturas.txt\n");
    return 0;
}
