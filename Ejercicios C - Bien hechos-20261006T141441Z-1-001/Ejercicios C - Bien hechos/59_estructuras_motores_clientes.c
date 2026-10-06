/* Video 59 - Estructuras y funciones: motores de clientes
   Empresa que fabrica motores electricos y los vende a clientes.
   a) Estructuras:
      cliente: nif (hasta 10 caracteres), provincia (entero), nombre (hasta 100)
      motor:   id (hasta 10 caracteres), anio, potencia, nif del cliente
   b) Funcion motoresClientes: recibe un vector de clientes y su tamano y un
      vector de motores y su tamano; muestra los id de los motores vendidos a
      esos clientes y devuelve cuantos son.
   c) Llamada a la funcion desde main.
   Las cadenas tienen un elemento mas para el '\0'. */
#include <stdio.h>
#include <string.h>   /* strcmp */

struct cliente {
    char nif[11];
    int provincia;
    char nombre[101];
};

struct motor {
    char id[11];
    int anio;
    float potencia;
    char nifCliente[11];
};

int motoresClientes(struct cliente clientes[], int nc, struct motor motores[], int nm)
{
    int i, j, cont = 0;

    for (i = 0; i < nc; i++)              /* cada cliente */
        for (j = 0; j < nm; j++)          /* cada motor */
            if (strcmp(clientes[i].nif, motores[j].nifCliente) == 0) {
                printf("%s\n", motores[j].id);
                cont++;
            }
    return cont;
}

int main()
{
    struct cliente vc[3] = {
        {"12345678A", 46, "Motores Levante SL"},
        {"87654321B", 28, "Electrica Centro SA"},
        {"11223344C", 8,  "Vehiculos Norte SL"}
    };
    struct motor vm[7] = {
        {"M001", 2017, 75.5, "12345678A"},
        {"M002", 2018, 90.0, "99999999Z"},
        {"M003", 2018, 60.0, "87654321B"},
        {"M004", 2019, 120.0, "12345678A"},
        {"M005", 2019, 45.0, "55555555X"},
        {"M006", 2020, 80.0, "11223344C"},
        {"M007", 2020, 100.0, "87654321B"}
    };
    int total;

    total = motoresClientes(vc, 3, vm, 7);   /* solo el nombre de los vectores */
    printf("Motores vendidos a estos clientes: %d\n", total);
    return 0;
}
