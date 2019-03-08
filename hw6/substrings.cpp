/**
 * Authors: Taber McFarlin, Chris Byrne, and Luke L
 * We pledge our honor that we have abided by the Stevens Honor System
 */
#include <iostream>
#include <string>

#define MOD 1000000007;

using namespace std;

unsigned long long substrings(string n) {
  int len = n.length();
  cout << "len: " << len << endl;
  unsigned long long *subsums[len];
  unsigned long long sum = 0;

  for (int i = 0; i < len; i++) {
    // cout << "i: " << i << endl;
    subsums[i] = new unsigned long long[len - i];
    subsums[i][0] = n[i] - '0';
    sum = (sum + subsums[i][0]) % MOD;
    for (int j = 1; j + i < len; j++) {
      // cout << "j: " << j << endl;
      subsums[i][j] = (subsums[i][j - 1] * 10 + (n[i + j] - '0')) % MOD;
      sum = (sum + subsums[i][j]) % MOD;
    }
  }

  return sum;
}

int main() {
  string n;
  cin >> n;

  cout << substrings(n) << endl;
}