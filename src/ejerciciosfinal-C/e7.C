#include <stdio.h>

#define MAXLINE 1000

/* Lee una línea y devuelve su longitud */
int get_line(char s[], int lim) {
    int c, i = 0;

    while (i < lim - 1 && (c = getchar()) != EOF && c != '\n')
        s[i++] = c;

    if (c == '\n') {
        s[i++] = c;
    }

    s[i] = '\0';
    return i;
}

/* Función que invierte una cadena s */
void reverse(char s[]) {
    int i = 0, j = 0;
    char temp;

    /* Encontrar el final real de la cadena (antes del '\n') */
    while (s[j] != '\0' && s[j] != '\n')
        j++;

    j--;  // Retroceder al último carácter útil

    /* Intercambiar extremos hacia el centro */
    while (i < j) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        i++;
        j--;
    }
}

int main() {
    char line[MAXLINE];

    while (get_line(line, MAXLINE) > 0) {
        reverse(line);
        printf("%s", line);
    }

    return 0;
}
/* Entrada:hola; Salida: aloh */