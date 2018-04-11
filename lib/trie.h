
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
