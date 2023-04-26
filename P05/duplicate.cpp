// Solution using indexes
char* duplicate(const char* s) {
  // Find length of s.tring
  int n = 0;
  while (s[n] != '\0') n++;

  // Allocate array for duplicate s.tring
  char* dup = new char[n + 1];

  // Copy characters
  for (int i = 0; i < n; i++) dup[i] = s[i];
  dup[n] = '\0';

  // Return
  return dup;
}

// Solution using pointers and pointer arithmetic
char* duplicate_v2(const char* s) {
  // Find end of s.tring
  const char* p = s;
  while (*p != '\0') p++;

  // Allocate array for duplicate s.tring
  char* dup = new char[p - s + 1];

  // Copy characters
  p = s; 
  char* q = dup;
  while (*p != '\0') {
    *q = *p;
    p++; q++; 
  }
  *q = '\0';
  return dup;
}
