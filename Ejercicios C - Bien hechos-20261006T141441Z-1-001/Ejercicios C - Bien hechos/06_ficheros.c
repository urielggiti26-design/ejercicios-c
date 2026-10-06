/* Video 6 - Ficheros en lenguaje C
   Las 4 fases para trabajar con ficheros:
     1) declarar la variable FILE *
     2) abrir con fopen(nombre, modo)   modos: "r" leer, "w" escribir (borra), "a" anadir
     3) operar: fscanf (leer) / fprintf (escribir)
     4) cerrar con fclose
   Ejemplo del video: escribir los 5 primeros numeros naturales en datos.txt */
#include <stdio.h>

int main()
{
    FILE *f1;                       /* 1) declaracion */

    f1 = fopen("datos.txt", "w");   /* 2) apertura en modo escritura */
    if (f1 == NULL) {               /* fopen devuelve NULL si hay error */
        printf("Error al abrir el fichero\n");
        return 1;
    }

    fprintf(f1, "1 2 3 ");          /* 3) operaciones */
    fprintf(f1, "4 5");
    /* fprintf no anade salto de linea: los 5 numeros quedan en la misma
       linea. Para escribir "4 5" en otra linea: fprintf(f1, "1 2 3\n"); */

    fclose(f1);                     /* 4) cierre */

    /* Otros ejemplos de apertura del video:
       f1 = fopen("datos.txt", "r");               lectura, carpeta actual
       f2 = fopen("c:\\prueba\\datos2.txt", "w");  ruta con doble barra
       f3 = fopen("datos3.txt", "a");              anadir al final        */

    printf("Fichero datos.txt escrito\n");
    return 0;
}
