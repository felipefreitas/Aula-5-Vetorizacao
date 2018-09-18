main (int argc, char **argv) {
  float a[100], b[100], c[100], maxval;
  int i = 0, n = 100;

  maxval = 0.; 
  for (i=0; i<n; i++) {
    a[i] = b[i] + c[i];
    maxval = (a[i] > maxval ? a[i] : maxval);
    if (maxval > 1000.0) break;
  }
}
