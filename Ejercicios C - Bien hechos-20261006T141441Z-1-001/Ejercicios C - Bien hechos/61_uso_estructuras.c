/* Video 61 - Uso de estructuras en C
   1) Estructura punto2D (coordenadas reales x e y) declarada con typedef,
      para poder declarar variables sin poner "struct" delante.
   2) Ampliacion: estructura triangulo2D con tres vertices v1, v2, v3 de tipo
      punto2D (punto2D tiene que declararse antes).
   3) Ampliacion: funcion distanciaPunto2D que devuelve la distancia euclidea
      entre dos puntos: sqrt((x1-x2)^2 + (y1-y2)^2). */
#include <stdio.h>
#include <math.h>    /* sqrt y pow */

typedef struct {
    float x;
    float y;
} punto2D;

typedef struct {
    punto2D v1;
    punto2D v2;
    punto2D v3;
} triangulo2D;

float distanciaPunto2D(punto2D p1, punto2D p2)
{
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

int main()
{
    punto2D p1, p2;
    triangulo2D t1;

    /* Codigo del primer apartado */
    p1.x = 1.0;
    p1.y = 2.0;
    p2.x = 4.0;
    p2.y = 6.0;
    printf("p1 = (%.1f, %.1f)  p2 = (%.1f, %.1f)\n", p1.x, p1.y, p2.x, p2.y);

    /* Codigo del segundo apartado */
    t1.v1 = p1;
    t1.v2 = p2;
    t1.v3.x = 4.0;
    t1.v3.y = 2.0;
    printf("Triangulo: (%.1f, %.1f) (%.1f, %.1f) (%.1f, %.1f)\n",
           t1.v1.x, t1.v1.y, t1.v2.x, t1.v2.y, t1.v3.x, t1.v3.y);

    /* Tercer apartado */
    printf("Distancia p1-p2: %.2f\n", distanciaPunto2D(p1, p2));   /* 5.00 */
    return 0;
}
