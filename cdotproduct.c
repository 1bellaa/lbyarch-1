#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <locale.h>
#include <immintrin.h>

extern void asmdotproduct(float *A, float *B, float *sdot, int n);

// for vector values
void initialize_vectors(float *A, float *B, int n) {
    for (int i = 0; i < n; i++) {
        A[i] = (float)(rand() % 101); // numbers from 1-100
        B[i] = (float)(rand() % 101);
    }
}

// dot product
void c_dotproduct(float *A, float *B, float *sdot, int n) {
    float sum = 0.0f;
    for (int i = 0; i < n; i++) {
        sum += A[i] * B[i];
    }
    *sdot = sum;
}

int main() {
    int n; 
    
    printf("Enter the length of the vectors (2^20: 1048576 | 2^24: 16777216 | 2^28: 268435456): "); 
    scanf("%d", &n);

    float *A = (float *)malloc(n * sizeof(float)); 
    float *B = (float *)malloc(n * sizeof(float));

    float c_sdot = 0.0f; 
    float asm_sdot = 0.0f;

    initialize_vectors(A, B, n);

    // printf("\nVector A contents: ");
	// for(int i = 0; i < n; i++)
	// 	printf("%.2f ", A[i]);
		
	// printf("\n\nVector B contents: ");
	// for(int i = 0; i < n; i++)
	// 	printf("%.2f ", B[i]);

    int runs = 20; 
    double c_time = 0.0;
    double asm_time = 0.0;

    for (int i = 0; i < runs; i++) { 
        clock_t start, end; 
        
        // C Kernel 
        start = clock(); 
        c_dotproduct(A, B, &c_sdot, n); 
        end = clock(); 
        c_time += (double)(end - start) / CLOCKS_PER_SEC; 
        
        //ASM Kernel 
        start = clock(); 
        asmdotproduct(A, B, &asm_sdot, n); 
        end = clock(); 
        asm_time += (double)(end - start) / CLOCKS_PER_SEC; 
    }

    printf("\nResults:\n"); 
    printf("Vector size: %d\n", n); 
    printf("C Kernel Avg Time: %f seconds\n", c_time / runs); 
    printf("ASM Kernel Avg Time: %f seconds\n", asm_time / runs); 
    printf("Final dot product (C): %.2f\n", c_sdot); 
    printf("Final dot product (ASM): %.2f\n", asm_sdot); 
    
    free(A); 
    free(B);

    return 0;
}