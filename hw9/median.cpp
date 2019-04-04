#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the runningMedian function below.
 */
vector<double> runningMedian(vector<int> a) {
  vector<double> medians;
  priority_queue<double> lowHeap;
  priority_queue < double, vector<double>, greater<double> highHeap;

  double median = 0;
  int med1 = 0, med2 = 0;

  for (int val : a) {
    (val > median ? highHeap : lowHeap).push(val);

    if (highHeap.size() != lowHeap.size()) {
      if (highHeap.size() > lowHeap.size()) {
        med2 = highHeap.pop();
      } else {
        med1 = lowHeap.pop();
      }
    }

    medians.push(median);
  }

  return medians;
}

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
