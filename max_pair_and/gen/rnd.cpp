#include<bits/stdc++.h>
#include "testlib.h"
using namespace std;

const int MAXM = 1e9;

int main(int argc , char* argv[]){
	registerGen(argc, argv , 1);

	int n = atoi(argv[1]);
	char tp = argv[2][0];

    cout << n << "\n";
    for(int i=0 ; i<n ; i++)
        cout << rnd.next(1, (tp == 'd' ? n : MAXM)) << " \n"[i == n-1];
}

