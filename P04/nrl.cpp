#include <iostream>
using namespace std;

int nrl(const char s[], char low[]){
  int n = 0;
  int p = 0;
  int count[26] = { 0 };
  for (int i = 0; s[i] != '\0'; i++){
    if(s[i] != ' '){
    if(s[i] >= 'a' && s[i] <= 'z')
      count[s[i] - 'a']++;
    else
      count[s[i] - 'A']++;
      }
  }

  for (int c = 0; c<26; c++){
    if (count[c] == 1){
      n++;
      low[p] = 'a' + c;
      p++;
    }
  }
  low[p] = '\0';
  return n;
}