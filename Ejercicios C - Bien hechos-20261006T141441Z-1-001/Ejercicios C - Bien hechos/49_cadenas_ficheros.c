/* Video 49 - Tratamiento de cadenas en ficheros con C
   Una cadena es un vector de caracteres terminado en '\0'.
   Lectura (stdio.h):
     fscanf(f, "%s", cad)  -> lee palabra a palabra y anade el '\0'
     fgets(cad, max, f)    -> lee una linea: hasta max-1 caracteres o hasta
                              el salto de linea (que se incluye)
   Escritura:
     fprintf(f, "...%s...", cad) -> permite contextualizar lo que se escribe
     fputs(cad, f)               -> escribe la cadena tal cual, sin anadir
                                    salto de linea */
#include <stdio.h>

int main()
{
    FILE *f;
    char palabra[50], linea[200];
    char nombre[] = "Jorge";

    /* Escritura */
    f = fopen("cadenas.txt", "w");
    if (f == NULL) {
        printf("Error al abrir el fichero\n");
        return 1;
    }
    fprintf(f, "Nombre: %s\n", nombre);   /* con contexto */
    fputs("Hola mundo", f);               /* tal cual... */
    fputs("\n", f);                       /* ...el salto hay que ponerlo aparte */
    fclose(f);

    /* Lectura palabra a palabra con fscanf */
    f = fopen("texto.txt", "r");
    if (f == NULL) {
        printf("Error al abrir el fichero\n");
        return 1;
    }
    printf("Palabras de texto.txt:\n");
    while (fscanf(f, "%s", palabra) == 1)
        printf("[%s] ", palabra);
    printf("\n\n");
    fclose(f);

    /* Lectura linea a linea con fgets */
    f = fopen("texto.txt", "r");
    if (f == NULL) {
        printf("Error al abrir el fichero\n");
        return 1;
    }
    printf("Lineas de texto.txt:\n");
    while (fgets(linea, 200, f) != NULL)
        printf("%s", linea);              /* la linea ya trae su '\n' */
    fclose(f);

    return 0;
}
