/**
 * CS 370
 * Homework 1: Large Sum
 * Authors: Taber McFarlin, Chris Byrne, and Luke Loposky
 * We pledge our honor that we have abided by the Stevens Honor System
 */

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * Add a one digit value to a place in a
 * vector representing a single number
 */
vector<int> addDigit(int amount, int place, vector<int> sum)
{
  if (sum.size() <= place)
  {
    sum.push_back(0);
  }

  sum[place] += amount;

  if (sum[place] >= 10)
  {
    sum[place] -= 10;

    return addDigit(1, place + 1, sum);
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

      sum = addDigit(num[i] - '0', sumIndex, sum);
    }
  }
  
  // Remove leading 0s
  while (sum[sum.size() - 1] == 0 and sum.size() > 1)
  {
    sum.pop_back();
  }

  // Output
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

  cout << "\n";

  // Close file and cleanup
  inFile.close();

  return 0;
}
