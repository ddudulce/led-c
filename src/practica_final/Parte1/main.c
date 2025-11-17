#include <stdio.h>
#include "regresion.h"

int main() {

    // Ejemplo del enunciado
    double coef[] = {2.0, 0.5, -1.0};   // β0 = 2.0, β1 = 0.5, β2 = -1.0
    double x[] = {4.0, 1.0};           // x1 = 4.0, x2 = 1.0

    int n = 2; // número de variables independientes

    double y_pred = predict(coef, x, n);

    printf("Predicción: %.2f\n", y_pred);

    return 0;
}