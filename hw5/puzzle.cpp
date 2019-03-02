#include "puzzlesolver.h"
#include <iostream>
#include <vector>

using namespace std;

class puzzle {
private:
  static vector<puzzle> get_solutions(piece **pieces, puzzle board, bool used[], int i) {
    vector<puzzle> solutions;

    if (i == 9) {
      solutions.push_back(board);
    } else {
      // Check each piece
      for (int p = 0; p < 9; p++) {
        if (!used[p]) {
          // Check each roatation
          for (int r = 0; r < 4; r++) {
            if (board.is_valid(pieces[p][r], i)) {
              // Mark P as used
              bool usedP[9];
              copy(used, used + 9, usedP);
              usedP[p] = true;

              // Recusively call with piece in place
              vector<puzzle> sols =
                  get_solutions(pieces, puzzle::insert(board, pieces[p][r], i), usedP, i + 1);

              // Add any solutions
              solutions.insert(solutions.end(), sols.begin(), sols.end());
            }
          }
        }
      }
    }

    return solutions;
  }

  int rotate_index(int i, int r) {
    if (r == 0) {
      return i;
    } else {
      if (i < 3) {
        return rotate_index(2 + 3 * i, r - 1);
      } else if (i < 6) {
        return rotate_index(i == 3 ? 1 : 7, r - 1);
      } else {
        return rotate_index((i - 6) * 3, r - 1);
      }
    }
  }

public:
  static vector<puzzle> solve(piece _pieces[]) {
    // Create array of pieces in all rotations
    piece **pieces = new piece *[9];
    for (int p = 0; p < 9; p++) {
      pieces[p] = new piece[4];
      pieces[p][0] = _pieces[p];

      for (int r = 1; r < 4; r++) {
        pieces[p][r] = pieces[p][r - 1].rotate();
      }
    }

    // Find valid solutions
    bool used[9] = {false};
    puzzle board;
    return get_solutions(pieces, board, used, 0);
  }

  static puzzle insert(puzzle puzz, piece p, int i) {
    puzzle newPuzz = puzzle(puzz);
    newPuzz.pieces[i] = p;

    return newPuzz;
  }

  piece pieces[9];

  // Default Constructor
  puzzle() {}
  // Copy Constructor
  puzzle(const puzzle &puzz) { copy(puzz.pieces, puzz.pieces + 9, pieces); }
  puzzle(piece _pieces[]) {
    for (int i = 0; i < 9; i++) {
      pieces[i] = _pieces[i];
    }
  }
  ~puzzle() {}

  bool is_valid(piece p, int i) {
    // Check above
    if (i >= 3) {
      if (!complements(p.edges[0], pieces[i - 3].edges[2])) {
        return false;
      }
    }

    // Check left
    if (i % 3 != 0) {
      if (!complements(p.edges[3], pieces[i - 1].edges[1])) {
        return false;
      }
    }

    // If no bad cases return true
    return true;
  }

  bool operator==(const puzzle &puzz) {
    if (pieces[4].num != puzz.pieces[4].num) {
      return false;
    }

    // Check each rotation
    for (int r = 0; r < 4; r++) {
      bool equal = true;

      // Check each piece
      for (int p = 0; p < 9; p++) {
        if (p == 4) {
          continue;
        }

        int index = puzzle::rotate_index(p, r);

        if (pieces[index].num != puzz.pieces[p].num) {
          equal = false;
          break;
        }
      }

      if (equal) {
        return true;
      }
    }

    return false;
  }

  friend ostream &operator<<(ostream &output, const puzzle &u) {
    const string hr = "+--------+--------+--------+\n";

    for (int r = 0; r < 3; r++) {
      output << hr;
      for (int e = 0; e < 3; e++) {
        output << "|";
        for (int p = 0; p < 3; p++) {
          // Print edges 0 and 2
          if (e == 0 || e == 2) {
            if (e == 0) {
              output << u.pieces[r * 3 + p].num << "  ";
            } else {
              output << "   ";
            }

            output << u.pieces[r * 3 + p].edges[e] << "   "
                   << "|";
          } else {
            // Print edges 1 and 3
            output << u.pieces[r * 3 + p].edges[3] << "    " << u.pieces[r * 3 + p].edges[1] << "|";
          }
        }
        output << "\n";
      }
    }

    output << hr;
    return output;
  }
};