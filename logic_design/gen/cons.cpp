#include<bits/stdc++.h>
#include "testlib.h"
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int N = 50;

vector<int> p;

string to_bin(int len, ll x){
	string ret;
	for(int i=len-1 ; i>=0 ; i--)
		if((1LL << i)&x)
			ret += "1";
		else
			ret += "0";
    string tmp = ret;
    for(int i=0 ; i<len ; i++)
        tmp[i] = ret[ p[i] ];
    ret = tmp;
	return ret;
}

int main(int argc , char* argv[]){
	registerGen(argc, argv , 1);
	int n = atoi(argv[1]);
    int v = atoi(argv[2]);
    int t = atoi(argv[3]);

    for(int i=0 ; i<v ; i++)
        p.push_back(i);
    shuffle(p.begin(), p.end());

	cout << n << " " << v << "\n";
    ll st = rnd.next((1LL << v) - n);
    for(int i=0 ; i<n ; i++)
        cout << to_bin(v, st+i) << " " << char('0' + rnd.wnext(2, t)) << "\n";
}
