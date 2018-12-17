#include "LSH.h"

struct trie_node {
  map<long long, trie_node*> f;
  vector<int> index;
};

set<pair<int, int> > LSH(int n, int k, int h, int b, double threshold, vector<string>& V, 
    vector<function<long long(long long)> >& H) {
  vector<vector<long long> > D = minhash(n, k, h, V, H);
  set<pair<int, int> > R;
  int r = (k + b -1)/b;
  for (int band = 0; band < b; ++band) {
    trie_node *root = new trie_node;
    for (int i = 0; i < n; ++i) {
      trie_node *p = root;
      for (int j = r*band; j < min(r*(band+1), h); ++j) {
        if (!p->f.count(D[i][j])) {
          p->f[D[i][j]] = new trie_node;
        }
        p = p->f[D[i][j]];
      }
      p->index.push_back(i);
    }
    stack<trie_node*> S;
    S.push(root);
    while (!S.empty()) {
      trie_node* p = S.top();
      S.pop();
      for (auto f : p->f) S.push(f.second);
      for (int i = 0; i < (int)p->index.size(); ++i) {
        for (int j = i + 1; j < (int)p->index.size(); ++j) {
          double similarity_value = 0;
          for (int w = 0; w < h; ++w) {
            if (D[i][w] == D[j][w]) similarity_value += 1.0/h;
          }
          if (similarity_value >= threshold) R.insert({i,j});
        }
      }
      delete p;
    }
  }
  return R;
}
