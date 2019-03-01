#include "puzzlesolver.h"
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char *argv[]) {
  // Open file with default of input.txt
  string filename;
  if (argc != 2) {
    filename = "input.txt";
  } else {
    filename = argv[1];
  }

  ifstream input_file(filename);

  // Check file exists
  if (!input_file) {
    cerr << "Error: Cannot open file '" << filename << "'." << "\n";
    return 1;
  }

  // Add read errors to the list of exceptions the ifstream will handle.
  input_file.exceptions(ifstream::badbit);

  piece pieces[9];
  try {
    // Read pieces
    string edges;
    unsigned int line_number = 1;
    while (getline(input_file, edges)) {
      piece p = piece(line_number, edges);
      pieces[line_number - 1] = p;
      ++line_number;
    }

    input_file.close();
  } catch (const ifstream::failure &f) {
    cerr << "Error: An I/O error occurred reading '" << argv[1] << "'.";
    return 1;
  }

  // Print input
  cout << "Input tiles:" << "\n";
  for (piece p : pieces) {
    cout << p;
  }
  cout << "\n";

  // Find Solutions
  puzzle puzz = puzzle(pieces);
  vector<puzzle> solutions = puzzle::solve(puzz);

  // Output solutions
  int num_solitions = solutions.size();

  if (num_solitions == 0) {
    cout << "No";
  } else {
    cout << num_solitions << " unique";
  }
  cout << " solution";

  if (num_solitions > 1) {
    cout << "s";
  }

  cout << " found.";

  for (puzzle solution : solutions) {
    cout << "\n" << solution;
  }

  return 0;
}
