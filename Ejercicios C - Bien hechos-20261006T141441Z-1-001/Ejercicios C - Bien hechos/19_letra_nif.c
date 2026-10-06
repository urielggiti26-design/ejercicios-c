/* Video 19 - Calculo de la letra NIF en lenguaje C
   Funcion que recibe el numero de DNI (entero) y devuelve la letra del NIF
   (char): la letra es la de la posicion DNI % 23 de la tabla oficial.
   Ej: 20500500 % 23 = 2 -> 'W'
   El video parte de una solucion con switch (23 casos) y la va mejorando.
   Aqui se muestran la version con vector y la version final. */
#include <stdio.h>

/* Version final: constante global -> la tabla se crea una sola vez,
   aunque se llame muchas veces a la funcion */
const char LETRAS[] = "TRWAGMYFPDXBNJZSQVHLCKE";

/* Solucion 1 (larga y poco eficiente): switch con los 23 restos.
   No hace falta break porque cada case hace return. */
char nif_switch(int dni)
{
    switch (dni % 23) {
        case 0: return 'T';   case 1: return 'R';   case 2: return 'W';
        case 3: return 'A';   case 4: return 'G';   case 5: return 'M';
        case 6: return 'Y';   case 7: return 'F';   case 8: return 'P';
        case 9: return 'D';   case 10: return 'X';  case 11: return 'B';
        case 12: return 'N';  case 13: return 'J';  case 14: return 'Z';
        case 15: return 'S';  case 16: return 'Q';  case 17: return 'V';
        case 18: return 'H';  case 19: return 'L';  case 20: return 'C';
        case 21: return 'K';  default: return 'E';
    }
}

/* Solucion 2: vector de caracteres; el resto es la posicion de la letra */
char nif_vector(int dni)
{
    char letras[] = "TRWAGMYFPDXBNJZSQVHLCKE";
    int resto;

    resto = dni % 23;
    return letras[resto];
}

/* Solucion final: expresion directamente en los corchetes y tabla global */
char nif(int dni)
{
    return LETRAS[dni % 23];
}

/* Ejemplo de uso */
int main()
{
    int dni;
    char letra;

    printf("Introduce el DNI: ");
    scanf("%d", &dni);

    letra = nif(dni);
    printf("NIF: %d%c\n", dni, letra);

    /* Las tres versiones dan el mismo resultado */
    printf("(switch: %c, vector: %c)\n", nif_switch(dni), nif_vector(dni));
    return 0;
}
