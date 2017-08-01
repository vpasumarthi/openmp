#include <sstream>
#include <iostream>
#include <omp.h>

int main()
{
#pragma omp parallel //prompts compiler to execute the next block of code in braces in parallel
    {
        std::stringstream ss;
        ss << "OpenMP will use " << omp_get_max_threads() << " threads." << std::endl;
        std::cout << ss.str();
    }
    return 0;
}
