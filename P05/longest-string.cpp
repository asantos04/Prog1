// find the length of a C-s.tring
int length(const char* s) {
  int l = 0;
  while (s[l] != '\0') l++;
  return l;
}

/// find the longest c-s.tring of the given array
const char* longest(const char* pa[]) {
  int max_len = 0;
  const char* r = nullptr;
  for (int i = 0; pa[i] != nullptr; i++) {
    const char* s = pa[i];
    int l = length(s);
    if (l >= max_len) {
      r = s;
      max_len = l;
    } 
  }
  return r;
}
