# Loop Unrolling Performance Analysis

## Overview
This project explores the optimization technique of loop unrolling and its impact on the performance of a simple computation loop. By comparing the execution times of a standard loop against various unrolled loops with different unrolling degrees, we aim to understand how loop unrolling can affect the efficiency of code execution on modern CPUs.

## Features
- Implement a standard loop and unrolled loops with 4, 8, 16, and 64 degrees.
- High-resolution timing functions to measure execution times accurately.
- Speedup calculations to compare the performance of unrolled loops against the standard loop.
- Support for multiple array sizes to analyze performance impact across different data volumes.

## Requirements
- GCC compiler or any compatible C compiler
- POSIX-compliant system for the `clock_gettime` function (most Unix-like systems, including Linux and macOS, should work)

## Getting Started

### Compilation
To compile the project, ensure that compiler optimizations are disabled to measure the effects of manual loop unrolling accurately. Use the following command:

```sh
gcc -O0 -o loop_unrolling_test main.c
