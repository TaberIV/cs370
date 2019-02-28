#include "puzzlesolver.h"
#include <iostream>

using namespace std;

class puzzle {
private:
  const char *hr = "+--------+--------+--------+\n";

public:
  piece pieces[3][3];

  puzzle(piece _pieces[]) {
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        pieces[i][j] = _pieces[i * 3 + j];
      }
    }
  }
  ~puzzle() {}

  void print() {
    for (int r = 0; r < 3; r++) {
      cout << hr;
      for (int e = 0; e < 4; e++) {
        if (e == 2) {
          continue;
        }

        cout << "|";
        for (int p = 0; p < 3; p++) {
          // Print edges 0 and 3
          if (e == 0 || e == 3) {
            if (e == 0) {
              cout << pieces[r][p].num << "  ";
            } else {
              cout << "   ";
            }

            pieces[r][p].edges[e].print();
            cout << "   ";
            cout << "|";
          } else {
            // Print edges 1 and 2
            pieces[r][p].edges[e].print();
            cout << "    ";
            pieces[r][p].edges[e + 1].print();
            cout << "|";
          }
        }
        cout << endl;
      }
    }

    cout << hr;
  }
};