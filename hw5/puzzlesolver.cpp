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
    cerr << "Error: Cannot open file '" << filename << "'." << endl;
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
  printf("Input tiles: \n");
  for (piece p : pieces) {
    cout << p.num << ". ";
    p.print();
  }
  cout << endl;

  puzzle puzz = puzzle(pieces);

  return 0;
}
