/* Video 16 - Errores mas comunes en sentencias condicionales
   Cada bloque muestra el error del video (comentado) y la forma correcta. */
#include <stdio.h>

int main()
{
    int v, edad;
    float r = 2.5;

    printf("Dame el valor de v: ");
    scanf("%d", &v);

    /* ERROR 1: valor en un intervalo
       if (4 < v < 9)  -> compila, pero (4 < v) da 0 o 1, que siempre es < 9,
       asi que es cierto para v = 5, v = 1 y v = 15.
       CORRECTO: dos comparaciones unidas con && */
    if (4 < v && v < 9)
        printf("v esta en el intervalo (4, 9)\n");
    else
        printf("v no esta en el intervalo (4, 9)\n");

    /* ERROR 2: = en lugar de ==
       if (v = 5)  -> asigna 5 a v y la condicion vale 5 (cierto) siempre.
       CORRECTO: */
    if (v == 5)
        printf("v vale 5\n");

    /* ERROR 3: operador inexistente
       if (v => 10)  -> error de compilacion.
       CORRECTO: el simbolo > o < va delante del =  ( >=  <= ) */
    if (v >= 10)
        printf("v es mayor o igual que 10\n");

    /* ERROR 4: olvidar las llaves con varias instrucciones
       edad = 16;
       if (edad >= 18)
           printf("Eres mayor de edad\n");
           printf("Puedes votar\n");      <- se ejecuta siempre
       CORRECTO: */
    edad = 16;
    if (edad >= 18) {
        printf("Eres mayor de edad\n");
        printf("Puedes votar\n");
    }

    /* ERROR 5: punto y coma tras la condicion
       if (edad >= 18);                  <- sentencia vacia
           printf("Puedes votar\n");      <- se ejecuta siempre
       CORRECTO: sin ; tras la condicion */
    if (edad >= 18)
        printf("Puedes votar\n");

    /* ERROR 6: switch sobre una expresion no entera
       switch (r) { ... }  con r float -> error de compilacion.
       CORRECTO: switch solo con expresiones int o char */
    switch ((int)r) {
        case 2:
            printf("Parte entera de r: 2\n");
            break;
        default:
            printf("Otro valor\n");
    }

    return 0;
}
