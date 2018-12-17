#include<vector>
#include<functional>
#include<numeric>
#include<algorithm>
#include<cstdlib>

using namespace std;

vector<function<long long(long long)> > linear_hash(int n, int mod);

vector<function<long long(long long)> > quadratic_hash(int n, int mod);

vector<function<long long(long long)> > bit_permutation_hash(int n);
