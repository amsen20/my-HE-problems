#include<bits/stdc++.h>
#include "testlib.h"
using namespace std;

const int MAXN = 64;

string int_to_string(int x){
	string ret;
	while(x){
		ret.push_back('0' + x%10);
		x /= 10;
	}
	reverse(ret.begin(), ret.end());

	return ret;
}

int main(int argc , char* argv[])
{
	registerValidation(argc, argv);
	int n = inf.readInt();
	inf.readSpace();
	int m = inf.readInt();
	inf.readEoln();
	string pat = "[a-z]{";
	pat += int_to_string(m);
	pat += "}";
	cerr << pat << "\n";
	for(int i=0 ; i<n ; i++){
		inf.readToken(pat);
		inf.readSpace();
		inf.readInt(0, 500);
		inf.readEoln();
	}
	inf.readEof();
}
