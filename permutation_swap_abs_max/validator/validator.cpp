#include<bits/stdc++.h>
#include "testlib.h"
using namespace std;

const int MAXN = 100000;

int main(int argc , char* argv[])
{
	registerValidation(argc, argv);

	int n = inf.readInt(1 , MAXN , "n");
	inf.readEoln();
    set<int> st;
	for(int i=0 ; i<n ; i++){
        int d = inf.readInt(1 , n , "p[i]");
        st.insert(d);
        if(i < n-1)
            inf.readSpace();
        else
            inf.readEoln();
    }
    ensuref(st.size() == n, "Array is not permutation!");
    inf.readEof();
}
