#include "algos/adjacency_list_graph.h"

class SimpleGraph: public AdjacencyListGraphBase<size_t> {
  public:
    explicit SimpleGraph(size_t n): AdjacencyListGraphBase(n) {}

    void add_edge(Vertex from, Vertex to) {
      g[from].push_back[to];
    }
};
