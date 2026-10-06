/* Video 43 - Ordenacion en C mediante el metodo de la burbuja
   En cada pasada se compara cada elemento con el siguiente y se
   intercambian si estan desordenados; tras cada pasada un elemento mas queda
   en su sitio. La variable "ordenado" permite terminar antes si en una
   pasada no hay intercambios.
   Ejemplo del video: leer las notas de 20 alumnos, ordenarlas de mayor a
   menor y mostrar la nota media de los tres mejores. */
#include <stdio.h>
#define ALUMNOS 20

void leerNotas(float v[], int tam)
{
    int i;

    for (i = 0; i < tam; i++) {
        printf("Nota del alumno %d: ", i + 1);
        scanf("%f", &v[i]);
    }
}

/* Burbuja de mayor a menor: estan desordenados si v[j] < v[j+1].
   (Para ordenar de menor a mayor bastaria con cambiar < por >.) */
void ordenar(float v[], int tam)
{
    int j, rango = 1, ordenado = 0;
    float aux;

    while (ordenado == 0) {
        ordenado = 1;                      /* se supone ordenado */
        for (j = 0; j < tam - rango; j++)
            if (v[j] < v[j + 1]) {         /* intercambio */
                aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;
                ordenado = 0;
            }
        rango++;                           /* cada pasada mira un elemento menos */
    }
}

int main()
{
    float notas[ALUMNOS], media;

    leerNotas(notas, ALUMNOS);     /* los vectores se pasan por referencia */
    ordenar(notas, ALUMNOS);

    media = (notas[0] + notas[1] + notas[2]) / 3;
    printf("Nota media de los tres mejores: %.2f\n", media);
    return 0;
}
