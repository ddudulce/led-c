#ifndef SIMULACION_H
#define SIMULACION_H

double normal_random(double mu, double sigma);

double simular_experimento(
    double yo, double x,
    double vo,
    double theta,
    double delta_vo,
    double delta_theta,
    int N,
    int Nbins
);

#endif