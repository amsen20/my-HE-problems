#include<bits/stdc++.h>
using namespace std;

#define M_PI 3.14159265358979323846264338327950288

typedef long long ll;

const int N = 1000, M=200;

string s[N];
int a[N];
ll b[N];

int main()
{
    int n, m;cin >> n >> m;
    for(int i=0 ; i<n ; i++)
        cin >> s[i] >> a[i];
    int sz;cin >> sz;
    assert(sz <= M);
    unordered_set<string> S;
    for(int i=0 ; i<sz ; i++){
        string s;cin >> s;
        assert(s.size() <= m);
        assert(S.count(s) == 0);
        S.insert(s);
    }
    for(int it=0 ; it<n ; it++){
        for(int i=0 ; i<s[it].size() ; i++){
            string t="";
            for(int j=i ; j<s[it].size() ; j++){
                t.push_back(s[it][j]);
                b[it] += S.count(t);
            }
        }
    }
    long double sc=0;
    for(int i=0 ; i<n ; i++){
        long double cur = (a[i] - b[i]);
        cur *= cur;
        sc += cur;
    }
    sc = 5*(1-2*atan(sqrt(sc))/M_PI);
    cout << sc;// << "\n";
    return 0;
}
