#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;


void clean_string(string& str) {
  str.erase(str.begin(), find_if(str.begin(), str.end(), [](char c) { return !isspace(c); }));
  str.erase(find_if(str.rbegin(), str.rend(), [](char c) { return !isspace(c); }).base(), str.end());
}

void count_words(const string& str, vector<pair<string, size_t>>& count) {

  string cleaned_str = str;
  transform(cleaned_str.begin(), cleaned_str.end(), cleaned_str.begin(), ::tolower);
  clean_string(cleaned_str);


  unordered_map<string, size_t> word_count;
  size_t start_pos = 0;
  while (start_pos != string::npos) {
    size_t end_pos = cleaned_str.find(' ', start_pos);
    string word = cleaned_str.substr(start_pos, end_pos - start_pos);
    if (!word.empty()) {  
      ++word_count[word];
    }
    start_pos = end_pos != string::npos ? end_pos + 1 : end_pos;
  }


  count.reserve(word_count.size());
  for (const auto& p : word_count) {
    count.emplace_back(p.first, p.second);
  }
  sort(count.begin(), count.end());
}

void show_vector(const vector<pair<string, size_t>>& count) {
  cout << "[ ";
  for (const auto& e : count) {
    cout << e.first << ":" << e.second << ' ';
  }
  cout << "]\n";
}
