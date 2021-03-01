#include<bits/stdc++.h>
#include "testlib.h"
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int N = 50;

string to_bin(int len, ll x){
	string ret;
	for(int i=len-1 ; i>=0 ; i--)
		if((1LL << i)&x)
			ret += "1";
		else
			ret += "0";
	return ret;
}

int main(int argc , char* argv[]){
	registerGen(argc, argv , 1);
	int n = atoi(argv[1]);
    int v = atoi(argv[2]);
    assert(v<=10);
    int t = atoi(argv[3]);
    vector<int> vec;
    for(int i=0 ; i<(1 << v) ; i++)
        vec.push_back(i);
    shuffle(vec.begin(), vec.end());
    vec.resize(n);

	cout << n << " " << v << "\n";
    for(int i=0 ; i<n ; i++)
        cout << to_bin(v, vec[i]) << " " << char('0' + rnd.wnext(2, t)) << "\n";
}
