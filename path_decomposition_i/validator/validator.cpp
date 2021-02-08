#include<bits/stdc++.h>
#include "testlib.h"
using namespace std;

const int MAXN = 200000;

int par[MAXN];

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

	int n = inf.readInt(1 , MAXN , "n");
	inf.readEoln();
    for(int i=0 ; i<n ; i++)
        par[i];

    for(int i=0 ; i<n-1 ; i++){
        int v = inf.readInt(1, n);v --;
        inf.readSpace();
        int u = inf.readInt(1, n);u --;
        inf.readEoln();
        merge(v, u);
    }
    set<int> st;
    for(int i=0 ; i<n ; i++)
        st.insert(root(i));
    ensuref(st.size() == 1, "The tree must be connected.");
	inf.readEof();
}
