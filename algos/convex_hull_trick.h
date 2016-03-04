template<class T>
struct Line {
  T a, b;
  T get(T x) { return a*x + b; }
};

template<class T>
struct ConvexHullTrick {
  int size;
  vector<Line<T>> hull;

  ConvexHullTrick(int maxSize):
    size(0),
    hull(maxSize+1) { }

  bool is_bad(int curr, int prev, int next) {
    Line<T> c = hull[curr], p = hull[prev], n = hull[next];
    return (c.b-n.b) * (c.a-p.a) <= (p.b-c.b) * (n.a-c.a);
  }

  void add_line(T a, T b) {
    hull[size++] = {a, b};
    while (size > 2 && is_bad(size-2, size-3, size-1))
      hull[size-2] = hull[size-1], size--;
  }

  T query(T x) {
    int l = -1, r = size - 1;
    while (r-l > 1) {
      int m = (l+r) / 2;
      if (hull[m].get(x) <= hull[m+1].get(x))
        l = m;
      else
        r = m;
    }
    return hull[r].get(x);
  }
};
