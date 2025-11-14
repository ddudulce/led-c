#include <stdio.h>

int main() {
    int c;

    while ((c = getchar()) != EOF) {

        if (c == '\t') {
            /* Secuencia para mostrar una tabulación */
            putchar('>');
            putchar('\b');   /* retroceso */
            putchar('-');
        }
        else if (c == '\b') {
            /* Secuencia para mostrar un retroceso */
            putchar('<');
            putchar('\b');
            putchar('-');
        }
        else {
            putchar(c);
        }
    }

    return 0;
}

/*
========== EJEMPLO =============

ENTRADA (los tabs se ven como \t aquí solo para mostrar):
hola\tmundo
abc\t\tdef
hola\bX

SALIDA VISIBLE:
hola>-mundo
abc>- >-def
hola<-X
*/
