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


constexpr size_t kAlphabetSize = 26;
struct StringTrieNode {
  StringTrieNode* parent;
  StringTrieNode* children[kAlphabetSize];
  bool is_terminal;

  StringTrieNode(): parent(nullptr), is_terminal(true) {
    std::fill(children, children + kAlphabetSize, nullptr);
  }

  ~StringTrieNode() {
    for(int i = 0; i < kAlphabetSize; i++) if(children[i]) delete children[i];
  }
};

struct StringTrie {
  StringTrieNode* root;

  StringTrie(): root(new StringTrieNode) {}
  ~StringTrie() { delete root; }

  StringTrieNode* add(const std::string& s) {
    size_t index = 0;
    auto current_node = root;
    while (index < s.size()) {
      if (current_node->children[s[index]-'a'] == nullptr) break;
      current_node = current_node->children[s[index]-'a'];
      index++;
    }
    while (index < s.size()) {
      auto new_node = new StringTrieNode;
      new_node->parent = current_node;
      current_node->children[s[index]-'a'] = new_node;
      current_node->is_terminal = false;
      current_node = new_node;
      index++;
    }
    return current_node;
  }

  StringTrieNode* find(const std::string& s) {
    auto current_node = root;
    int index = 0;
    while (index < s.size()) {
      current_node = current_node->children[s[index]-'a'];
      if (current_node == nullptr) return nullptr;
      index++;
    }
    return current_node;
  }

  void remove(const std::string& s) {
    auto node = find(s);
    int index = s.size() - 1;
    if (node == nullptr) return;
    while (node != nullptr && index >= 0) {
      auto parent = node->parent;
      parent->children[s[index]-'a'] = nullptr;
      if (std::any_of(parent->children,
            parent->children + kAlphabetSize,
            [](StringTrieNode* n) { return n != nullptr; })) {
        return;
      }
      delete node;
      node = parent;
      index--;
    }
    assert(node == nullptr && index == 0);
  }
};

int dfs(StringTrieNode* v, int want_win) {
  if (v->is_terminal) return !want_win;
  for (int i = 0; i < kAlphabetSize; i++) {
    if (v->children[i])
      if (0 == dfs(v->children[i], want_win))
        return 1;
  }
  return 0;
}

int main() {
  int n, k;
  cin >> n >> k;
  StringTrie trie;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    trie.add(s);
  }
  int first_may_force_win = dfs(trie.root, 1);
  int first_may_force_lose = dfs(trie.root, 0);
  if (first_may_force_win && first_may_force_lose) cout << "First";
  if (!first_may_force_win) cout << "Second";
  if (first_may_force_win && !first_may_force_lose) cout << (k & 1 ? "First" : "Second");
  return 0;
}

