#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "simulacion.h"
double normal_random(double mu, double sigma) {
    double u1 = (rand() + 1.0) / (RAND_MAX + 2.0);
    double u2 = (rand() + 1.0) / (RAND_MAX + 2.0);
    double z = sqrt(-2.0 * log(u1)) * cos(2.0 * M_PI * u2);
    return mu + sigma * z;
}
double simular_experimento(double yo, double x, double vo, double delta_vo,
                           double theta, double delta_theta,
                           int N, int Nbins)
{
    srand(100);  // Semilla fija para reproducibilidad

    double resultados[N];
    double min_val = 1e9, max_val = -1e9;

    printf("Simulando %d repeticiones...\n", N);

    for (int i = 0; i < N; i++) {
        // generar velocidad perturbada
        double vo_err = normal_random(vo, delta_vo);

        // generar ángulo perturbado (convertir a radianes)
        double theta_err = normal_random(theta, delta_theta) * (M_PI / 180.0);

        // tiempo hasta llegar a x
        double t = x / (vo_err * cos(theta_err));

        // calcular yf usando ecuaciones de movimiento
        double yf = yo + vo_err * sin(theta_err) * t - 0.5 * 9.8 * t * t;

        resultados[i] = yf;

        if (yf < min_val) min_val = yf;
        if (yf > max_val) max_val = yf;
    }

    // =============================
    //         HISTOGRAMA
    // =============================
    double bin_width = (max_val - min_val) / Nbins;
    int hist[Nbins];

    for (int i = 0; i < Nbins; i++)
        hist[i] = 0;

    for (int i = 0; i < N; i++) {
        int bin = (int)((resultados[i] - min_val) / bin_width);
        if (bin == Nbins) bin--;  // caso borde
        hist[bin]++;
    }

    // =============================
    //     MEDIA Y DESVIACIÓN
    // =============================
    double sum = 0.0;
    for (int i = 0; i < N; i++)
        sum += resultados[i];

    double mean = sum / N;

    double var = 0.0;
    for (int i = 0; i < N; i++)
        var += (resultados[i] - mean) * (resultados[i] - mean);

    var /= N;
    double sd = sqrt(var);

    // =============================
    //        SALIDA EN TABLA
    // =============================
    printf("\nResultados:\n");
    printf("Media = %.3f\n", mean);
    printf("Desviacion estandar = %.3f\n", sd);

    printf("\nHistograma:\n");
    for (int i = 0; i < Nbins; i++) {
        double a = min_val + i * bin_width;
        double b = a + bin_width;
        printf("[%.3f , %.3f): %d\n", a, b, hist[i]);
    }

    return mean;
}

