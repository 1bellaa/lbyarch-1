#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <immintrin.h>

extern void asmdotproduct(float *A, float *B, float *sdot, int n);

// initialize vectors function

// dot product with SIMD function

int main() {
    // input
    int n;
    printf("Enter the length of the vectors: ");
    scanf("%d", &n);
    
    float *A = (float *)malloc(n * sizeof(float));
    float *B = (float *)malloc(n * sizeof(float));
    float csdot = 0.0f;
    float asmsdot = 0.0f;

    // clock, time

    return 0;
}