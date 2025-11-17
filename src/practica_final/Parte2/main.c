#include <stdio.h>
#include "simulacion.h"

int main() {
    double yo = 1.0;
    double x = 10.0;
    double vo = 5.0;
    double delta_vo = 0.2;
    double theta = 45.0;
    double delta_theta = 3.0;
    int N = 100;
    int Nbins = 10;

    simular_experimento(yo, x, vo, delta_vo, theta, delta_theta, N, Nbins);

    return 0;
}