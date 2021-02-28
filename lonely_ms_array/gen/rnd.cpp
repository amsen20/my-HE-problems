#include<bits/stdc++.h>
#include "testlib.h"
using namespace std;

const int N = 3e5+100;

int a[N];

int main(int argc , char* argv[]){
	registerGen(argc, argv , 1);

	int n = atoi(argv[1]);
	int m = atoi(argv[2]);
    int block = atoi(argv[3]);

    cout << n << "\n";
    for(int i=0 ; i<n ; i++)
        a[i] = rnd.next(1, m);
    for(int i=0 ; i<n ; i++){
        if(i % block != 0)
            continue;
        bool d = (i/block)&1;
        if(d)
            sort(a+i, a+min(i+block, n), greater<int>());
        else
            sort(a+i, a+min(i+block, n));
    }
    for(int i=0 ; i<n ; i++)
        cout << a[i] << " \n"[i == n-1];
    return 0;

}

