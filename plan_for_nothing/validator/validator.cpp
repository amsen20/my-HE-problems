#include<bits/stdc++.h>
#include "testlib.h"
using namespace std;

const int MAXN = 2e5, MAXM = 1e6;

int main(int argc , char* argv[]){
	registerValidation(argc, argv);

	int n = inf.readInt(2 , MAXN , "n");
    inf.readEoln();
    int sum=0;
    
    for(int i=0 ; i<n ; i++){
        int m = inf.readInt(0, MAXN, "mi");
        sum += m;
        ensuref(sum <= MAXN, "sum should be less than or equal 2e5");
        if(m == 0){
            inf.readEoln();
            continue;
        }
        inf.readSpace();
        int ls=0;
        for(int i=0 ; i<m ; i++){
            int l = inf.readInt(ls, MAXM, "li");
            inf.readSpace();
            ls = l;
            int r = inf.readInt(ls, MAXM, "ri");
            ls = r;
            if(i == m-1)
                inf.readEoln();
            else
                inf.readSpace();
        }
    }

    inf.readEof();
}
