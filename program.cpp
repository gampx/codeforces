#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
template<class T> using V = vector<T>;
template<class T> using VV = V<V<T>>;
using VI = V<int>;
using VVI = VV<int>;
using VL = V<ll>;
using VVL = VV<ll>;
template <typename T, size_t N>
struct MakeVector { template <typename... Args, typename R = vector<decltype(MakeVector<T, N-1>::make_vector(declval<Args>()...))>> static R make_vector(std::size_t first, Args... sizes) { auto inner = MakeVector<T, N - 1>::make_vector(sizes...); return R(first, inner);}};
template <typename T> struct MakeVector<T, 1> { template <typename R = std::vector<T>> static R make_vector(std::size_t size, const T& value) { return R(size, value); }};
template <typename T, typename... Args>
auto make_vector(Args... args) -> decltype(MakeVector<T, sizeof...(Args) - 1>::make_vector(args...)) {
  return MakeVector<T, sizeof...(Args) - 1>::make_vector(args...);
}

void solve(VI& even, VI& odd) {
  sort(even.begin(), even.end());
  sort(odd.begin(), odd.end());
  VI a(even.size() + odd.size());
  for (int i = 0; i < (int)a.size(); i++) a[i] = (i % 2) == 0 ? even[i/2] : odd[i/2];
  for (int i = 0; i < (int)a.size() - 1; i++)
    if (a[i] > a[i+1]) {
      cout << i << endl;
      return;
    }
  cout << "OK" << endl;
}

int main() {
  int T;
  cin >> T;
  for (int t = 0; t < T; t++) {
    int n;
    cin >> n;
    VI even((n+1)/2), odd(n/2);
    for (int i = 0; i < n; i++) {
      cin >> ((i % 2) == 0 ? even[i/2] : odd[i/2]);
    }
    cout << "Case #" << t+1 << ": ";
    solve(even, odd);
  }
  return 0;
}

