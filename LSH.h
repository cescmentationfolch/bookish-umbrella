#include<vector>
#include<set>
#include<stack>
#include<map>
#include<functional>
#include "minhash.h"

using namespace std;

set<pair<int, int> > LSH(int n, int k, int h, int b, double threshold, vector<string>& V, 
    vector<function<long long(long long)> >& H);
