#include<bits/stdc++.h>
#include "testlib.h"
using namespace std;

typedef pair<int, int> ii;

const int N = 2e5+100;

int par[N], p[N];

int main(int argc , char* argv[]){
	registerGen(argc, argv , 1);

	int n = atoi(argv[1]);
    int t = atoi(argv[2]);

    for(int i=1 ; i<n ; i++)
        par[i] = rnd.wnext(i, t);

    for(int i=0 ; i<n ; i++)
        p[i] = i;
    shuffle(p, p + n);

    vector<ii> v;
    for(int i=1 ; i<n ; i++)
        v.push_back(ii(p[i], p[ par[i] ]));
    shuffle(v.begin(), v.end());

    cout << n << "\n";
    for(auto i : v)
        cout << i.first+1 << " " << i.second+1 << "\n";
}
