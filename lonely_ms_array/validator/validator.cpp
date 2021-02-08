#include<bits/stdc++.h>
#include "testlib.h"
using namespace std;

const int MAXN = 3e5, MAXM = 3e5;

int main(int argc , char* argv[]){
	registerValidation(argc, argv);

	int n = inf.readInt(1 , MAXN , "n");
    inf.readEoln();
    
    for(int i=0 ; i<n ; i++){
	    int d = inf.readInt(1 , MAXM , "a[i]");
        if(i < n-1)
            inf.readSpace();
        else
            inf.readEoln();
    }
	
    inf.readEof();
}
