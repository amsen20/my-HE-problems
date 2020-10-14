#include<bits/stdc++.h>
#include "testlib.h"
using namespace std;

const int MAXN = 100000;

int main(int argc , char* argv[])
{
	registerValidation(argc, argv);

	int n = inf.readInt(1 , MAXN , "n");
	inf.readEoln();
    string s = inf.readWord();
    ensuref(s.size() == n, "string len should be equal to n");
    for(auto c : s)
        ensuref(c >= 'a' && c <= 'z', "characters should be a-z");
    inf.readEoln();
    inf.readEof();
}
