/*********************************************************************
 * Authors: E. Taber McFarlin, Chris Byrne, and Luke L.
 * We pledge our honor that we have abided by the Stevens Honor System
 * https://www.hackerrank.com/challenges/find-the-running-median/problem
 *********************************************************************/

#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the runningMedian function below.
 */
vector<double> runningMedian(vector<int> a) {
  int median = -1;         // Current median
  vector<double> medians;  // Running median history

  // These heaps hold elements on either side of the median
  priority_queue<double> lowHeap;                                    // < median
  priority_queue<double, vector<double>, greater<double>> highHeap;  // > median

  // Find median at each insertion
  for (int val : a) {
    if (median == -1) {  // There is no middle number
      if (lowHeap.empty() || val >= lowHeap.top() && val <= highHeap.top()) {
        median = val;
      } else if (val < lowHeap.top()) {
        median = lowHeap.top();
        lowHeap.pop();
        lowHeap.push(val);
      } else {
        median = highHeap.top();
        highHeap.pop();
        highHeap.push(val);
      }

      // Add median
      medians.push_back(median);
    } else {
      if (val <= median) {
        lowHeap.push(val);
        highHeap.push(median);
      } else {
        lowHeap.push(median);
        highHeap.push(val);
      }

      // Add median
      median = -1;
      medians.push_back((highHeap.top() + lowHeap.top()) / 2.0);
    }
  }

  return medians;
}

// HackerRank provided main
int main() {
  ofstream fout(getenv("OUTPUT_PATH"));

  int a_count;
  cin >> a_count;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  vector<int> a(a_count);

  for (int a_itr = 0; a_itr < a_count; a_itr++) {
    int a_item;
    cin >> a_item;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    a[a_itr] = a_item;
  }

  vector<double> result = runningMedian(a);

  for (int result_itr = 0; result_itr < result.size(); result_itr++) {
    fout << result[result_itr];

    if (result_itr != result.size() - 1) {
      fout << "\n";
    }
  }

  fout << "\n";

  fout.close();

  return 0;
}
