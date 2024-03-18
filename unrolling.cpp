#include <immintrin.h>  // portable to all x86 compilers
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DATA float

void seconds(struct timespec *now) {
    clock_gettime(CLOCK_MONOTONIC, now);
}

double time_diff(struct timespec start, struct timespec end) {
    return (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1000000000.0;
}

void initialize_array(DATA a[], int size) {
    for (int i = 0; i < size; i++) {
        a[i] = rand() % 2;
    }
}

void normal(DATA a[], int size) {
    for (int i = 0; i < size; i++) {
        a[i] = a[i] + 5;
    }
}

void unrolled_4(DATA a[], int size) {
    int i;
    for (i = 0; i <= size - 4; i += 4) {
        a[i] = a[i] + 5;
        a[i + 1] = a[i + 1] + 5;
        a[i + 2] = a[i + 2] + 5;
        a[i + 3] = a[i + 3] + 5;
    }
    for (; i < size; i++) {
        a[i] = a[i] + 5;
    }
}

void unrolled_8(DATA a[], int size) {
    int i;
    for (i = 0; i <= size - 8; i += 8) {
        a[i] = a[i] + 5;
        a[i + 1] = a[i + 1] + 5;
        a[i + 2] = a[i + 2] + 5;
        a[i + 3] = a[i + 3] + 5;
        a[i + 4] = a[i + 4] + 5;
        a[i + 5] = a[i + 5] + 5;
        a[i + 6] = a[i + 6] + 5;
        a[i + 7] = a[i + 7] + 5;
    }
    for (; i < size; i++) {
        a[i] = a[i] + 5;
    }
}

void unrolled_16(DATA a[], int size) {
    int i;
    for (i = 0; i <= size - 16; i += 16) {
        for (int j = 0; j < 16; j++) {
            a[i + j] = a[i + j] + 5;
        }
    }
    for (; i < size; i++) {
        a[i] = a[i] + 5;
    }
}

void unrolled_64(DATA a[], int size) {
    int i;
    for (i = 0; i <= size - 64; i += 64) {
        for (int j = 0; j < 64; j++) {
            a[i + j] = a[i + j] + 5;
        }
    }
    for (; i < size; i++) {
        a[i] = a[i] + 5;
    }
}

double measure_and_print(const char *label, void (*func)(DATA *, int), DATA *a, int size) {
    struct timespec before, after;
    seconds(&before);
    func(a, size);
    seconds(&after);
    double time = time_diff(before, after);
    printf("%s Time: %f\\n", label, time);
    return time;
}

int main() {
    const int sizes[] = {1024, 1024*1024, 16*1024*1024};
    const int num_sizes = sizeof(sizes) / sizeof(sizes[0]);
    double normal_time, speedup;

    for (int i = 0; i < num_sizes; i++) {
        int size = sizes[i];
        printf("Array Size: %d\\n", size);
        DATA *A = (DATA *)malloc(size * sizeof(DATA));

        initialize_array(A, size);
        normal_time = measure_and_print("Normal", normal, A, size);

        initialize_array(A, size);
        speedup = normal_time / measure_and_print("Unrolled-4", unrolled_4, A, size);
        printf("Speedup (Unrolled-4): %f\\n", speedup);

        initialize_array(A, size);
        speedup = normal_time / measure_and_print("Unrolled-8", unrolled_8, A, size);
        printf("Speedup (Unrolled-8): %f\\n", speedup);

        initialize_array(A, size);
        speedup = normal_time / measure_and_print("Unrolled-16", unrolled_16, A, size);
        printf("Speedup (Unrolled-16): %f\\n", speedup);

        initialize_array(A, size);
        speedup = normal_time / measure_and_print("Unrolled-64", unrolled_64, A, size);
        printf("Speedup (Unrolled-64): %f\\n", speedup);

        free(A);
        printf("\\n");
    }

    return 0;
}
