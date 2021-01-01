#include<bits/stdc++.h>
#include "testlib.h"
using namespace std;

typedef long long ll;

int main(int argc , char* argv[]){
	registerGen(argc, argv , 1);
	int n = atoi(argv[1]);
    char c = argv[2][0];
    ll mn = 1 + (n-1)*2, mx = 1LL*n*(n+1)/2+1;
    if(c == 'y')
        cout << n << " " << rnd.next(mn, mx) << "\n";
    else
        cout << n << " " << (rnd.wnext(2, -1) ? rnd.next(0LL, mn) : rnd.next(mx, 1LL*n*n)) << "\n";
}
