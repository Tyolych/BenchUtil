#ifndef __BENCH_UTILS_H_INCLUDED__
#define __BENCH_UTILS_H_INCLUDED__

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define SECONDS 5

static int get_number_of_threads(int argc, char** argv)
{
    int n; 
        
    if (argc <= 1 ) 
    {
        //printf("Number of CPU cores to run Benchmark: ");
        //scanf("%d", &n);
        return 1;
    }
    
    if (argv == NULL || argv[1] == NULL)
    {
        return 1;
    }    
    
    n = atoi(argv[1]);    
    if (n < 1) n = 1;
    
    return n;
}

#endif // __BENCH_UTILS_H_INCLUDED__
