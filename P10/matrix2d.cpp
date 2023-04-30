#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;


void show_vector(const vector<vector<int>>& v) {
  cout << "{";
  for (const auto& line : v) {
    cout << "{ ";
    for (const auto& elem : line)
      cout << elem << ' ';
    cout << "}";
  }
  cout << "}";
}

bool max_filter(vector<vector<int>> &v, int n) {
    if (n==0 or n%2==0) {
        return false;
    }
    int a = v.size();
    int b = v.at(0).size();
    if (a < n or b < n) {
        return false;
    }
    vector<vector<int>> copy = v;
    for (int linha = 0; linha < a;linha++) {
        for (int col = 0; col < b; col++) {
            vector<int> vizinhos;
            for (int i = max(0,linha - (n/2)); i <= min(linha+(n/2), a-1);i++) {
                for (int j = max(0, col - (n/2)); j <= min(col+(n/2),b-1) ;j++) {
                    vizinhos.push_back(v[i][j]);
                }
            }
            sort(vizinhos.begin(), vizinhos.end(), greater<int>());
            copy[linha][col] = vizinhos[0];
        }
    }
    v = copy;
    return true;
}