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
            FTYPE (*a)[cols], FTYPE *b, FTYPE *x)
{
    int i, j;

    // ATTENTION:
    // This is just an example to demonstrate the effects in case the compiler
    // does not have information at compile time. As this is a matrix vector
    // multiplication, there is no reason to use non-unit strides here.
    // For other algorithms: Think about whether it is possible to reduce
    // runtime variables to compile time constants (e.g. with templates,
    // dedicated function implementations, reduction of parameters, etc.).
    enum { inc_i = 1, inc_j = 1 };

    for (i = 0; i < rows; i += inc_i) {
        for (j = 0; j < cols; j += inc_j) {
            b[i] += a[i][j] * x[j];
        }
    }
}
