#include "minhash.h"

vector<vector<long long> > minhash(int n, int k, int h, vector<string>& V, 
    vector<function<long long(long long)> >& H) {
  long long INF = 1e18;
  vector<vector<long long> > R(n, vector<long long>(h, INF));
  long long base = 37;
  long long pot = pow(base, k);
  for (int i = 0; i < n; ++i) {
    long long valor = 0;
    for (int w = 0; w < (int)V[i].size(); ++w) {
      valor /= base;
      if ('a' <= V[i][w] && V[i][w] <= 'z') valor += pot*(V[i][w] - 'a' + 1);
      else if (V[i][w] != ' ') valor += pot*(V[i][w] - '0' + 27);
      if (w < k -1) continue;
      for (int j = 0; j < h; ++j) {
        R[i][j] = min(R[i][j], H[j](valor));
      }
    }
  }
  return R;
}
