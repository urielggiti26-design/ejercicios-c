/* Video 36 - Programa para la gestion de asientos de un autobus
   Autobus de 10 plazas (numeradas de 0 a 9). Menu:
     1. Reservar asiento   2. Ver asientos libres   0. Salir
   Un vector guarda el estado de cada asiento (LIBRE / OCUPADO).
   Los vectores se pasan por referencia: las funciones pueden modificarlos. */
#include <stdio.h>

#define PLAZAS 10      /* para otro autobus basta con cambiar este valor */
#define LIBRE 1
#define OCUPADO 0

/* Muestra el menu y devuelve una opcion valida (0, 1 o 2) */
int menu()
{
    int opc;

    do {
        printf("\n1. Reservar asiento\n");
        printf("2. Ver asientos libres\n");
        printf("0. Salir\n");
        printf("Opcion: ");
        scanf("%d", &opc);
    } while (opc < 0 || opc > 2);

    return opc;
}

/* Pide un asiento y lo reserva si esta libre */
void reservarAsiento(int asientos[])
{
    int num;

    do {
        printf("Asiento a reservar (0-%d): ", PLAZAS - 1);
        scanf("%d", &num);
    } while (num < 0 || num >= PLAZAS);

    if (asientos[num] == LIBRE) {
        asientos[num] = OCUPADO;
        printf("Asiento %d reservado\n", num);
    }
    else
        printf("Error: el asiento %d ya estaba reservado\n", num);
}

/* Muestra los asientos libres y cuantos hay */
void verAsientosLibres(int asientos[])
{
    int i, total = 0;

    printf("Asientos libres: ");
    for (i = 0; i < PLAZAS; i++)
        if (asientos[i] == LIBRE) {
            printf("%d ", i);
            total++;
        }
    printf("\nTotal de asientos libres: %d\n", total);
}

int main()
{
    int asientos[PLAZAS];
    int i, opc;

    /* Al principio todos los asientos estan libres */
    for (i = 0; i < PLAZAS; i++)
        asientos[i] = LIBRE;

    do {
        opc = menu();
        switch (opc) {
            case 1:
                reservarAsiento(asientos);
                break;
            case 2:
                verAsientosLibres(asientos);
                break;
            case 0:
                printf("Adios\n");
        }
    } while (opc != 0);

    return 0;
}
