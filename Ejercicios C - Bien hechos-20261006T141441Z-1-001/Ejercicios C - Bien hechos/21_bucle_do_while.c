/* Video 21 - Implementacion de bucles en C con do ... while
   La condicion se comprueba DESPUES de cada iteracion (minimo 1 iteracion)
   y tras el parentesis de la condicion SI va punto y coma.
   Ejemplo del video: nota media de una clase. Se piden notas hasta que el
   usuario introduce un valor negativo o mayor que 10. */
#include <stdio.h>

int main()
{
    float nota, suma = 0;
    int alumnos = 0;

    do {
        printf("Introduce una nota (negativa o > 10 para terminar): ");
        scanf("%f", &nota);
        if (nota >= 0 && nota <= 10) {   /* es una nota valida */
            suma += nota;
            alumnos++;
        }
    } while (nota >= 0 && nota <= 10);

    /* Si no se ha introducido ninguna nota valida no se puede dividir entre 0 */
    if (alumnos > 0)
        printf("Nota media: %.2f\n", suma / alumnos);
    else
        printf("No se han introducido notas\n");

    return 0;
}
