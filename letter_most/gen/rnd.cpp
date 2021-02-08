#include<bits/stdc++.h>
#include "testlib.h"
using namespace std;

const int MAXN = 1e5+100;

int main(int argc , char* argv[]){
	registerGen(argc, argv , 1);
	int n = atoi(argv[1]);

    int f = rnd.next(16);
    cout << n << "\n";
    for(int i=0 ; i<n ; i++)
        cout << char('a' + f + rnd.next(11));
    cout << "\n";
}

