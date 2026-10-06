/* Video 45 - Ordenacion en C de vectores de temperatura y lluvia
   Leer la lluvia (pluviometria) y la temperatura media de los 12 meses,
   ordenar los meses de mas a menos lluvia y, a igual lluvia, primero los
   meses mas frios. Mostrar los datos ordenados.
   Tres vectores relacionados por la posicion: pluv, temp y meses (numero de
   mes al que corresponden los datos). Todo intercambio se hace en los tres. */
#include <stdio.h>
#define M 12

void leerDatos(float p[], float t[], int m[])
{
    int i;

    for (i = 0; i < M; i++) {
        printf("Mes %d - lluvia: ", i + 1);
        scanf("%f", &p[i]);
        printf("Mes %d - temperatura media: ", i + 1);
        scanf("%f", &t[i]);
        m[i] = i + 1;          /* los datos de la posicion i son del mes i+1 */
    }
}

void ordenar(float p[], float t[], int m[])
{
    int j, rango = 1, ordenado = 0, auxM;
    float aux;

    while (ordenado == 0) {
        ordenado = 1;
        for (j = 0; j < M - rango; j++)
            /* desordenados: menos lluvia que el siguiente, o igual lluvia
               y mas temperatura que el siguiente */
            if (p[j] < p[j + 1] || (p[j] == p[j + 1] && t[j] > t[j + 1])) {
                aux = p[j];  p[j] = p[j + 1];  p[j + 1] = aux;
                aux = t[j];  t[j] = t[j + 1];  t[j + 1] = aux;
                auxM = m[j]; m[j] = m[j + 1];  m[j + 1] = auxM;
                ordenado = 0;
            }
        rango++;
    }
}

void listarDatos(float p[], float t[], int m[])
{
    int i;

    for (i = 0; i < M; i++)
        printf("Mes %2d: lluvia %.1f, temperatura %.1f\n", m[i], p[i], t[i]);
}

int main()
{
    float pluv[M], temp[M];
    int meses[M];

    leerDatos(pluv, temp, meses);
    ordenar(pluv, temp, meses);
    listarDatos(pluv, temp, meses);
    return 0;
}
