void trim(char s[]) {
  int i = 0;
  // Skip leading spaces
  while (s[i] != 0 && s[i] == ' ') {
    i++;
  }
  if (s[i] == 0) {
    // reached end - all spaces!
    s[0] = 0;
    return; 
  }
  // Find end
  int j = i + 1;
  while (s[j] != 0) {
    j++;
  }
  // Skip and erase trailing spaces
  do { 
    j--; 
  } while (s[j] == ' ');
  // Trim!
  if (i > 0) {
    // There are leading spaces. Move characters.
    int k = i;
    while (k <= j) {
      s[k - i] = s[k];
      k++;
    }
  } 
  // Don't forget the null terminator!
  s[j - i + 1] = 0;
}