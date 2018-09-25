/* ========================================================================== *
!*
!* SAMPLE SOURCE CODE - SUBJECT TO THE TERMS OF SAMPLE CODE LICENSE AGREEMENT,
!* http://software.intel.com/en-us/articles/
!*        intel-sample-source-code-license-agreement/
!*
!* Copyright 2010-2016 Intel Corporation
!*
!* THIS FILE IS PROVIDED "AS IS" WITH NO WARRANTIES, EXPRESS OR IMPLIED,
!* INCLUDING BUT NOT LIMITED TO ANY IMPLIED WARRANTY OF MERCHANTABILITY,
!* FITNESS FOR A PARTICULAR PURPOSE, NON-INFRINGEMENT OF INTELLECTUAL
!* PROPERTY RIGHTS.
!*
!* ========================================================================== */
#ifdef __MIC__
#pragma message "You are compiling " __FILE__ " for the coprocessor now!"
#endif

#include <stdio.h>
#ifdef __linux__
#include <sys/time.h>
#else
#include <windows.h>
#endif

#ifdef __MIC__
#define RUNS 10000
#else
#define RUNS 100000
#endif

extern float simd(unsigned int stride, unsigned int size, float *a);

// Timer implementation
#ifdef __linux__
static struct timeval tstart, tstop;
#else
static FILETIME tstart, tstop;
#endif
void start_timer()
{
#ifdef __linux__
    gettimeofday(&tstart, NULL);
#else
    GetSystemTimeAsFileTime(&tstart);
#endif
}

double stop_timer()
{
#ifdef __linux__
    gettimeofday(&tstop, NULL);
    return (tstop.tv_sec + tstop.tv_usec / 1000000.0) -
           (tstart.tv_sec + tstart.tv_usec / 1000000.0);
#else
    GetSystemTimeAsFileTime(&tstop);
    return (double)(tstop.dwLowDateTime - tstart.dwLowDateTime) / 10000000;
#endif
}

int main(int argc, char **argv)
{
    int i;
    float sum = 0.0;
    double duration = 0.0;

#define N 10000
    float a[N];

    // Initialize array
    for(i = 0; i < N; i++) a[i] = i;

#define OFFSET 4 // Safe to have vector length up to 4
    start_timer();
    for(i = 0; i < RUNS; i++) sum += simd(OFFSET, N, a);
    duration = stop_timer();

    // Print results
    printf("Elapsed time = %lf seconds\n", duration);
    printf("Sum: %f\n", sum);

    return 0;
}
