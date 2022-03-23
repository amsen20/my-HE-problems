#include<bits/stdc++.h>
#include "testlib.h"
using namespace std;

const int MAXN = 1e5+100;

int p[MAXN];

int main(int argc , char* argv[]){
	registerGen(argc, argv , 1);
	int n = atoi(argv[1]);
    char c = argv[1][0];
    cout << (c == 'e' ? n : rnd.next(n)) << "\n";
}

