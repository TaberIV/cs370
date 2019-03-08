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
  long subsums[len];
  long sum = 0;
  long places = 1;
  
  for (int i = len - 1; i >= 0; i--) {
    // places has 1 in each place that the number will be found in,
    // and it's multiplied by i + 1 as that's the number of times it
    // will be found at each place
    sum = (sum + (n[i] - '0') * places * (i + 1)) % MOD;
    places = (places * 10 + 1) % MOD;
  }

  return sum;
}

int main() {
  string n;
  cin >> n;

  cout << substrings(n) << endl;
}