/* Video 58 - Estructuras y funciones: Sets de juego
   Una empresa fabrica minifiguras y sets de juego.
     minifigura: codigo, nombre y precio
     set: codigo, nombre comercial, codigos de las 5 minifiguras que incluye
          y precio
   Funcion setsContenedores: recibe un vector de sets, su tamano y una
   minifigura, y muestra el nombre comercial de los sets que la incluyen.
   - Una misma figura puede estar mas de una vez en un set: el set solo se
     muestra una vez (variable "esta").
   - Si ningun set la contiene, se indica por pantalla. */
#include <stdio.h>

struct minifigura {
    int codigo;
    char nombre[50];
    float precio;
};

struct set {
    int codigo;
    char nombreComercial[50];
    int minifiguras[5];          /* codigos de las 5 minifiguras */
    float precio;
};

void setsContenedores(struct set v[], int tam, struct minifigura mf)
{
    int i, j, esta, alguno = 0;

    for (i = 0; i < tam; i++) {             /* recorrer los sets */
        esta = 0;
        for (j = 0; j < 5; j++)             /* recorrer sus 5 minifiguras */
            if (v[i].minifiguras[j] == mf.codigo)
                esta = 1;
        if (esta == 1) {                    /* se muestra una sola vez */
            printf("%s\n", v[i].nombreComercial);
            alguno = 1;
        }
    }
    if (alguno == 0)
        printf("La minifigura %s no esta en ningun set\n", mf.nombre);
}

int main()
{
    struct set sets[3] = {
        {1, "Castillo medieval", {10, 11, 12, 10, 13}, 49.95},
        {2, "Estacion espacial", {20, 21, 22, 23, 24}, 79.95},
        {3, "Barco pirata",      {30, 10, 31, 32, 33}, 59.95}
    };
    struct minifigura caballero = {10, "Caballero", 3.5};
    struct minifigura robot = {99, "Robot", 4.0};

    printf("Sets con %s:\n", caballero.nombre);
    setsContenedores(sets, 3, caballero);   /* Castillo medieval y Barco pirata */

    printf("\nSets con %s:\n", robot.nombre);
    setsContenedores(sets, 3, robot);
    return 0;
}
