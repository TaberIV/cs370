#include <iostream>
#include <sstream>

using namespace std;

typedef struct edge {
  char color;
  int type;

  void print() { cout << color << type; }
} edge;

class piece {
public:
  int num;
  edge edges[4];

  // Default constructor
  piece() {
    num = 0;
    for (int i = 0; i < 4; i++) {
      edges[i] = {0, 0};
    }
  }
  // Edges string constructor
  piece(int _num, string edges_str) {
    num = _num;
    // Read edges
    string edge;
    istringstream piece(edges_str);
    unsigned int edge_number = 0;
    while (getline(piece, edge, ',')) {
      edges[edge_number] = {edge[0], edge[1] - '0'};
      edge_number++;
    }
  }
  // Edges array constructor
  piece(int _num, edge _edges[]) {
    num = _num;
    for (int i = 0; i < 4; i++) {
      edges[i] = _edges[i];
    }
  }
  // Destructor
  ~piece() {}

  // Print as line
  void print() {
    cout << "<";
    for (int i = 0; i < 4; i++) {
      edges[i].print();

      if (i < 3) {
        cout << ", ";
      }
    }
    cout << ">" << endl;
  }
};