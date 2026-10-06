/* Video 7 - Procedimiento habitual de trabajo con ficheros
   Fases: 1) definir la variable FILE *   2) abrir con fopen
          3) operar (fprintf / fscanf)    4) cerrar con fclose
   Ejemplo completo del video: crear un fichero y escribir los numeros 1 a 5. */
#include <stdio.h>   /* FILE no es un tipo nativo: hace falta stdio.h */

int main()
{
    /* 1) Definicion: cada variable fichero es un puntero, lleva su asterisco */
    FILE *f1, *f2;

    /* 2) Apertura: fopen(nombre, modo)
          "r": leer (error si no existe)
          "w": escribir (borra el contenido si existe, lo crea si no)
          "a": anadir al final (lo crea si no existe)
          Ruta en Windows con doble barra: "c:\\prueba\\datos.txt"
          Sin extension ("datos") seria otro fichero distinto de "datos.txt" */
    f1 = fopen("datos.txt", "w");
    if (f1 == NULL) {              /* si hay error fopen devuelve NULL */
        printf("Error al abrir datos.txt\n");
        return 1;
    }

    /* 3) Operar: escribir los numeros del 1 al 5 */
    fprintf(f1, "1 2 3 4 5\n");

    /* 4) Cierre */
    fclose(f1);

    /* Mismo procedimiento para leer: abrir en modo "r" y usar fscanf */
    int a, b, c, d, e;
    f2 = fopen("datos.txt", "r");
    if (f2 == NULL) {
        printf("Error al abrir datos.txt\n");
        return 1;
    }
    fscanf(f2, "%d %d %d %d %d", &a, &b, &c, &d, &e);
    fclose(f2);

    printf("Leido del fichero: %d %d %d %d %d\n", a, b, c, d, e);
    return 0;
}
