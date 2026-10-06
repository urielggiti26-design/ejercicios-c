/* Video 57 - Caracterizacion de alumnos mediante estructuras en lenguaje C
   Estructura para los datos basicos de un alumno: nombre, apellidos,
   direccion, telefono y fecha de nacimiento. La fecha se declara antes como
   otra estructura (dia, mes, anio) y se usa como campo de alumno.
   Se accede a los campos con el operador punto; las cadenas se asignan con
   strcpy. Ampliacion: funcion que muestra los datos de un alumno. */
#include <stdio.h>
#include <string.h>

struct fecha {
    int dia;
    int mes;
    int anio;
};                       /* punto y coma tras la llave */

struct alumno {
    char nombre[50];     /* maximo 49 caracteres + '\0' */
    char apellidos[50];
    char direccion[50];
    int telefono;
    struct fecha fechaNacimiento;
};

void mostrarAlumno(struct alumno al)
{
    printf("Nombre: %s\n", al.nombre);
    printf("Apellidos: %s\n", al.apellidos);
    printf("Direccion: %s\n", al.direccion);
    printf("Telefono: %d\n", al.telefono);
    printf("Fecha de nacimiento: %d/%d/%d\n", al.fechaNacimiento.dia,
           al.fechaNacimiento.mes, al.fechaNacimiento.anio);
}

int main()
{
    struct alumno daniel;
    struct alumno clase[60];       /* vector de 60 alumnos (una clase) */

    daniel.telefono = 963877000;
    strcpy(daniel.nombre, "Daniel");
    strcpy(daniel.apellidos, "Garcia Perez");
    strcpy(daniel.direccion, "Camino de Vera s/n");
    daniel.fechaNacimiento.dia = 25;
    daniel.fechaNacimiento.mes = 3;
    daniel.fechaNacimiento.anio = 2000;

    mostrarAlumno(daniel);

    (void)clase;
    return 0;
}
