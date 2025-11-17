#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "simulacion.h"
#define PI 3.14159265358979323846
double normal_random(double mu, double sigma) {
    double u1 = (rand() + 1.0) / (RAND_MAX + 2.0);
    double u2 = (rand() + 1.0) / (RAND_MAX + 2.0);
    double z = sqrt(-2.0 * log(u1)) * cos(2.0 * PI * u2);
    return mu + sigma * z;
}
double simular_experimento(
    double yo, double x, double vo, double v,
    double theta, double delta_theta,
    int N, int Nbins
) {
    double *errores = malloc(N * sizeof(double));
    if (!errores) {
        printf("Error: no se pudo asignar memoria.\n");
        return 0.0;
    }

    // 1. Generar errores angulares normales
    for (int i = 0; i < N; i++) {
        double err = normal_random(0.0, delta_theta);   // ruido en grados
        err = err * (PI / 180.0);                       // convertir a radianes
        errores[i] = err;
    }

    // 2. Encontrar valores mínimo y máximo
    double min = errores[0], max = errores[0];
    for (int i = 1; i < N; i++) {
        if (errores[i] < min) min = errores[i];
        if (errores[i] > max) max = errores[i];
    }

    // 3. Construir histograma
    double bin_size = (max - min) / Nbins;
    int *hist = calloc(Nbins, sizeof(int));

    for (int i = 0; i < N; i++) {
        int idx = (int)((errores[i] - min) / bin_size);
        if (idx == Nbins) idx--;  // corrige el borde derecho
        hist[idx]++;
    }

    // 4. Calcular media
    double suma = 0.0;
    for (int i = 0; i < N; i++) {
        suma += errores[i];
    }
    double media = suma / N;

    // 5. Calcular desviación estándar
    double var = 0.0;
    for (int i = 0; i < N; i++) {
        double d = errores[i] - media;
        var += d * d;
    }
    var /= (N - 1);
    double desviacion = sqrt(var);

    // 6. Imprimir resultados
    printf("---- Resultados experimento ----\n");
    printf("Media: %lf\n", media);
    printf("Desviación estándar: %lf\n", desviacion);
    printf("\nHistograma:\n");

    for (int i = 0; i < Nbins; i++) {
        double bmin = min + i * bin_size;
        double bmax = bmin + bin_size;
        printf("[%lf, %lf] : %d\n", bmin, bmax, hist[i]);
    }

    free(errores);
    free(hist);

    return desviacion;
}


