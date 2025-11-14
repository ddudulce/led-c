#include <stdio.h>

int main() {
    int c;
    int prev_space = 0;  // indica si ya vimos un espacio antes

    while ((c = getchar()) != EOF) {

        if (c == ' ') {
            if (!prev_space) {
                putchar(' ');
                prev_space = 1;   // marcamos que un espacio ya fue impreso
            }
        } else {
            putchar(c);
            prev_space = 0;   // reiniciar cuando no hay espacio
        }
    }

    return 0;
}

/* 
======== EJEMPLO ==========

ENTRADA:
hola      mundo    en   C
esto     es      una   prueba

SALIDA:
hola mundo en C
esto es una prueba
*/
