#include<bits/stdc++.h>
#include "testlib.h"
using namespace std;

const int MAXN = 1e5+100;

int p[MAXN];

int main(int argc , char* argv[]){
	registerGen(argc, argv , 1);
	int n = atoi(argv[1]);

    for(int i=0 ; i<n ; i++)
        p[i] = i+1;

    shuffle(p, p+n);
    
    cout << n << "\n";
    for(int i=0 ; i<n ; i++)
        cout << p[i] << " \n"[i == n-1];
}

