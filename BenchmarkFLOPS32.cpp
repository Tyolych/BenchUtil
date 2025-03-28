#include "BenchUtil.h"

void *calculateFLOPS32 (void *arg) {
    unsigned long long noOfOperations = 0, loopOperations = 30;
    float a = 124.235250001, b = 21.241201001, c = 2342.234320000, d = 23.3240000000001, e= 2.341200000100000, g = 1231.12003001, h =567.40012007, k =24.0010001001, l =342.24003003006, m= 324.2352500060006, n = 51.2412487236, o = 242.23432, p = 112.34142738462, r = 853.2114414, s = 31.125646724, t =67.451241564, u = 34.447892317, w =3.244427389, x =89.13189230, y =123.23782349, v1 =0.000001000023, v2 = 3.000009000009, v3 = 56.5000000204, v4 = 0.00000090009, v5 = 787.43777777;

    while (1) {
        c *= ((((d + e) + (v5 * v5)) * ((a * (v1 + v2)) + (b * (o + p))) + ((g * h) + (x * y)) * (t + u) + ((k * l) + (g * k)) * (w * l)) * (((m * n) + (k + n)) + ((r * s) + (v3 * v4))));
        *((unsigned long long *)arg) = noOfOperations += loopOperations;
    }
}


void initFLOPS32 (const int POOL) {

    time_t	now; time(&now);
    pthread_t memThreads[POOL];
    unsigned long long flopsLog[POOL][6];
    unsigned long long flops[6], tFlops[POOL], maxflops = 0, temp = 0, singleCoreMax = 0;

    for (int i = 0 ; i < 1; i++) {
        if (i == 0)
            for (int r = 0; r < POOL; r++) {
                tFlops[r] = 0;
                flopsLog[r][i] = 0;
                pthread_create(&memThreads[r], NULL, calculateFLOPS32, &tFlops[r]);
            }
        printf("please wait: it takes %d seconds", SECONDS); fflush(stdout);
        sleep(SECONDS);
        for (int r = 0; r < POOL; r++)
            flopsLog[r][i] = tFlops[r];
    }

    for (int i = 0; i < POOL; i++)
        pthread_cancel(memThreads[i]);

    FILE *fptr;
    fptr = fopen("flopsBench.txt", "a");
    fprintf(fptr, "\n%s", ctime(&now));
    fprintf(fptr, "Benchmarking for 32 Bit Floating point operations per second\n");

    for (int i = 0; i < 1; i++) {
        flops[i] = 0;
        printf("%d| ", i + 1);
        fprintf(fptr, "%d| ", i + 1);
        for (int r = 0; r < POOL; r++) {
            temp = (i == 0) ? (flopsLog[r][i] / 60) : (flopsLog[r][i] - flopsLog[r][i - 1]) / 60;
            flops[i] += temp;
            singleCoreMax = (temp > singleCoreMax) ? temp : singleCoreMax;
            printf("Tr %d: %llu ", r + 1, temp);
            fprintf(fptr, "Tr %d: %llu ", r + 1, temp);
        }
        printf("FLOPS = %llu\n", flops[i]);
        fprintf(fptr, "FLOPS = %llu\n", flops[i]);
        maxflops = (flops[i] > maxflops) ? flops[i] : maxflops;
    }
    printf("Maximum CPU Throughput: %lf Gigaflops.\n", maxflops / 1000000000.0f);
    printf("Maximum Single Core Throughput: %lf Gigaflops.\n", singleCoreMax / 1000000000.0f);
    fprintf(fptr, "Maximum CPU Throughput: %lf Gigaflops.\n", maxflops / 1000000000.0f);
    fprintf(fptr, "Maximum Single Core Throughput: %lf Gigaflops.\n", singleCoreMax / 1000000000.0f);
    fclose(fptr);
}

int main (int argc, char** argv) {
    
    int n = get_number_of_threads(argc,argv);
    
    printf("Benchmarking for 32 Bit Floating point operations per second\n");
    printf("using %d threads\n",n);
    
    initFLOPS32(n);
    return 0;
}
