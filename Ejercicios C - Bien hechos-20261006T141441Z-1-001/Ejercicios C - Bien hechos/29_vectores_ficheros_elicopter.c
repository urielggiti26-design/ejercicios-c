/* Video 29 - Vectores y ficheros: servicio e-Licopter
   Helicopteros electricos: 200 helipuertos (id < 100 en la ciudad, >= 100
   fuera) y 10 usuarios (0 a 9). semanal.txt guarda una linea por servicio:
       usuario  helipuerto_origen  helipuerto_destino
   1) Generar informe.txt con cuantas veces ha usado el servicio cada usuario
      (los que no lo han usado no aparecen).
   2) Mostrar el total facturado: 10 euros si origen y destino estan en la
      ciudad, 19 si ambos estan fuera y 14.50 en otro caso. */
#include <stdio.h>
#define USUARIOS 10

int main()
{
    FILE *fEnt, *fSal;
    int usuarios[USUARIOS];   /* contador de servicios de cada usuario */
    int usr, orig, dest, i;
    float facturado = 0;

    /* Apertura de los dos ficheros */
    fEnt = fopen("semanal.txt", "r");
    if (fEnt == NULL) {
        printf("Error al abrir semanal.txt\n");
        return 1;
    }
    fSal = fopen("informe.txt", "w");
    if (fSal == NULL) {
        printf("Error al abrir informe.txt\n");
        fclose(fEnt);         /* cerrar el que ya estaba abierto */
        return 1;
    }

    /* Los contadores se incrementan, asi que se inicializan a 0 */
    for (i = 0; i < USUARIOS; i++)
        usuarios[i] = 0;

    /* Lectura linea a linea hasta el final del fichero */
    while (fscanf(fEnt, "%d %d %d", &usr, &orig, &dest) == 3) {
        usuarios[usr]++;                      /* apartado 1 */

        if (orig < 100 && dest < 100)         /* apartado 2 */
            facturado += 10;
        else if (orig >= 100 && dest >= 100)
            facturado += 19;
        else
            facturado += 14.5;
    }

    /* Volcado del vector al informe (solo usuarios con algun servicio) */
    for (i = 0; i < USUARIOS; i++)
        if (usuarios[i] > 0)
            fprintf(fSal, "Usuario %d: %d veces\n", i, usuarios[i]);

    fclose(fEnt);
    fclose(fSal);

    printf("Total facturado: %.2f euros\n", facturado);
    return 0;
}
