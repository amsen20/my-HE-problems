#include<bits/stdc++.h>
#include "testlib.h"
using namespace std;

const int MAXN = 200*1000, MAXM = 200*1000;

int par[MAXN];

int root(int v){
    return par[v] = (par[v] == v ? v : root(par[v]));
}

void merge(int v, int u){
    v = root(v);
    u = root(u);
    par[v] = u;
}

int main(int argc , char* argv[]){
	registerValidation(argc, argv);
	int n = inf.readInt(1 , MAXN , "n");
    inf.readEoln();
    { // first graph
        for(int i=0 ; i<n ; i++)
            par[i] = i;
        for(int i=0 ; i<n-1 ; i++){
            int v = inf.readInt(1, n, "vi");
            v --;
            inf.readSpace();
            int u = inf.readInt(1, n, "ui");
            u --;
            inf.readSpace();
            int w = inf.readInt(0, int(1e9), "wi");
            inf.readEoln();
            merge(v, u);
        }
        set<int> st;
        for(int i=0 ; i<n ; i++)
            st.insert(root(i));
        ensuref(st.size() == 1, "tree should be connected");
    } 
	inf.readEof();
}
