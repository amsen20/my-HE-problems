#include<bits/stdc++.h>
#include "testlib.h"
using namespace std;

const int small = 100, medium = 10000, large = 100000000;
const int MAXL = 1000;

int main(int argc , char* argv[])
{
	registerGen(argc, argv , 1);

	int n = atoi(argv[1]);
    int m = atoi(argv[2]);
    int sz = atoi(argv[3]);
    char ls = argv[4][0];
    string sls;sls.push_back(ls);
    
    string pat = "[";pat += "a";pat += "-";pat += sls;pat += "]{50}";
    vector<string> vec;
    for(int i=0 ; i<50 ; i++){
        string cur = rnd.next(pat);
        int len = rnd.wnext(m/4, m/2, -2);
        cur.resize(len);
        vec.push_back(cur);
    }
    
    vector<string> strs;
    for(int i=0 ; i<n ; i++){
        string cur;
        while(cur.size() < m)
            cur += vec[ rnd.next(vec.size()) ];
        cur.resize(m);
        strs.push_back(cur);
    }
    
    unordered_set<string> S;
    for(auto s : vec){
        int t=4;
        while(t --){
            int l = rnd.next(s.size()), r = rnd.next(s.size());
            if(l>r)
                swap(l, r);
            S.insert(s.substr(l, r-l+1));
        }
    }
    while(S.size() > sz)
        S.erase(S.begin());

    cout << n << " " << m << "\n";
    for(auto s : strs){
        int cnt=0;
        for(int i=0 ; i<s.size() ; i++){
            string t = "";
            for(int j=i ; j<s.size() ; j++){
                t.push_back(s[j]);
                if(S.count(t))
                    cnt ++;
            }
        }
        cout << s << " " << cnt << "\n";
    }
}
