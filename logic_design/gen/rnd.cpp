#include<bits/stdc++.h>
#include "testlib.h"
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main(int argc , char* argv[]){
	registerGen(argc, argv , 1);
	int n = atoi(argv[1]);
    int v = atoi(argv[2]);
	int t = atoi(argv[3]);

	cout << n << " " << v << "\n";
	for(int i=0 ; i<n ; i++){
		ll x = rnd.next((1LL << v));
		for(int j=0 ; j<v ; j++)
			cout << char(rnd.next(2) + '0');
		cout << " " << char(rnd.wnext(2, t) + '0');
		cout << "\n";
	}
}

