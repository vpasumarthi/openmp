#include <iostream>
#include <omp.h>

int main()
{
    std::cout << "OpenMP will use " << omp_get_num_threads() << " threads" << std::endl;
    return 0;
}
