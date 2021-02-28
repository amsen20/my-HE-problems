#include<bits/stdc++.h>
#include "testlib.h"
using namespace std;

const int N = 2e5, M = 3e5, W = 1e9;

typedef pair<int, int> ii;

int par[N];

int root(int v){
    return par[v] = (v == par[v] ? par[v] : root(par[v]));
}

int merge(int v, int u){
    v = root(v);
    u = root(u);
    par[v] = u;
}

int main(int argc , char* argv[])
{
	registerValidation(argc, argv);

	int n = inf.readInt(1 , N , "n");
    inf.readSpace();
    int m = inf.readInt(1, M, "m");
	inf.readEoln();
    for(int i=0 ; i<n ; i++)
        par[i];

    set<ii> stt;
    for(int i=0 ; i<m ; i++){
        int v = inf.readInt(1, n);v --;
        inf.readSpace();
        int u = inf.readInt(1, n);u --;
        inf.readSpace();
        inf.readInt(1, W);
        inf.readEoln();
        ii cur = (v<u ? ii(v, u) : ii(u, v));
        ensuref(!stt.count(cur), "Multiple edges are not allowed.");
        stt.insert(cur);
        merge(v, u);
    }
    set<int> st;
    for(int i=0 ; i<n ; i++)
        st.insert(root(i));
    ensuref(st.size() == 1, "The graph must be connected.");
	inf.readEof();
}
