#include <iostream>
#include <sstream>

using namespace std;

typedef struct edge {
  char color;
  int type;

  friend ostream &operator<<(ostream &output, const edge &e) { 
    output << e.color << e.type;
    return output;            
  }
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

  piece rotateL() {
    edge edges_rot[4];
    edge temp = edges[0];

    for (int i = 0; i < 3; i++) {
      edges_rot[i] = edges[i + 1];
    }
    edges_rot[3] = temp;

    return piece(num, edges_rot);
  }

  piece rotateR() {
    edge edges_rot[4];
    edge temp = edges[3];

    for (int i = 1; i < 3; i++) {
      edges_rot[i] = edges[i - 1];
    }
    edges_rot[0] = temp;

    return piece(num, edges_rot);
  }

  friend ostream &operator<<(ostream &output, const piece &p) { 
    output << p.num << ". <" << p.edges[0];
    for (int i = 1; i < 4; i++) {
      output << ", " << p.edges[i];
    }
    output << ">" << "\n";
    return output;            
  }
};