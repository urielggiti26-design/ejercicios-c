/* Video 60 - Estructuras y funciones en lenguaje C: ejemplo de robots electricos
   Robots electricos que trabajan a velocidad 1 (normal), 2 (rapida) o
   3 (ultrarrapida).
   a) Estructura robot: id (8 caracteres alfanumericos), color ("rojo",
      "verde", "naranja" o "azul") y tiempoTrabajo (segundos que funciona con
      carga completa a velocidad 1; a velocidad 2 la mitad y a 3 la tercera parte).
   b) Funcion robotValido(r, vel, minutos): 1 si el robot puede funcionar a
      esa velocidad esos minutos y 0 si no.
      Ej: tiempoTrabajo 700 -> vel 1, 10 min (600 s): 1;  vel 2 (350 s): 0
   c) Funcion robotsEspeciales(v, tam, segundos): escribe en ids.txt los id de
      los robots especiales (rojos o naranjas) que a velocidad 2 trabajan mas
      de "segundos". Devuelve cuantos ha escrito o -1 si falla el fichero. */
#include <stdio.h>
#include <string.h>

struct robot {
    char id[9];          /* 8 caracteres + '\0' */
    char color[8];       /* "naranja" (7) + '\0' */
    int tiempoTrabajo;
};

int robotValido(struct robot r, int vel, int minutos)
{
    float tMax;

    tMax = (float)r.tiempoTrabajo / vel;   /* division real */
    if (tMax >= minutos * 60)
        return 1;
    return 0;
}

int robotsEspeciales(struct robot v[], int tam, int segundos)
{
    FILE *f;
    int i, cont = 0;

    f = fopen("ids.txt", "w");
    if (f == NULL)
        return -1;

    for (i = 0; i < tam; i++)
        if ((strcmp(v[i].color, "rojo") == 0 || strcmp(v[i].color, "naranja") == 0)
            && (float)v[i].tiempoTrabajo / 2 > segundos) {
            fprintf(f, "%s\n", v[i].id);
            cont++;
        }

    fclose(f);
    return cont;
}

int main()
{
    struct robot r = {"AB12CD34", "rojo", 700};
    struct robot v[5] = {
        {"AB12CD34", "rojo",    700},
        {"XY98ZT76", "verde",   900},
        {"QW34ER56", "naranja", 1200},
        {"PL09OK87", "azul",    1500},
        {"MN45BV21", "rojo",    300}
    };
    int n;

    printf("%d\n", robotValido(r, 1, 10));   /* 1 */
    printf("%d\n", robotValido(r, 2, 10));   /* 0 */

    n = robotsEspeciales(v, 5, 300);
    if (n == -1)
        printf("Error con el fichero\n");
    else
        printf("Se han escrito %d robots en ids.txt\n", n);   /* 2 */
    return 0;
}
