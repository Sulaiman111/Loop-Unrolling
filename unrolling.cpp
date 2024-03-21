//sulaiman kurdi
//computer architecture  2
//assignment 1

#include <immintrin.h>  
#include <stdio.h>
#include <time.h>

#define DATA float

const int SIZE = 1024;

DATA A[SIZE][SIZE][16];
DATA B[SIZE];

// Function prototypes
double seconds() {

    struct timespec now;
    clock_gettime(CLOCK_MONOTONIC, &now);
    return now.tv_sec + now.tv_nsec / 1000000000.0;
}

void initialize_array(DATA a[], int size) {
    for (int i = 0; i < size; i++) {
        a[i] = rand() % 2;
    }
}

void initialize_array_1024_1024(DATA a[][SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            a[i][j] = rand() % 2;
        }
    }
}
//
void initialize_array_1024_1024_16(DATA a[][SIZE][16], int size) {
    for (int i = 0; i < size; i++) {

        for (int j = 0; j < size; j++) {
            for (int k = 0; k < size; k++) {
                a[i][j][k] = rand() % 2;
            }
        }
    }
}

void normal(DATA a[], int size) {
    for (int i = 0; i < size; i++) {
        a[i] = a[i] + 5;
    }
}
//unrolling the loop by 4
void unrolled_4(DATA a[], int size) {
    for (int i = 0; i < size; i += 4) {
        a[i + 0] = a[i + 0] + 5;
        a[i + 1] = a[i + 1] + 5;
        a[i + 2] = a[i + 2] + 5;
        a[i + 3] = a[i + 3] + 5;

    }
}
//unrolling the loop by 8
void unrolled_8(DATA a[], int size) {
    for (int i = 0; i < size; i += 8) {
        a[i + 0] = a[i + 0] + 5;
        a[i + 1] = a[i + 1] + 5;
        a[i + 2] = a[i + 2] + 5;
        a[i + 3] = a[i + 3] + 5;
        a[i + 4] = a[i + 4] + 5;
        a[i + 5] = a[i + 5] + 5;
        a[i + 6] = a[i + 6] + 5;
        a[i + 7] = a[i + 7] + 5;

    }
}
//unrolling the loop by 16
void unrolled_16(DATA a[], int size) {
    for (int i = 0; i < size; i += 16) {
        a[i + 0] = a[i + 0] + 5;
        a[i + 1] = a[i + 1] + 5;
        a[i + 2] = a[i + 2] + 5;
        a[i + 3] = a[i + 3] + 5;
        a[i + 4] = a[i + 4] + 5;
        a[i + 5] = a[i + 5] + 5;
        a[i + 6] = a[i + 6] + 5;
        a[i + 7] = a[i + 7] + 5;
        a[i + 8] = a[i + 8] + 5;
        a[i + 9] = a[i + 9] + 5;
        a[i + 10] = a[i + 10] + 5;
        a[i + 11] = a[i + 11] + 5;
        a[i + 12] = a[i + 12] + 5;
        a[i + 13] = a[i + 13] + 5;
        a[i + 14] = a[i + 14] + 5;
        a[i + 15] = a[i + 15] + 5;
    }
}
//unrolling the loop by 64
void unrolled_64(DATA a[], int size) {
    for (int i = 0; i < size; i += 64) {
        a[i + 0] = a[i + 0] + 5;
        a[i + 1] = a[i + 1] + 5;
        a[i + 2] = a[i + 2] + 5;
        a[i + 3] = a[i + 3] + 5;
        a[i + 4] = a[i + 4] + 5;
        a[i + 5] = a[i + 5] + 5;
        a[i + 6] = a[i + 6] + 5;
        a[i + 7] = a[i + 7] + 5;
        a[i + 8] = a[i + 8] + 5;
        a[i + 9] = a[i + 9] + 5;
        a[i + 10] = a[i + 10] + 5;
        a[i + 11] = a[i + 11] + 5;
        a[i + 12] = a[i + 12] + 5;
        a[i + 13] = a[i + 13] + 5;
        a[i + 14] = a[i + 14] + 5;
        a[i + 15] = a[i + 15] + 5;
        a[i + 16] = a[i + 16] + 5;
        a[i + 17] = a[i + 17] + 5;
        a[i + 18] = a[i + 18] + 5;
        a[i + 19] = a[i + 19] + 5;
        a[i + 20] = a[i + 20] + 5;
        a[i + 21] = a[i + 21] + 5;
        a[i + 22] = a[i + 22] + 5;
        a[i + 23] = a[i + 23] + 5;
        a[i + 24] = a[i + 24] + 5;
        a[i + 25] = a[i + 25] + 5;
        a[i + 26] = a[i + 26] + 5;
        a[i + 27] = a[i + 27] + 5;
        a[i + 28] = a[i + 28] + 5;
        a[i + 29] = a[i + 29] + 5;
        a[i + 30] = a[i + 30] + 5;
        a[i + 31] = a[i + 31] + 5;
        a[i + 32] = a[i + 32] + 5;
        a[i + 33] = a[i + 33] + 5;
        a[i + 34] = a[i + 34] + 5;
        a[i + 35] = a[i + 35] + 5;
        a[i + 36] = a[i + 36] + 5;
        a[i + 37] = a[i + 37] + 5;
        a[i + 38] = a[i + 38] + 5;
        a[i + 39] = a[i + 39] + 5;
        a[i + 40] = a[i + 40] + 5;
        a[i + 41] = a[i + 41] + 5;
        a[i + 42] = a[i + 42] + 5;
        a[i + 43] = a[i + 43] + 5;
        a[i + 44] = a[i + 44] + 5;
        a[i + 45] = a[i + 45] + 5;
        a[i + 46] = a[i + 46] + 5;
        a[i + 47] = a[i + 47] + 5;
        a[i + 48] = a[i + 48] + 5;
        a[i + 49] = a[i + 49] + 5;
        a[i + 50] = a[i + 50] + 5;
        a[i + 51] = a[i + 51] + 5;
        a[i + 52] = a[i + 52] + 5;
        a[i + 53] = a[i + 53] + 5;
        a[i + 54] = a[i + 54] + 5;
        a[i + 55] = a[i + 55] + 5;
        a[i + 56] = a[i + 56] + 5;
        a[i + 57] = a[i + 57] + 5;
        a[i + 58] = a[i + 58] + 5;
        a[i + 59] = a[i + 59] + 5;
        a[i + 60] = a[i + 60] + 5;
        a[i + 61] = a[i + 61] + 5;
        a[i + 62] = a[i + 62] + 5;
        a[i + 63] = a[i + 63] + 5;

    }
}
//normal loop for 1024*1024
void normal_1024(DATA a[][SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            a[i][j] = a[i][j] + 5;
        }
    }
}
//unrolling the loop by 4 for 1024*1024
void unrolled_4_1024(DATA a[][SIZE], int size) {
    for (int i = 0; i < size; i += 4) {
        for (int j = 0; j < size; j += 4) {
            a[i + 0][j + 0] = a[i + 0][j + 0] + 5;
            a[i + 1][j + 1] = a[i + 1][j + 1] + 5;
            a[i + 2][j + 2] = a[i + 2][j + 2] + 5;
            a[i + 3][j + 3] = a[i + 3][j + 3] + 5;
        }
    }
}
//unrolling the loop by 8 for 1024*1024
void unrolled_8_1024(DATA a[][SIZE], int size) {
    for (int i = 0; i < size; i += 8) {
        for (int j = 0; j < size; j += 8) {
            a[i + 0][j + 0] = a[i + 0][j + 0] + 5;
            a[i + 1][j + 1] = a[i + 1][j + 1] + 5;
            a[i + 2][j + 2] = a[i + 2][j + 2] + 5;
            a[i + 3][j + 3] = a[i + 3][j + 3] + 5;
            a[i + 4][j + 4] = a[i + 4][j + 4] + 5;
            a[i + 5][j + 5] = a[i + 5][j + 5] + 5;
            a[i + 6][j + 6] = a[i + 6][j + 6] + 5;
            a[i + 7][j + 7] = a[i + 7][j + 7] + 5;

        }
    }
}
//unrolling the loop by 16 for 1024*1024
void unrolled_16_1024(DATA a[][SIZE], int size) {
    for (int i = 0; i < size; i += 16) {
        for (int j = 0; j < size; j += 16) {
            a[i + 0][j + 0] = a[i + 0][j + 0] + 5;
            a[i + 1][j + 1] = a[i + 1][j + 1] + 5;
            a[i + 2][j + 2] = a[i + 2][j + 2] + 5;
            a[i + 3][j + 3] = a[i + 3][j + 3] + 5;
            a[i + 4][j + 4] = a[i + 4][j + 4] + 5;
            a[i + 5][j + 5] = a[i + 5][j + 5] + 5;
            a[i + 6][j + 6] = a[i + 6][j + 6] + 5;
            a[i + 7][j + 7] = a[i + 7][j + 7] + 5;
            a[i + 8][j + 8] = a[i + 8][j + 8] + 5;
            a[i + 9][j + 9] = a[i + 9][j + 9] + 5;
            a[i + 10][j + 10] = a[i + 10][j + 10] + 5;
            a[i + 11][j + 11] = a[i + 11][j + 11] + 5;
            a[i + 12][j + 12] = a[i + 12][j + 12] + 5;
            a[i + 13][j + 13] = a[i + 13][j + 13] + 5;
            a[i + 14][j + 14] = a[i + 14][j + 14] + 5;
            a[i + 15][j + 15] = a[i + 15][j + 15] + 5;

        }
    }
}
//unrolling the loop by 64 for 1024*1024
void unrolled_64_1024(DATA a[][SIZE], int size) {
    for (int i = 0; i < size; i += 64) {
        for (int j = 0; j < size; j += 64) {
            a[i + 0][j + 0] = a[i + 0][j + 0] + 5;
            a[i + 1][j + 1] = a[i + 1][j + 1] + 5;
            a[i + 2][j + 2] = a[i + 2][j + 2] + 5;
            a[i + 3][j + 3] = a[i + 3][j + 3] + 5;
            a[i + 4][j + 4] = a[i + 4][j + 4] + 5;
            a[i + 5][j + 5] = a[i + 5][j + 5] + 5;
            a[i + 6][j + 6] = a[i + 6][j + 6] + 5;
            a[i + 7][j + 7] = a[i + 7][j + 7] + 5;
            a[i + 8][j + 8] = a[i + 8][j + 8] + 5;
            a[i + 9][j + 9] = a[i + 9][j + 9] + 5;
            a[i + 10][j + 10] = a[i + 10][j + 10] + 5;
            a[i + 11][j + 11] = a[i + 11][j + 11] + 5;
            a[i + 12][j + 12] = a[i + 12][j + 12] + 5;
            a[i + 13][j + 13] = a[i + 13][j + 13] + 5;
            a[i + 14][j + 14] = a[i + 14][j + 14] + 5;
            a[i + 15][j + 15] = a[i + 15][j + 15] + 5;
            a[i + 16][j + 16] = a[i + 16][j + 16] + 5;
            a[i + 17][j + 17] = a[i + 17][j + 17] + 5;
            a[i + 18][j + 18] = a[i + 18][j + 18] + 5;
            a[i + 19][j + 19] = a[i + 19][j + 19] + 5;
            a[i + 20][j + 20] = a[i + 20][j + 20] + 5;
            a[i + 21][j + 21] = a[i + 21][j + 21] + 5;
            a[i + 22][j + 22] = a[i + 22][j + 22] + 5;
            a[i + 23][j + 23] = a[i + 23][j + 23] + 5;
            a[i + 24][j + 24] = a[i + 24][j + 24] + 5;
            a[i + 25][j + 25] = a[i + 25][j + 25] + 5;
            a[i + 26][j + 26] = a[i + 26][j + 26] + 5;
            a[i + 27][j + 27] = a[i + 27][j + 27] + 5;
            a[i + 28][j + 28] = a[i + 28][j + 28] + 5;
            a[i + 29][j + 29] = a[i + 29][j + 29] + 5;
            a[i + 30][j + 30] = a[i + 30][j + 30] + 5;
            a[i + 31][j + 31] = a[i + 31][j + 31] + 5;
            a[i + 32][j + 32] = a[i + 32][j + 32] + 5;
            a[i + 33][j + 33] = a[i + 33][j + 33] + 5;
            a[i + 34][j + 34] = a[i + 34][j + 34] + 5;
            a[i + 35][j + 35] = a[i + 35][j + 35] + 5;
            a[i + 36][j + 36] = a[i + 36][j + 36] + 5;
            a[i + 37][j + 37] = a[i + 37][j + 37] + 5;
            a[i + 38][j + 38] = a[i + 38][j + 38] + 5;
            a[i + 39][j + 39] = a[i + 39][j + 39] + 5;
            a[i + 40][j + 40] = a[i + 40][j + 40] + 5;
            a[i + 41][j + 41] = a[i + 41][j + 41] + 5;
            a[i + 42][j + 42] = a[i + 42][j + 42] + 5;
            a[i + 43][j + 43] = a[i + 43][j + 43] + 5;
            a[i + 44][j + 44] = a[i + 44][j + 44] + 5;
            a[i + 45][j + 45] = a[i + 45][j + 45] + 5;
            a[i + 46][j + 46] = a[i + 46][j + 46] + 5;
            a[i + 47][j + 47] = a[i + 47][j + 47] + 5;
            a[i + 48][j + 48] = a[i + 48][j + 48] + 5;
            a[i + 49][j + 49] = a[i + 49][j + 49] + 5;
            a[i + 50][j + 50] = a[i + 50][j + 50] + 5;
            a[i + 51][j + 51] = a[i + 51][j + 51] + 5;
            a[i + 52][j + 52] = a[i + 52][j + 52] + 5;
            a[i + 53][j + 53] = a[i + 53][j + 53] + 5;
            a[i + 54][j + 54] = a[i + 54][j + 54] + 5;
            a[i + 55][j + 55] = a[i + 55][j + 55] + 5;
            a[i + 56][j + 56] = a[i + 56][j + 56] + 5;
            a[i + 57][j + 57] = a[i + 57][j + 57] + 5;
            a[i + 58][j + 58] = a[i + 58][j + 58] + 5;
            a[i + 59][j + 59] = a[i + 59][j + 59] + 5;
            a[i + 60][j + 60] = a[i + 60][j + 60] + 5;
            a[i + 61][j + 61] = a[i + 61][j + 61] + 5;
            a[i + 62][j + 62] = a[i + 62][j + 62] + 5;
            a[i + 63][j + 63] = a[i + 63][j + 63] + 5;


        }
    }
}
//normal loop for 1024*1024*16
void normal_1024_16(DATA a[][SIZE][16], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            for (int k = 0; k < 16; k++) {
                a[i][j][k] = a[i][j][k] + 5;
            }
        }
    }
}
//unrolling the loop by 4 for 1024*1024*16
void unrolled_4_1024_16(DATA a[][SIZE][16], int size) {
    for (int i = 0; i < size; i += 4) {
        for (int j = 0; j < size; j += 4) {
            for (int k = 0; k < 16; k += 4) {
                a[i + 0][j + 0][k + 0] = a[i + 0][j + 0][k + 0] + 5;
                a[i + 1][j + 1][k + 1] = a[i + 1][j + 1][k + 1] + 5;
                a[i + 2][j + 2][k + 2] = a[i + 2][j + 2][k + 2] + 5;
                a[i + 3][j + 3][k + 3] = a[i + 3][j + 3][k + 3] + 5;
            }
        }
    }
}

void unrolled_8_1024_16(DATA a[][SIZE][16], int size) {
    for (int i = 0; i < size; i += 8) {
        for (int j = 0; j < size; j += 8) {
            for (int k = 0; k < 16; k += 8) {
                a[i + 0][j + 0][k + 0] = a[i + 0][j + 0][k + 0] + 5;
                a[i + 1][j + 1][k + 1] = a[i + 1][j + 1][k + 1] + 5;
                a[i + 2][j + 2][k + 2] = a[i + 2][j + 2][k + 2] + 5;
                a[i + 3][j + 3][k + 3] = a[i + 3][j + 3][k + 3] + 5;
                a[i + 4][j + 4][k + 4] = a[i + 4][j + 4][k + 4] + 5;
                a[i + 5][j + 5][k + 5] = a[i + 5][j + 5][k + 5] + 5;
                a[i + 6][j + 6][k + 6] = a[i + 6][j + 6][k + 6] + 5;
                a[i + 7][j + 7][k + 7] = a[i + 7][j + 7][k + 7] + 5;

            }
        }
    }
}
//unrolling the loop by 16 for 1024*1024*16
void unrolled_16_1024_16(DATA a[][SIZE][16], int size) {
    for (int i = 0; i < size; i += 16) {
        for (int j = 0; j < size; j += 16) {
            a[i+0][j+0][0] = a[i+0][j+0][0] + 5;
            a[i+1][j+1][1] = a[i+1][j+1][1] + 5;
            a[i+2][j+2][2] = a[i+2][j+2][2] + 5;
            a[i+3][j+3][3] = a[i+3][j+3][3] + 5;
            a[i+4][j+4][4] = a[i+4][j+4][4] + 5;
            a[i+5][j+5][5] = a[i+5][j+5][5] + 5;
            a[i+6][j+6][6] = a[i+6][j+6][6] + 5;
            a[i+7][j+7][7] = a[i+7][j+7][7] + 5;
            a[i+8][j+8][8] = a[i+8][j+8][8] + 5;
            a[i+9][j+9][9] = a[i+9][j+9][9] + 5;
            a[i+10][j+10][10] = a[i+10][j+10][10] + 5;
            a[i+11][j+11][11] = a[i+11][j+11][11] + 5;
            a[i+12][j+12][12] = a[i+12][j+12][12] + 5;
            a[i+13][j+13][13] = a[i+13][j+13][13] + 5;
            a[i+14][j+14][14] = a[i+14][j+14][14] + 5;
            a[i+15][j+15][15] = a[i+15][j+15][15] + 5;

        }
    }
}
void unrolled_64_1024_16(DATA a[][SIZE][16], int size) {
    for (int i = 0; i < size; i += 64) {
        for (int j = 0; j < size; j += 64) {
            a[i+0][j+0][0] = a[i+0][j+0][0] + 5;
            a[i+1][j+1][1] = a[i+1][j+1][1] + 5;
            a[i+2][j+2][2] = a[i+2][j+2][2] + 5;
            a[i+3][j+3][3] = a[i+3][j+3][3] + 5;
            a[i+4][j+4][4] = a[i+4][j+4][4] + 5;
            a[i+5][j+5][5] = a[i+5][j+5][5] + 5;
            a[i+6][j+6][6] = a[i+6][j+6][6] + 5;
            a[i+7][j+7][7] = a[i+7][j+7][7] + 5;
            a[i+8][j+8][8] = a[i+8][j+8][8] + 5;
            a[i+9][j+9][9] = a[i+9][j+9][9] + 5;
            a[i+10][j+10][10] = a[i+10][j+10][10] + 5;
            a[i+11][j+11][11] = a[i+11][j+11][11] + 5;
            a[i+12][j+12][12] = a[i+12][j+12][12] + 5;
            a[i+13][j+13][13] = a[i+13][j+13][13] + 5;
            a[i+14][j+14][14] = a[i+14][j+14][14] + 5;
            a[i+15][j+15][15] = a[i+15][j+15][15] + 5;
            a[i+16][j+16][0] = a[i+16][j+16][0] + 5;
            a[i+17][j+17][1] = a[i+17][j+17][1] + 5;
            a[i+18][j+18][2] = a[i+18][j+18][2] + 5;
            a[i+19][j+19][3] = a[i+19][j+19][3] + 5;
            a[i+20][j+20][4] = a[i+20][j+20][4] + 5;
            a[i+21][j+21][5] = a[i+21][j+21][5] + 5;
            a[i+22][j+22][6] = a[i+22][j+22][6] + 5;
            a[i+23][j+23][7] = a[i+23][j+23][7] + 5;
            a[i+24][j+24][8] = a[i+24][j+24][8] + 5;
            a[i+25][j+25][9] = a[i+25][j+25][9] + 5;
            a[i+26][j+26][10] = a[i+26][j+26][10] + 5;
            a[i+27][j+27][11] = a[i+27][j+27][11] + 5;
            a[i+28][j+28][12] = a[i+28][j+28][12] + 5;
            a[i+29][j+29][13] = a[i+29][j+29][13] + 5;
            a[i+30][j+30][14] = a[i+30][j+30][14] + 5;
            a[i+31][j+31][15] = a[i+31][j+31][15] + 5;
            a[i+32][j+32][0] = a[i+32][j+32][0] + 5;
            a[i+33][j+33][1] = a[i+33][j+33][1] + 5;
            a[i+34][j+34][2] = a[i+34][j+34][2] + 5;
            a[i+35][j+35][3] = a[i+35][j+35][3] + 5;
            a[i+36][j+36][4] = a[i+36][j+36][4] + 5;
            a[i+37][j+37][5] = a[i+37][j+37][5] + 5;
            a[i+38][j+38][6] = a[i+38][j+38][6] + 5;
            a[i+39][j+39][7] = a[i+39][j+39][7] + 5;
            a[i+40][j+40][8] = a[i+40][j+40][8] + 5;
            a[i+41][j+41][9] = a[i+41][j+41][9] + 5;
            a[i+42][j+42][10] = a[i+42][j+42][10] + 5;
            a[i+43][j+43][11] = a[i+43][j+43][11] + 5;
            a[i+44][j+44][12] = a[i+44][j+44][12] + 5;
            a[i+45][j+45][13] = a[i+45][j+45][13] + 5;
            a[i+46][j+46][14] = a[i+46][j+46][14] + 5;
            a[i+47][j+47][15] = a[i+47][j+47][15] + 5;
            a[i+48][j+48][0] = a[i+48][j+48][0] + 5;
            a[i+49][j+49][1] = a[i+49][j+49][1] + 5;
            a[i+50][j+50][2] = a[i+50][j+50][2] + 5;
            a[i+51][j+51][3] = a[i+51][j+51][3] + 5;
            a[i+52][j+52][4] = a[i+52][j+52][4] + 5;
            a[i+53][j+53][5] = a[i+53][j+53][5] + 5;
            a[i+54][j+54][6] = a[i+54][j+54][6] + 5;
            a[i+55][j+55][7] = a[i+55][j+55][7] + 5;
            a[i+56][j+56][8] = a[i+56][j+56][8] + 5;
            a[i+57][j+57][9] = a[i+57][j+57][9] + 5;
            a[i+58][j+58][10] = a[i+58][j+58][10] + 5;
            a[i+59][j+59][11] = a[i+59][j+59][11] + 5;
            a[i+60][j+60][12] = a[i+60][j+60][12] + 5;
            a[i+61][j+61][13] = a[i+61][j+61][13] + 5;
            a[i+62][j+62][14] = a[i+62][j+62][14] + 5;
            a[i+63][j+63][15] = a[i+63][j+63][15] + 5;
        }
    }
}

int main() {


    DATA r;
    double x, y, z, w;

    double before, after;
    double normalTime, unrolled4Time, unrolled8Time, unrolled16Time, unrolled64Time;

    // Initialize the 3D array
    initialize_array_1024_1024_16(A, SIZE);

    // Measure normal loop execution time
    before = seconds();
    normal_1024_16(A, SIZE);
    after = seconds();
    normalTime = after - before;

    // Measure unrolled_4 loop execution time
    initialize_array_1024_1024_16(A, SIZE);  // Re-initialize to reset the array
    before = seconds();
    unrolled_4_1024_16(A, SIZE);
    after = seconds();
    unrolled4Time = after - before;

    // Repeat for unrolled_8, unrolled_16, and unrolled_64...

    // Print the times and speedups
    printf("Normal Time: %f\n", normalTime);
    printf("Unrolled 4 Time: %f, Speedup: %f\n", unrolled4Time, normalTime / unrolled4Time);

    // Repeat for unrolled_8, unrolled_16, and unrolled_64 
    printf("Unrolled 8 Time: %f, Speedup: %f\n", unrolled8Time, normalTime / unrolled8Time);
    printf("Unrolled 16 Time: %f, Speedup: %f\n", unrolled16Time, normalTime / unrolled16Time);
    printf("Unrolled 64 Time: %f, Speedup: %f\n", unrolled64Time, normalTime / unrolled64Time);


    return 0;
}
