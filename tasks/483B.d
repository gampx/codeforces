import std.stdio;
import std.typecons;
import std.range;
import std.algorithm;
import std.array;
import std.conv;

void main() {
  int cnt1, cnt2, p1, p2;
  readf(" %d %d %d %d", &cnt1, &cnt2, &p1, &p2);
  long ans = binSearch!(delegate(x) {
      debug { writeln(x);}
      if (cnt1 > x - x/p1) return false;
      if (cnt2 > x - x/p2) return false;
      if (cnt1 > x/p2 - x/(p1*p2)) {
        return cnt2 <= x - cnt1 - x/(p1*p2);
      } else {
        return cnt2 <= x - x/p2;
      }
      })(1L, 2*10^^9L);
  writeln(ans);
}

T binSearch(alias pred, T)(T l, T r) {
  while (r-l > 1) {
    T mid = (l+r)/2;
    if (!pred(mid)) l = mid;
    else r = mid;
  }
  return r;
}
