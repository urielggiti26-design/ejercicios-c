/* Video 4 - Entrada estandar en lenguaje C (scanf)
   Ejemplos del video: leer un entero, una cadena (sin &), varios datos en un
   mismo scanf, el triangulo con mensaje previo al usuario y la trampa de
   leer caracteres (el espacio en blanco tambien es un caracter). */
#include <stdio.h>

int main()
{
    int valor, entero;
    float real, base, altura;
    char cad[50];
    char a, b, c[20];

    /* 1. Leer un entero: & devuelve la direccion de la variable */
    printf("Dame un valor entero: ");
    scanf("%d", &valor);
    printf("Has introducido %d\n\n", valor);

    /* 2. Leer una cadena: no lleva & porque ya es una direccion.
          Solo lee hasta el primer espacio ("hola a todos" -> "hola") */
    printf("Dame una cadena: ");
    scanf("%s", cad);
    printf("Has introducido %s\n\n", cad);

    /* 3. Varios datos separados por espacio, tabulador o salto de linea (4 5.2) */
    printf("Dame un valor entero y otro real: ");
    scanf("%d %f", &entero, &real);
    printf("Entero: %d  Real: %.1f\n\n", entero, real);

    /* 4. Siempre avisar al usuario de lo que tiene que introducir */
    printf("Dame la base y la altura del triangulo: ");
    scanf("%f %f", &base, &altura);
    printf("La superficie del triangulo es %.2f\n\n", base * altura / 2);

    /* 5. Caracteres: si el usuario escribe "x b", a = 'x', b = ' ' (el espacio)
          y la cadena c = "b". Con " %c" (espacio delante) se saltan los blancos. */
    printf("Dame dos caracteres y una cadena: ");
    scanf(" %c%c%s", &a, &b, c);
    printf("a = '%c'  b = '%c'  c = \"%s\"\n", a, b, c);

    return 0;
}
