#include<bits/stdc++.h>
#include "testlib.h"
using namespace std;

const int N = 100000;

int main(int argc , char* argv[])
{
	registerValidation(argc, argv);
    int t = inf.readInt(1, 10);
    inf.readEoln();
    while(t--){
        int n = inf.readInt(1, N);
        inf.readEoln();
        for(int i=1 ; i<n ; i++){
            inf.readInt(1, i);
            inf.readEoln();
        }
    }
	inf.readEof();
}
