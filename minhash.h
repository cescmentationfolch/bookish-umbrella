#include<vector>
#include<functional>
#include<math.h>

using namespace std;

vector<vector<long long> > minhash(int n, int k, int h, vector<string>& V, 
    vector<function<long long(long long)> >& H);
