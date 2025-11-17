#include "regresion.h"

double predict(double coef[], double x[], int n) {
    double y = coef[0];  // término independiente β0

    for (int i = 0; i < n; i++) {
        y += coef[i + 1] * x[i];  // βᵢ * xᵢ
    }

    return y;
}