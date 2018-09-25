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

#include "multiply.h"

#pragma omp declare simd notinbranch
FTYPE mult(FTYPE a, FTYPE x)
{
        return a * x;
}

void matvec(unsigned int rows, unsigned int cols,
            FTYPE (*a)[cols], FTYPE *b, FTYPE *x)
{
    int i, j;

    enum { inc_i = 1, inc_j = 1 };

    for (i = 0; i < rows; i += inc_i) {
        // Need temporary because OpenMP does not allow references as part of
        // reduction clauses (yet)!
        FTYPE tmp = 0;
#pragma omp simd linear(j:inc_j) reduction(+:tmp)
        for (j = 0; j < cols; j += inc_j) {
            tmp += mult(a[i][j], x[j]);
        }
        b[i] += tmp;
    }
}
