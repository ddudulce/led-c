#include <stdio.h>

#define MAXLINE 1000   /* Tamaño máximo permitido de una línea */

/* Función que lee una línea y devuelve su longitud */
int get_line(char s[], int lim) {
    int c, i = 0;

    while (i < lim - 1 && (c = getchar()) != EOF && c != '\n') {
        s[i++] = c;
    }

    if (c == '\n') {      /* incluir el salto de línea */
        s[i++] = c;
    }

    s[i] = '\0';          /* fin de cadena */
    return i;             /* longitud total */
}

int main() {
    char line[MAXLINE];
    int len;

    while ((len = get_line(line, MAXLINE)) > 0) {
        if (len > 80) {                /* condición pedida */
            printf("%s", line);
        }
    }

    return 0;
}
/* Para probar el programa se puede utilizar la entrada: hola
esta es una línea muy larga que definitivamente sobrepasa los 80 caracteres porque así la estoy escribiendo
test*/