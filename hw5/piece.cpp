typedef struct Edge {
  char color;
  int type;
} Edge;

typedef struct Piece {
  Edge edges[4];
} Piece;