#include <iostream>
#include <sstream>

using namespace std;

typedef struct edge {
  char color;
  int type;

  void print() {
    cout << color << type;
  }
} edge;

typedef struct piece {
  edge edges[4];

  piece(string edges_str) {
    // Read edges
    string edge;
    istringstream piece(edges_str);
    unsigned int edge_number = 0;
    while (getline(piece, edge, ',')) {
      edges[edge_number] = {edge[0], edge[1] - '0'};
      edge_number++;
    }
  }
  ~piece() {}

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
} piece;