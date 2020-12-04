#include<bits/stdc++.h>
#include "testlib.h"
using namespace std;

const int N = 1e5+100;

int p[N];

int main(int argc , char* argv[]){
	registerGen(argc, argv , 1);
	int n = atoi(argv[1]);
    int cnt = atoi(argv[2]);
    int step = n/cnt;
    for(int i=0 ; i<n ; i++)
        p[i] = i+1;
    shuffle(p, p+n);
    int f = 1;
    for(int i=0 ; i<n ; i+=step, f = 1-f){
        if(f)
            sort(p+i, p+i+step);
        else
            sort(p+i, p+i+step, greater<int>());
    }

    cout << n << "\n";
    for(int i=0 ; i<n ; i++)
        cout << p[i] << " \n"[i == n-1];
    return 0;
}
