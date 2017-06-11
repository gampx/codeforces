import std.stdio;
import std.typecons;
import std.range;
import std.algorithm;
import std.array;
import std.conv;

struct Queue(T) {
  private T[] items = [T.init];
  private size_t first, last;

  @property bool empty() { 
    return first == last; 
  }

  void push(T top) { 
    if (last == items.length) {
      items.length = max(1, items.length*2);
    }
    items[last] = top;
    last++;
  }

  T pop() {
    if (this.empty)
      throw new Exception("Empty Queue.");
    auto top = items[first];
    first++;
    return top;
  }
}

void main() {
  int n;
  readf(" %d", &n);
  auto g = new int[][](n+1, 0);
  auto parent = new int[](n+1);
  auto visited = new int[](n+1);
  auto cycle = new int[](n+1);
  auto distances = new int[](n+1);
  int a,b;
  while (readf(" %d %d", &a, &b)) {
    g[a] ~= b;
    g[b] ~= a;
  }
  bool cycle_found = false;
  void dfs(int u, int p) {
    visited[u] = 1;
    parent[u] = p;
    if(cycle_found) return;
    foreach (v; g[u]) {
      if (v == p || visited[v] == 2 || cycle_found) continue;
      if (visited[v] == 1) {
        cycle[v] = 1;
        int x = u;
        while (x != v) {
          cycle[x] = 1;
          x = parent[x];
        }
        cycle_found = true;
        return;
      }
      dfs(v, u);
    }
    visited[u] = 2;
  }
  
  
  void bfs(int u0) {
    Queue!int q;
    q.push(u0);
    while (!q.empty) {
      auto u = q.pop();
      visited[u] = 1;
      foreach (v; g[u]) {
        debug {
          writeln("Start: ", v);
        }
        if (visited[v]) continue;
        debug {
          writeln("not visited");
        }
        if (!cycle[v]) {
          distances[v] = distances[u] + 1;
          debug {
            writeln(distances[v], ' ', distances[u]);
          }
        }
        q.push(v);
      }
    }
  }
  dfs(1, 0);
  visited[] = 0;
  bfs(to!int(cycle.countUntil(1)));
  debug {
    writeln(cycle);
  }
  writefln("%(%s %)", distances[1..$]);
}
