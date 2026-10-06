/* Video 31 - Ficheros en lenguaje C: ejemplo de biblioteca genomica
   genes.txt: una linea por sujeto con  altura(cm)  edad(anios)  CI
   a) Pedir edadMin y edadMax, repitiendo hasta que edadMin <= edadMax.
   b) Mostrar el total de muestras del fichero y, para las muestras con edad
      en [edadMin, edadMax], cuantas hay y su adecuacion genetica (AG) media.
      AG = CI + 10% de la altura + componente edad
      componente edad: 5 si edad >= 60, 10 si 40-59, 15 en otro caso.
      Ej: 163 20 88 -> 88 + 16.3 + 15 = 119.3 */
#include <stdio.h>

int main()
{
    FILE *f;
    int edadMin, edadMax;
    int altura, edad, ci;
    int totalMuestras = 0, totalIntervalo = 0, compEdad;
    float compAltura, totalAG = 0;

    /* a) Peticion del intervalo de edad */
    do {
        printf("Edad minima: ");
        scanf("%d", &edadMin);
        printf("Edad maxima: ");
        scanf("%d", &edadMax);
    } while (edadMin > edadMax);

    /* b) Procesar el fichero linea a linea */
    f = fopen("genes.txt", "r");
    if (f == NULL) {
        printf("Error al abrir el fichero\n");
        return 1;
    }

    while (fscanf(f, "%d %d %d", &altura, &edad, &ci) == 3) {
        totalMuestras++;
        if (edad >= edadMin && edad <= edadMax) {
            totalIntervalo++;
            compAltura = altura * 0.1;
            if (edad >= 60)
                compEdad = 5;
            else if (edad >= 40)
                compEdad = 10;
            else
                compEdad = 15;
            totalAG += ci + compAltura + compEdad;
        }
    }
    fclose(f);

    printf("Total de muestras: %d\n", totalMuestras);
    if (totalIntervalo == 0)
        printf("No hay muestras entre %d y %d anios\n", edadMin, edadMax);
    else
        printf("%d muestras entre %d y %d anios. AG media: %.1f\n",
               totalIntervalo, edadMin, edadMax, totalAG / totalIntervalo);

    return 0;
}
