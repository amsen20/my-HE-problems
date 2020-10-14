#include<bits/stdc++.h>
#include "testlib.h"
using namespace std;

int main(int argc , char* argv[]){
	registerGen(argc, argv , 1);

	int n = atoi(argv[1]);
    char tp = argv[2][0];

    const int MAXM = (tp == 'l' ? n : int(1e9));

    cout << n << "\n";
    for(int i=0 ; i<n ; i++)
        cout << rnd.next(1, MAXM) << " \n"[i == n-1];
    return 0;
}

