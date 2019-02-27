#include <fstream>
#include <iostream>
#include <sstream>
#include "piece.cpp"

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

  // Get all pieces
  Piece pieces[9];

  // Add read errors to the list of exceptions the ifstream will handle.
  input_file.exceptions(ifstream::badbit);
  try {
    // Read pieces
    string line;
    unsigned int line_number = 1;
    while (getline(input_file, line)) {
      cout << line_number << ". <";

      // Read edges
      string edge;
      istringstream piece(line);
      unsigned int edge_number = 0;
      while (getline(piece, edge, ',')) {
        Edge e = {edge[0], edge[1] - '0'};
        pieces[line_number - 1].edges[edge_number] = e;

        // Print edge
        cout << e.color << e.type;
        if (edge_number < 3) {
          cout << ", ";
        }

        ++edge_number;
      }

      cout << ">" << endl;
      ++line_number;
    }
    cout << endl;
    input_file.close();
  } catch (const ifstream::failure &f) {
    cerr << "Error: An I/O error occurred reading '" << argv[1] << "'.";
    return 1;
  }

  // Find valid solutions

  return 0;
}
