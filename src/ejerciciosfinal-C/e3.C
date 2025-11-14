#include <stdio.h>

/* Tabla Celsius a Fahrenheit con separador vertical */

int main(void)
{
    int lower = 0;      /* límite inferior */
    int upper = 300;    /* límite superior */
    int step  = 20;     /* incremento */

    float celsius = lower;
    float fahr;

    printf("=== TABLA DE CONVERSION C -> F (MODIFICADA) ===\n");
    printf(" Celsius     |   Fahrenheit\n");
    printf("----------------------------\n");

    while (celsius <= upper) {
        fahr = (9.0/5.0) * celsius + 32.0;
        printf("%7.0f      |     %7.1f\n", celsius, fahr);
        celsius = celsius + step;
    }

    return 0;
}
