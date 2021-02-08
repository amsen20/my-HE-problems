#include<bits/stdc++.h>
#include "testlib.h"
using namespace std;

int main(int argc , char* argv[]){
	registerGen(argc, argv , 1);
    int n = atoi(argv[1]);
    int m = atoi(argv[2]);
    int t = atoi(argv[3]);
    cout << n << " " << m << "\n";
    for(int i=0 ; i<n ; i++)
        for(int j=0 ; j<m ; j++){
            int r = rnd.wnext(2, t);
            cout << (r ? '#' : '.');
            if(j == m-1)
                cout << "\n";
        }
}
