#include<bits/stdc++.h>
#include "testlib.h"
using namespace std;

typedef pair<int, int> ii;

int main(int argc , char* argv[]){
	registerGen(argc, argv , 1);

	int count = atoi(argv[1]);
    int nn = atoi(argv[2]);
    int tt = atoi(argv[3]);

    cout << count << "\n";
    while(count --){
        int n = nn;
        int t = tt;
        int dv = 2;
        /*if(rnd.next(2))
            dv = 5;*/
        if(n%dv == 0)
            n --;
        n = dv*(n/dv)+1;
        int m = n/dv;
        vector<int> vec;
        for(int i=0 ; i<m ; i++)
            vec.push_back(rnd.wnext(i+1, t));
        cout << n << "\n";
        for(int it=0 ; it<dv ; it++){
            int toadd = 1 + it*m;
            for(auto i : vec)
                cout << (i ? toadd+i : 1) << "\n";
        }
    }
}
