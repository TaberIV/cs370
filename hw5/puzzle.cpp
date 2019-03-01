#include "puzzlesolver.h"
#include <iostream>
#include <vector>

using namespace std;

class puzzle {
private:
  inline static const string hr = "+--------+--------+--------+\n";

public:
  static vector<puzzle> solve(puzzle puzz) {
    vector<puzzle> solutions;
    solutions.push_back(puzz);
    solutions.push_back(puzz);

    return solutions;
  }

  piece pieces[3][3];

  puzzle(piece _pieces[]) {
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        pieces[i][j] = _pieces[i * 3 + j];
      }
    }
  }
  ~puzzle() {}

  friend ostream &operator<<(ostream &output, const puzzle &u) {
    for (int r = 0; r < 3; r++) {
      output << hr;
      for (int e = 0; e < 4; e++) {
        if (e == 2) {
          continue;
        }

        output << "|";
        for (int p = 0; p < 3; p++) {
          // Print edges 0 and 3
          if (e == 0 || e == 3) {
            if (e == 0) {
              output << u.pieces[r][p].num << "  ";
            } else {
              output << "   ";
            }

            output << u.pieces[r][p].edges[e] << "   "
                   << "|";
          } else {
            // Print edges 1 and 2
            output << u.pieces[r][p].edges[e] << "    "
                   << u.pieces[r][p].edges[e + 1] << "|";
          }
        }
        output << "\n";
      }
    }

    output << hr;
    return output;
  }
};