#include<bits/stdc++.h>
#include "testlib.h"
using namespace std;

int main(int argc , char* argv[]){
	registerGen(argc, argv , 1);
	int n = atoi(argv[1]);
    char tp = argv[2][0];
    int i = rnd.next(1, n);
    if(tp == 's')
        i = n - rnd.next(0, min(n-1, 4));
    cout << n << " " << i << "\n";
}

