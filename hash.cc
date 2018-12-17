#include "hash.h"

vector<function<long long(long long)> > linear_hash(int n, int mod) {
  vector<function<long long(long long)> > R(n);
  for (int i = 0; i < n; ++i) {
    long long a = rand()%mod;
    long long b = rand()%mod;
    R[i] = [a,b,mod](long long x) -> long long { return (a*x + b)%mod; }; 
  }
  return R;
}

vector<function<long long(long long)> > quadratic_hash(int n, int mod) {
  vector<function<long long(long long)> > R(n);
  for (int i = 0; i < n; ++i) {
    long long a = rand()%mod;
    long long b = rand()%mod;
    long long c = rand()%mod;
    R[i] = [a,b,c,mod](long long x) -> long long { return (a*((x*x)%mod) + b*x + c)%mod; }; 
  }
  return R;
}

vector<function<long long(long long)> > bit_permutation_hash(int n) {
  vector<function<long long(long long)> > R(n);
  vector<int> b(64);
  iota(b.begin(), b.end(), 0);
  for (int i = 0; i < n; ++i) {
    random_shuffle(b.begin(), b.end());
    R[i] = [b](long long x) -> long long { 
      long long res = 0;
      for (int i = 0; i < 64; ++i) {
        res += ((x>>i)&1)<<b[i];
      }
      return res;
    }; 
  }
  return R;
}
