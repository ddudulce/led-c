#include <stdio.h>
#include <stdlib.h>
#include "simulacion.h"

int main(int argc, char *argv[]) {

    if (argc != 9) {
        printf("Uso correcto:\n");
        printf("./main yo  x  vo  theta  delta_vo  delta_theta  N  Nbins\n\n");
        printf("Ejemplo:\n");
        printf("./main 1.0 10.0 20.0 45.0 0.5 2.0 1000 20\n");
        return 1;
    }

    double yo          = atof(argv[1]);
    double x           = atof(argv[2]);
    double vo          = atof(argv[3]);
    double theta       = atof(argv[4]);
    double delta_vo    = atof(argv[5]);
    double delta_theta = atof(argv[6]);
    int N              = atoi(argv[7]);
    int Nbins          = atoi(argv[8]);

    printf("----- Parámetros de simulación -----\n");
    printf("yo          = %.3f\n", yo);
    printf("x           = %.3f\n", x);
    printf("vo          = %.3f\n", vo);
    printf("theta       = %.3f grados\n", theta);
    printf("delta_vo    = %.3f\n", delta_vo);
    printf("delta_theta = %.3f grados\n", delta_theta);
    printf("N           = %d\n", N);
    printf("Nbins       = %d\n\n", Nbins);

    /* Llamar a la simulación */
    simular_experimento(yo, x, vo, theta, delta_vo, delta_theta, N, Nbins);

    return 0;
}