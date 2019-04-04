#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the runningMedian function below.
 */
vector<double> runningMedian(vector<int> a) {
  double median = 0;
  vector<double> medians;
  vector<int> mids;  // For when the median is the average of two elements

  priority_queue<double> lowHeap;
  priority_queue<double, vector<double>, greater<double>> highHeap;

  for (int val : a) {
    if (mids.empty()) {  // val = a[0]
      median = val;
      mids.push_back(val);
    } else {
      if (mids.size() == 1) {
        // Add second value to mids
        int newMid;

        if (val <= median) {
          lowHeap.push(val);

          newMid = lowHeap.top();
          mids.insert(mids.begin(), newMid);
          lowHeap.pop();
        } else {
          highHeap.push(val);

          newMid = highHeap.top();
          mids.push_back(newMid);
          highHeap.pop();
        }

        // Update median
        median += newMid;
        median /= 2;
      } else {
        // Remove second value from mid
        if (val <= mids[0]) {
          lowHeap.push(val);

          highHeap.push(mids[1]);
          mids.pop_back();
        } else if (val >= mids[1]) {
          highHeap.push(val);

          lowHeap.push(mids[0]);
          mids.erase(mids.begin());
        } else {
          lowHeap.push(mids[0]);
          highHeap.push(mids[1]);

          mids.clear();
          mids.push_back(val);
        }

        // Update median
        median = mids[0];
      }
    }

    medians.push_back(median);
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
