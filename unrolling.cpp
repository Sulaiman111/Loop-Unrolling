#include <immintrin.h>
#include <stdio.h>
#include <time.h>

#define DATA float

const int SIZE = 1024;

DATA A[SIZE];
DATA B[SIZE];

double seconds() {
    struct timespec now;
    clock_gettime(CLOCK_MONOTONIC, &now);
    return now.tv_sec + now.tv_nsec / 1000000000.0;
}

void initialize_array(DATA a[], int size) {
    for (int i = 0; i < size; i++) {
        a[i] = a[i] + 5;
    }
}

void normal(DATA a[], int size) {
    for (int i = 0; i < size; i++) {
        a[i] = a[i] * 2; // Example computation
    }
}

void unrolled_4(DATA a[], int size) {
    for (int i = 0; i < size; i += 4) {
        a[i] = a[i] * 2; // Example computation
        a[i+1] = a[i+1] * 2; // Example computation
        a[i+2] = a[i+2] * 2; // Example computation
        a[i+3] = a[i+3] * 2; // Example computation
    }
}

void unrolled_16(DATA a[], int size) {
    for (int i = 0; i < size; i += 16) {
        for (int j = 0; j < 16; j++) {
            a[i+j] = a[i+j] * 2; // Example computation
        }
    }
}

void unrolled_64(DATA a[], int size) {
    for (int i = 0; i < size; i += 64) {
        for (int j = 0; j < 64; j++) {
            a[i+j] = a[i+j] * 2; // Example computation
        }
    }
}

int main() {
    double before, after;
    double normal_time, unrolled_4_time, unrolled_16_time, unrolled_64_time;
    
    initialize_array(A, SIZE);
    
    before = seconds();
    normal(A, SIZE);
    after = seconds();
    normal_time = after - before;
    printf("Normal Time: %f\n", normal_time);
    
    before = seconds();
    unrolled_4(A, SIZE);
    after = seconds();
    unrolled_4_time = after - before;
    printf("Unrolled 4 Time: %f\n", unrolled_4_time);
    
    before = seconds();
    unrolled_16(A, SIZE);
    after = seconds();
    unrolled_16_time = after - before;
    printf("Unrolled 16 Time: %f\n", unrolled_16_time);
    
    before = seconds();
    unrolled_64(A, SIZE);
    after = seconds();
    unrolled_64_time = after - before;
    printf("Unrolled 64 Time: %f\n", unrolled_64_time);
    
    // Calculate speedup
    double speedup_4 = normal_time / unrolled_4_time;
    double speedup_16 = normal_time / unrolled_16_time;
    double speedup_64 = normal_time / unrolled_64_time;
    
    // Print speedup values
    printf("Speedup (Unrolled 4): %f\n", speedup_4);
    printf("Speedup (Unrolled 16): %f\n", speedup_16);
    printf("Speedup (Unrolled 64): %f\n", speedup_64);
    
    return 0;
}