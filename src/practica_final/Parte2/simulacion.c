#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "simulacion.h"
#include <errno.h>

#define PI 3.14159265358979323846
#define G 9.8

/* ---------------------------------------------------------
   Generador de números normales (Box–Muller)
--------------------------------------------------------- */
double normal_random(double mu, double sigma) {
    double u1 = (rand() + 1.0) / (RAND_MAX + 2.0);
    double u2 = (rand() + 1.0) / (RAND_MAX + 2.0);

    double z = sqrt(-2.0 * log(u1)) * cos(2.0 * PI * u2);
    return mu + sigma * z;
}

/* ---------------------------------------------------------
   Simulación del experimento de tiro parabólico
--------------------------------------------------------- */
double simular_experimento(
    double yo, double x,
    double vo,            // velocidad promedio
    double theta,         // ángulo promedio
    double delta_vo,      // desviación estándar de vo
    double delta_theta,   // desviación estándar de theta
    int N,
    int Nbins
) {
    double yf[N];   // valores finales en y
    double sum = 0.0;

    /* ------------------------------
       1. Generar N repeticiones
    ------------------------------ */
    for (int i = 0; i < N; i++) {

        // velocidad con ruido
        double vi = normal_random(vo, delta_vo);

        // ángulo con ruido (convertido a radianes)
        double thetai_deg = normal_random(theta, delta_theta);
        double thetai = thetai_deg * (PI / 180.0);

        // tiempo para llegar a x
        double t = x / (vi * cos(thetai));

        // posición final en y
        yf[i] = yo + vi * sin(thetai) * t - 0.5 * G * t * t;

        sum += yf[i];
    }

    /* ------------------------------
       2. Calcular media y desviación
    ------------------------------ */
    double media = sum / N;

    double sum2 = 0.0;
    for (int i = 0; i < N; i++) {
        sum2 += (yf[i] - media) * (yf[i] - media);
    }

    double desvest = sqrt(sum2 / N);

    /* ------------------------------
       3. Construir histograma
    ------------------------------ */
    double min = yf[0];
    double max = yf[0];

    for (int i = 1; i < N; i++) {
        if (yf[i] < min) min = yf[i];
        if (yf[i] > max) max = yf[i];
    }

    double bin_width = (max - min) / Nbins;
    int bins[Nbins];

    for (int i = 0; i < Nbins; i++)
        bins[i] = 0;

    for (int i = 0; i < N; i++) {
        int bin = (int)((yf[i] - min) / bin_width);
        if (bin == Nbins) bin--; // evitar overflow
        bins[bin]++;
    }

    /* ------------------------------
       4. Imprimir resultados
    ------------------------------ */
    printf("----- Resultados experimento -----\n");
    printf("Media: %.6f\n", media);
    printf("Desviación estándar: %.6f\n", desvest);
    printf("\nHistograma:\n\n");

    for (int i = 0; i < Nbins; i++) {
        double a = min + i * bin_width;
        double b = a + bin_width;
        printf("[%.5f , %.5f] : %d\n", a, b, bins[i]);
    }
    return media;
// ----------------------------------------------------
// 5. Exportar datos a archivo
// ----------------------------------------------------
FILE *f = fopen("datos_yf.txt", "w");
if (!f) {
    printf("No se pudo crear datos_yf.txt\n");
} else {
    printf("ABRIENDO ARCHIVO...\n");

    for (int i = 0; i < N; i++) {
        printf("Escribiendo yf[%d] = %.6f\n", i, yf[i]);  // DEBUG
        fprintf(f, "%.6f\n", yf[i]);
    }

    fclose(f);
    printf("CERRADO ARCHIVO.\n");
}
}