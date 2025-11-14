#include <stdio.h>

#define MAXWORD 100   /* longitud máxima de palabra que contamos */

int main() {
    int c;
    int length = 0;
    int word_lengths[MAXWORD] = {0};

    while ((c = getchar()) != EOF) {

        if (c == ' ' || c == '\t' || c == '\n') {
            /* Fin de una palabra */
            if (length > 0) {
                if (length < MAXWORD) {
                    word_lengths[length]++;
                }
                length = 0;
            }
        } else {
            /* Contando caracteres dentro de una palabra */
            length++;
        }
    }

    /* Si el archivo termina mientras estamos en una palabra */
    if (length > 0 && length < MAXWORD) {
        word_lengths[length]++;
    }

    /* Imprimir histograma */
    printf("=== HISTOGRAMA DE LONGITUDES DE PALABRAS ===\n\n");

    for (int i = 1; i < MAXWORD; i++) {
        if (word_lengths[i] > 0) {
            printf("%2d: ", i);
            for (int j = 0; j < word_lengths[i]; j++) {
                putchar('*');
            }
            putchar('\n');
        }
    }

    return 0;
}
