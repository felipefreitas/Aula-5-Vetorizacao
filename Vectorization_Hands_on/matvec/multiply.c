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

void matvec(unsigned int rows, unsigned int cols,
            FTYPE (*a)[cols], FTYPE * restrict b, FTYPE *x)
{
    int i, j;

    enum { inc_i = 1, inc_j = 1 };

    for (i = 0; i < rows; i += inc_i) {
    	#pragma ivdep
        for (j = 0; j < cols; j += inc_j) {
            b[i] += a[i][j] * x[j];
        }
    }
}
