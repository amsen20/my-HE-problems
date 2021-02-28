#include<bits/stdc++.h>
#include "testlib.h"
using namespace std;

const int N = 3e5+100;

int a[N], p[N], f[N];

int main(int argc , char* argv[]){
	registerGen(argc, argv , 1);

	int n = atoi(argv[1]);
    int csz = atoi(argv[2]);
    int t = atoi(argv[3]);

    for(int st=0 ; st<n ; st += csz){
        a[st] = rnd.next(st, min(st+csz, n)-1);
        for(int i=st+1 ; i<st+csz && i<n ; i++)
            a[i] = rnd.wnext(st, i-1, t);
    }
    for(int i=0 ; i<n ; i++)
        p[i] = i;
    shuffle(p, p + n);

    for(int i=0 ; i<n ; i++)
        f[ p[i] ] = p[ a[i] ];
    
    cout << n << "\n";
    for(int i=0 ; i<n ; i++)
        cout << f[i] + 1 << " \n"[i == n-1];
}
