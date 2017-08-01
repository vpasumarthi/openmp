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
    const int nbodies = 1000;
    double energy = 0.0;

#pragma omp parallel for
    for (int i = 0; i < nbodies; i++)
    {
        for (int j = 0; j < nbodies; j++)
        {
            double eij = two_body_energy(i, j);
            energy += eij;
        }
   }

    std::cout << "energy = " << energy << std::endl;
    return 0;
}
