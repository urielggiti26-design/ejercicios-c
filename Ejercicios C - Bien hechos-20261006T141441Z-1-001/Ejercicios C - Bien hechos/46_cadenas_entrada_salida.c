/* Video 46 - Tratamiento de cadenas en entrada y salida estandar con C
   Salida:  printf("%s")  -> muestra la cadena hasta el '\0' (mas versatil)
            puts(cad)     -> igual, pero siempre anade un salto de linea
   Entrada: scanf("%s")   -> lee hasta espacio/tabulador/salto: UNA palabra
            gets(cad)     -> lee toda la linea (varias palabras)
   Ninguna lleva & (una cadena ya es una referencia) y ambas anaden el '\0'.
   (Nota: gets no comprueba el tamano y se elimino en C11; hoy se usa
    fgets(cad, tam, stdin). Se mantiene gets porque es lo que usa el video.)
   Ejemplo del video: usuario (puede tener varias palabras, con gets) y
   contrasena (solo la primera palabra, con scanf). */
#include <stdio.h>

int main()
{
    char nombre[10] = "Jorge";
    char cadena[50] = "Cadena de prueba";
    char usuario[50], contrasena[20];

    /* Salida estandar */
    printf("[%s]\n", nombre);
    printf("Inicio-");
    printf("%s", cadena);       /* sin salto de linea */
    printf("-Fin\n");
    printf("Inicio-");
    puts(cadena);               /* anade el salto de linea */
    printf("-Fin\n");

    /* Entrada estandar: ejemplo usuario / contrasena */
    printf("Usuario: ");
    gets(usuario);              /* "Adriana Patraix" -> se guarda entero */
    printf("Contrasena: ");
    scanf("%s", contrasena);    /* solo la primera palabra */

    printf("Usuario guardado: %s\n", usuario);
    printf("Contrasena guardada: %s\n", contrasena);
    return 0;
}
