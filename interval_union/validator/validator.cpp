#include<bits/stdc++.h>
#include "testlib.h"
using namespace std;

typedef pair<int, int> ii;
typedef long long ll;

const int MAXN = 3e5, MAXM = 1e9;

int main(int argc , char* argv[]){
	registerValidation(argc, argv);

	int n = inf.readInt(1 , MAXN , "n");
    inf.readEoln();
    vector<ii> vec;
    set<int> sts, ens;
    for(int i=0 ; i<n ; i++){
	    int l = inf.readInt(1, MAXM, "l[i]");l --;
        ensuref(!sts.count(l), "starts must be unique!");
        sts.insert(l);
        inf.readSpace();
        int r = inf.readInt(1, MAXM, "r[i]");
        ensuref(!ens.count(r), "ends must be unique!");
        ens.insert(r);
        ensuref(l < r, "l < r");
        inf.readEoln();
        vec.push_back(ii(l, r));
    }
    sort(vec.begin(), vec.end());
    int mx = -1;
    for(auto i : vec){
        ensuref(i.second > mx, "no common!");
        mx = i.second;
    }
    inf.readEof();
}
