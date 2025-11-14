#include <stdio.h>

/* Tabla Fahrenheit a Celsius con título agregado */

int main(void)
{
    int lower, upper, step;
    float fahr, celsius;

    lower = 0;      /* límite inferior */
    upper = 300;    /* límite superior */
    step  = 20;     /* incremento */

    fahr = lower;

    /* Título agregado */
    printf("=== TABLA DE CONVERSION F -> C ===\n");
    printf("Fahrenheit   Celsius\n");
    printf("----------------------\n");

    while (fahr <= upper) {
        celsius = (5.0/9.0) * (fahr - 32.0);
        printf("%10.0f %10.1f\n", fahr, celsius);
        fahr = fahr + step;
    }

    return 0;
}