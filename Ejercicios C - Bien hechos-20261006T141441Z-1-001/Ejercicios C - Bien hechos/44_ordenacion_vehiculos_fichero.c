/* Video 44 - Ordenacion en C de datos de vehiculos en ficheros
   total.txt: una linea por anio (2010 a 2017) con  anio  unidades_modelo1  unidades_modelo2
   a) Funcion ordena: genera orden.txt con  anio  produccion_total  ordenado de
      forma decreciente por produccion total; a igual produccion, primero el
      anio mas reciente. Devuelve 0 si hay problemas con los ficheros y, si no,
      el anio con menos vehiculos (si hay empate, el mas antiguo).
   b) main que llama a ordena y muestra el resultado. */
#include <stdio.h>
#define ANIOS 8

int ordena()
{
    int a[ANIOS], p[ANIOS];   /* anios y produccion total (relacionados por posicion) */
    int i, j, m1, m2, aux, ordenado, rango;
    FILE *f;

    /* 1. Carga de datos */
    f = fopen("total.txt", "r");
    if (f == NULL)
        return 0;
    for (i = 0; i < ANIOS; i++) {
        fscanf(f, "%d %d %d", &a[i], &m1, &m2);
        p[i] = m1 + m2;
    }
    fclose(f);

    /* 2. Ordenacion (burbuja). Desordenados si:
          - la produccion de j es menor que la de j+1, o
          - es igual y el anio de j es menor (el mas reciente va delante) */
    ordenado = 0;
    rango = 1;
    while (ordenado == 0) {
        ordenado = 1;
        for (j = 0; j < ANIOS - rango; j++)
            if (p[j] < p[j + 1] || (p[j] == p[j + 1] && a[j] < a[j + 1])) {
                aux = p[j]; p[j] = p[j + 1]; p[j + 1] = aux;   /* intercambio en */
                aux = a[j]; a[j] = a[j + 1]; a[j + 1] = aux;   /* ambos vectores */
                ordenado = 0;
            }
        rango++;
    }

    /* 3. Guardar en orden.txt (se reutiliza f) */
    f = fopen("orden.txt", "w");
    if (f == NULL)
        return 0;
    for (i = 0; i < ANIOS; i++)
        fprintf(f, "%d %d\n", a[i], p[i]);
    fclose(f);

    /* El ultimo es el de menor produccion (y, si hay empate, el mas antiguo) */
    return a[ANIOS - 1];
}

int main()
{
    int res;

    res = ordena();
    if (res == 0)
        printf("Error con los ficheros\n");
    else
        printf("Ordenacion correcta. Anio con menos vehiculos: %d\n", res);
    return 0;
}
