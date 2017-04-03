template<typename E>
class AdjacencyListGraphBase {
  public:
    using Edge = E;
    using Vertex = size_t;
    using Collection = std::vector<std::vector<Edge>>;
    using Iterator = typename Collection::iterator;

    AdjacencyListGraphBase(size_t n): g(n) {
    }

    Iterator begin() {
      return g.begin();
    }

    Iterator end() {
      return g.end();
    }

    const std::vector<E>& outgoing_edges(Vertex vertex) {
      return g[vertex];
    }

  protected:
    Collection g;
};
