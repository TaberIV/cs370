#include <cstdlib>
#include <iostream>
#include <ctime>
#include <vector>
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

vector<int> add(int amount, int place, vector<int> sum)
{
  if (sum.size() <= place)
  {
    sum.push_back(0);
  }

  sum[place] += amount;

  if (sum[place] >= 10)
  {
    sum[place] -= 10;

    return add(1, place + 1, sum);
  }
  else
  {
    return sum;
  }
}

int main(int argc, char *argv[])
{
  // Open input file
  string inPath = "input.txt";

  ifstream inFile;
  inFile.open(inPath);

  if (!inFile)
  {
    cerr << "Unable to open file: " << inPath;
    exit(1);
  }

  // Proccess
  vector<int> sum;
  sum.push_back(0);
  
  string num;

  while (inFile >> num)
  {
    int len = num.length();

    for (int i = len - 1; i >= 0; i--)
    {
      int sumIndex = len - (i + 1);

      sum = add(num[i] - '0', sumIndex, sum);
    }
  }

  // Output
  
  // Remove leading 0s
  
  while (sum[sum.size() - 1] == 0) {
    sum.pop_back();
  }
  
  int sumLen = sum.size();

  cout << "Full sum: ";
  for (int i = sumLen - 1; i >= 0; i--)
  {
    cout << sum[i];
  }

  cout << "\nFirst 10 digits: ";
  for (int i = sumLen - 1; i >= sumLen - 10 && i >= 0; i--)
  {
    cout << sum[i];
  }

  // Close file and cleanup
  inFile.close();

  return 0;
}
