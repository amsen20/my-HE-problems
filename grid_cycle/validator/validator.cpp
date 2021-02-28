#include<bits/stdc++.h>
#include "testlib.h"
using namespace std;

const int N = 100;

int main(int argc , char* argv[]){
	registerValidation(argc, argv);
	int n = inf.readInt(1, N);
	inf.readSpace();
	int m = inf.readInt(1, N);
	inf.readEoln();
	for(int i=0 ; i<n ; i++){
		for(int j=0 ; j<m ; j++){
			char c = inf.readChar();
			ensuref(c == '.' || c == '#', "grid must be '#' & '.'");
		}
		inf.readEoln();
	}
	inf.readEof();
}
