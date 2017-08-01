#include <sstream>
#include <iostream>
#include <omp.h>
#include <vector>
#include <stdio.h>
#include <math.h>

int main()
{
    const int size = 10000;
    std::vector<double> a;

    a.resize(size);

    double start = omp_get_wtime(); // returns present timestamp in double

    for (int i = 0; i < size; i++) {
        a[i] = 0;
        for (int j = 0; j < size; j++)
        {
            a[i] += sqrt(sqrt(i+j));
        }
    }

    double stop = omp_get_wtime();
    std::cout << "time: " << stop - start << std::endl;
    return 0;
}
