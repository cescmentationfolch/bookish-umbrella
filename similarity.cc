#include "similarity.h"

vector<vector<double> > similarity(int n, int k, int h, vector<string>& V, 
    vector<function<long long(long long)> >& H) {
  vector<vector<long long> > D = minhash(n, k, h, V, H);
  vector<vector<double> > R(n, vector<double>(n, 0));
  for (int i = 0; i < n; ++i) 
    for (int j = 0; j < n; ++j) 
      for (int w = 0; w < h; ++w) 
        if (D[i][w] == D[j][w]) R[i][j] += 1.0/h;
  return R;
}
