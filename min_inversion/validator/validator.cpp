#include<bits/stdc++.h>
#include "testlib.h"
using namespace std;

const int MAXN = 1e5;

int main(int argc , char* argv[]){
	registerValidation(argc, argv);

	int n = inf.readInt(2 , MAXN , "n");
    inf.readEoln();
    
    set<int> st;
    for(int i=0 ; i<n ; i++){
	    int d = inf.readInt(1 , n , "a[i]");
        ensuref(!st.count(d), "all must be unique.");
        st.insert(d);
        if(i < n-1)
            inf.readSpace();
        else
            inf.readEoln();
    }
	
    inf.readEof();
}
