#include <bits/stdc++.h>

#define FOR(i,a,b) for( LL i = (a); i < (LL)(b); i++ )
#define REP(i,n) FOR(i,0,n)
#define FORE(x,arr) for(auto& x:arr)
#define ALL(x) (x).begin(),(x).end()
#define SORT(x) sort(ALL((x)))
#define REVERSE(x) reverse(ALL((x)))
#define UNIQUE(x) (x).erase( unique( ALL( (x) ) ) , (x).end() )
#define PW(x) (1LL<<(x))
#define SZ(x) ((LL)(x).size())
#define SHOW(x) cout << #x << " = " << x << endl
#define SHOWA(x) for( int ___i = 0; ___i < SZ(x); ___i++ ){ cout << x[___i] << " "; } cout << endl
#define GET(x, i) get<i>(x)

#define PB emplace_back
#define MP make_pair
#define MT make_tuple

using namespace std;

typedef long double LD;
typedef long long int LL;
typedef pair<int,int> PI;
typedef pair<LL,LL> PL;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<LD> VD;
typedef vector<PI> VPI;
typedef vector<PL> VPL;
typedef vector<VPL> GR;
typedef vector<VL> ML;
typedef vector<VD> MD;
typedef vector<VI> MI;


template<class T> T& chmin(T &a , const T &b) { return a = min(a,b); }
template<class T> T& chmax(T &a , const T &b) { return a = max(a,b); }
template<class T> T sq(T a) { return a * a; }

void init_input() {
  //ios::sync_with_stdio(false);
  //cin.tie(nullptr);
  //cout.precision(10);
  //cout << fixed;
#ifdef LOCAL_DEFINE
  freopen("large_input", "rt", stdin);
#endif
}

void print_time() {
#ifdef LOCAL_DEFINE
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}

struct Query {
  int i;
  int l;
  int r;
};


void solve() {
  int n, t;
  cin >> n >> t;
  VL a(n);
  VL ans(t);
  vector<Query> q(t);
  REP(i, n) scanf("%lld", &a[i]);
  REP(i, t) scanf(" %d %d", &q[i].l, &q[i].r);
  REP(i, t) {
    q[i].i = i;
    q[i].l--;
  }
  LL k = static_cast<LL>(sqrt(n));
  [k](auto& lhs, auto& rhs) {
    if (lhs.l/k < rhs.l/k) return true;
    else if (lhs.l/k == rhs.l/k) return lhs.r < rhs.r;
    else return false;
  };
  sort(ALL(q), [k](auto& lhs, auto& rhs) {
      if (lhs.l/k < rhs.l/k) return true;
      else if (lhs.l/k == rhs.l/k) return lhs.r < rhs.r;
      else return false;
      });
  LL l = 0, r = 0;
  VL cnt(1e6, 0);
  LL sum = 0;
  auto add = [&](LL elem) {
    cnt[elem]++;
    sum += (sq(cnt[elem]) - sq(cnt[elem]-1))*elem;
  };
  auto del = [&](LL elem) {
    cnt[elem]--;
    sum -= (sq(cnt[elem] + 1) - sq(cnt[elem]))*elem;
  };
  FORE(qi, q) {
    while (r < qi.r) {
      add(a[r]);
      r++;
    }
    while (r > qi.r) {
      del(a[r-1]);
      r--;
    }
    while (l < qi.l) {
      del(a[l]);
      l++;
    }
    while (l > qi.l) {
      add(a[l-1]);
      l--;
    }
    ans[qi.i] = sum;
  }
  REP(i, t) printf("%lld\n", ans[i]);
}

int main() {
  init_input();
  solve();
  print_time();
  return 0;
}
