#include<bits/stdc++.h>
#include "testlib.h"
using namespace std;

int main(int argc , char* argv[]){
	registerGen(argc, argv , 1);

	int n = atoi(argv[1]);
	char tp = argv[2][0];
    char st = argv[3][0];

    const int MAXM = (st == 's' ? n : int(1e9));

    cout << n << "\n";

    int cmn = rnd.next(1, min(MAXM, 1000));

    int all = rnd.next(1, MAXM/cmn);
    auto get = [&](char tp){
        if(tp == 'a')
            return all;
        return rnd.next(1, MAXM/cmn);
    };

    int ind = rnd.next(1, n);
    for(int i=0 ; i<n ; i++){
        if(i == ind)
            cout << (tp == 'a' ? cmn : 1) * rnd.next(1, MAXM/cmn);
        else
            cout << get(tp)*cmn;
        if(i < n-1)
            cout << " ";
        else
            cout << "\n";
    }
    return 0;

}

