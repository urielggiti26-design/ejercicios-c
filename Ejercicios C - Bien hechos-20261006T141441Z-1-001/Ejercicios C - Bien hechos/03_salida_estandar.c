/* Video 3 - Salida estandar en lenguaje C (printf)
   Contenido del video: libreria stdio.h, secuencias de escape, modificadores
   de formato y flags, longitud y precision. */
#include <stdio.h>

int main()
{
    int n = 42;
    float precio = 25.6789;
    char letra = 'A';

    /* Texto simple y secuencias de escape */
    printf("Hola mundo\n");                  /* \n salto de linea */
    printf("Columna1\tColumna2\n");          /* \t tabulador */
    printf("Comillas: \" y barra: \\\n");   /* \" comillas, \\ barra invertida */
    printf("Comilla simple: \'\n");
    printf("Alerta sonora: \a\n");           /* \a pitido */

    /* Modificadores: %d entero, %f real, %c caracter, %s cadena */
    printf("Entero: %d\n", n);
    printf("Real: %f\n", precio);
    printf("Caracter: %c\n", letra);
    printf("Cadena: %s\n", "Hola");
    printf("Varios: %d %f %c\n", n, precio, letra);

    /* Longitud (ancho minimo) y precision */
    printf("[%5d]\n", n);          /* ancho 5, alineado a la derecha */
    printf("[%.2f]\n", precio);    /* 2 decimales */
    printf("[%10.1f]\n", precio);  /* ancho 10 y 1 decimal */

    /* Flags */
    printf("[%-5d]\n", n);         /* - : alinea a la izquierda */
    printf("[%+d]\n", n);          /* + : muestra siempre el signo */
    printf("[%05d]\n", n);         /* 0 : rellena con ceros */

    printf("Simbolo de porcentaje: %%\n");
    return 0;
}
