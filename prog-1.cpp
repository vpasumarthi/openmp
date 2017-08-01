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
    int x = -1;

    a.resize(size);

    //double start = omp_get_wtime(); // returns present timestamp in double

#pragma omp parallel default(none) shared(a) private(x)
{
    x = omp_get_thread_num() + 100;

#pragma omp for
    for (int i = 0; i < size; i++)
    {
        a[i] = 0;
        for (int j = 0; j < size; j++)
        {
            a[i] += sqrt(sqrt(i+j));
        }
   }
}

    std::cout << "x = " << x << std::endl;

    //double stop = omp_get_wtime();
    //std::cout << "time: " << stop - start << std::endl;
    return 0;
}
