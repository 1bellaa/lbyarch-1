#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <immintrin.h>

extern void asmdotproduct(float *A, float *B, float *sdot, int n);

// initialize vectors function

// dot product with SIMD function

int main() {
    int i, n;
	
	printf("Enter value for n: ");
	scanf("%d", &n);
	
	float vec1[n];
	float vec2[n];
	float* vec3 = (float*)malloc(4*sizeof(float));
	
	while(i != n){
		printf("Enter a floating point value for vector 1: \n");
		scanf("%f", &vec1[i]);
		
		printf("Enter a floating point value for vector 2: \n");
		scanf("%f", &vec2[i]);
		
		i++;
	};		
	
	asmdotproduct(n, vec1, vec2, vec3);
	
	printf("\n Array 1 contents:");
	for(i = 0; i < n; i++)
		printf("%.2f ", vec1[i]);
		
	printf("\n Array 2 contents:");
	for(i = 0; i < n; i++)
		printf("%.2f ", vec2[i]);
		
	printf("\n\n");
	printf("DotProduct: %.2f", vec3[0]);

    // clock, time

    return 0;
}