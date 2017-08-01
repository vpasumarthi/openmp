#include <iostream>
#include <omp.h>

int main()
{
    std::cout << "OpenMP will use " << omp_get_max_threads() << " threads" << std::endl;
    return 0;
}
