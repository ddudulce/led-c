#include <stdio.h>

int main() {
    char nombre[50];

    printf("Ingrese un nombre: ");
    scanf("%49s", nombre);

    printf("Hola %s\n", nombre);

    return 0;
}
