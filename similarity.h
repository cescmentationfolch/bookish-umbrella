#include<vector>
#include<functional>
#include "minhash.h"

using namespace std;


vector<vector<double> > similarity(int n, int k, int h, vector<string>& V, 
    vector<function<long long(long long)> >& H);
