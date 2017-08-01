#include <sstream>
#include <iostream>
#include <omp.h>

int main()
{
#pragma omp parallel //prompts compiler to execute the next block of code in braces in parallel
    {
        printf("hello from thread %d of %d\n", omp_get_thread_num(), omp_get_num_threads());
    }
    return 0;
}
