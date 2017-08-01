#include <sstream>
#include <iostream>
#include <omp.h>
#include <vector>
#include <stdio.h>
#include <math.h>


double two_body_energy(int i, int j)
{
    return ((double) i + (double) j) / 10.0;
}


int main()
{
    const int nbodies = 100000;
    double energy = 0.0;
    
    double start = omp_get_wtime(); // returns present timestamp in double
#pragma omp parallel for schedule(dynamic) reduction(+:energy)
    for (int i = 0; i < nbodies; i++) {
        for (int j = i+1; j < nbodies; j++) {
            double eij = two_body_energy(i, j);
            energy += eij;
        }
    }

    double stop = omp_get_wtime();
    std::cout << "time: " << stop - start << std::endl;

    printf("energy = %.5lf\n", energy);
    //std::cout << "energy = " << energy << std::endl;
    return 0;
}
