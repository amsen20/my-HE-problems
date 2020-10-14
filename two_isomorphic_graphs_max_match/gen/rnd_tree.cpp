#include<bits/stdc++.h>
#include "testlib.h"
using namespace std;

typedef pair<int, int> ii;

const int N = 1e5+100;

int p[N], par[N];

vector<ii> build_tree(int n, int t){
    for(int i=1 ; i<n ; i++)
        par[i] = rnd.wnext(i, t);
 
    vector<ii> eds;
    for(int i=1 ; i<n ; i++){
        int v = i, u = par[i];
        eds.push_back(ii(v, u));
    }

    return eds;
}

vector<ii> shuffle_vertices(int n, const vector<ii> &eds){
    vector<ii> ret;
    for(int i=0 ; i<n ; i++)
        p[i] = i;
    shuffle(p, p+n);
    for(auto e : eds)
        ret.push_back(ii(p[e.first], p[e.second]));
    shuffle(ret.begin(), ret.end());
    return ret;
}

int main(int argc , char* argv[]){
	registerGen(argc, argv , 1);

	int n = atoi(argv[1]);
    int t = atoi(argv[2]);

    auto tree = build_tree(n, t);
    auto t1 = shuffle_vertices(n, tree);
    auto t2 = shuffle_vertices(n, tree);

    cout << n << " " << n-1 << "\n";
    for(auto ed : t1)
        cout << ed.first + 1 << " " << ed.second + 1 << "\n";
    for(auto ed : t2)
        cout << ed.first + 1 << " " << ed.second + 1 << "\n";
}

