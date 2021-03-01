#include<bits/stdc++.h>
#include "testlib.h"
using namespace std;

typedef pair<int, int> ii;

const int MAXN = 100, MAXV = 50;

string to_str(int x){
    string ret;
    while(x){
        char d = x%10 + '0';
        x /= 10;
        ret.push_back(d);
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

int main(int argc , char* argv[]){
	registerValidation(argc, argv);
	int n = inf.readInt(1 , MAXN , "n");
	inf.readSpace();
	int v = inf.readInt(1 , MAXV , "v");
    inf.readEoln();
    set<string> st;
    for(int i=0 ; i<n ; i++){
        string key = inf.readToken("[0-1]{" + to_str(v) + "}");
        ensuref(!st.count(key), "Two values for a single key.");
        inf.readSpace();
        int d = inf.readInt(0, 1);
        inf.readEoln();
    }
	inf.readEof();
}
