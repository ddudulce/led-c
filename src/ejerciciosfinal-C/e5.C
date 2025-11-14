#include <stdio.h>

#define MAXLINE 1000

/* Función que elimina espacios y tabs finales */
int trim(char line[]) {
    int i = 0;

    /* Buscar fin de línea */
    while (line[i] != '\0') {
        i++;
    }

    /* Retroceder antes del '\n' */
    i--;

    /* Eliminar espacios, tabs y '\n' al final */
    while (i >= 0 && (line[i] == ' ' || line[i] == '\t' || line[i] == '\n')) {
        line[i] = '\0';
        i--;
    }

    /* Regresa la longitud de la línea resultante */
    return i + 1;
}

int main() {
    char line[MAXLINE];

    while (fgets(line, MAXLINE, stdin) != NULL) {
        int len = trim(line);

        /* Si la línea queda vacía, no imprimir */
        if (len > 0) {
            printf("%s\n", line);
        }
    }

    return 0;
}