#include <fstream>
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
  // Input and sort
  vector<int> numbers{2, 1, 5, 3, 8};
  const int numCount = numbers.size();

  sort(numbers.begin(), numbers.end());

  // 
  int sm_imp = 1;

  for (int i = 0; i < numCount; i++)
  {
    if (numbers[i] <= sm_imp) {
      sm_imp += numbers[i];
    }
    else
    {
      break;
    }
    
  }

  cout << sm_imp;

  return 0;
}