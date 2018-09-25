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
float simd(unsigned int offset, unsigned int size, float *a)
{
  int i;
  int sum = 0;

  float *ptr = a;

#pragma omp simd
  for (i = 0; i < size - offset; i++)
  {
      // "offset" can be assumed to be at least 4
      a[i + offset] = *ptr;

      ptr += offset / 4; // Always 1 in our example

      // Reduction
      if(a[i] > 0.0)
          sum += a[i];
      else
          sum += -1.0;

  }
  return sum;
}
