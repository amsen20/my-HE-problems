#include<bits/stdc++.h>
#include "testlib.h"
using namespace std;

typedef pair<int, int> ii;

string str(int n){
    string ret;
    while(n){
        int d = n%10;
        ret.push_back(d + '0');
        n /= 10;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

int main(int argc , char* argv[]){
	registerValidation(argc, argv);
    int n = inf.readInt(1, 1000);
    inf.readEoln();
    string s = inf.readToken("[a-z\.#0-9]{" + str(n) + "}");
    inf.readEoln();
	inf.readEof();
}
