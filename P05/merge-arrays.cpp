int* merge_arrays(const int a[], int na, const int b[], int nb) {
  int* c = new int[na + nb];
  int i = 0, j = 0, k = 0;
  while (i < na && j < nb) {
    if (a[i] < b[j]) {
      c[k] = a[i];
      i++;
    } else {
      c[k] = b[j];
      j++;
    }
    k++;
  }
  while (i < na) {
    c[k] = a[i];
    k++; i++;
  }
  while (j < nb) {
    c[k] = b[j];
    k++; j++;
  }
  return c;
}
