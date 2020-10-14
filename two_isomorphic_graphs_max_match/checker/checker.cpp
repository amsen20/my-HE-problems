#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define int ll

const int MAXOUT = 1e18;

int gcd(int a, int b){
    if(a > b)
        swap(a, b);
    if(a == 0)
        return b;
    return gcd(b%a, a);
}

signed main(signed argc, char * argv[])
{
	//registerChecker("fs", argc, argv);
    int a, b, l;cin >> a >> b >> l;
    vector<int> up, dn;
    up.push_back(b);
    dn.push_back(a);
    for(int i=0 ; i<l ; i++){
        int f;cin >> f;
        int s;cin >> s;
        assert(f < s);
        assert(f <= MAXOUT);
        assert(s <= MAXOUT);
        assert(f > 0);
        assert(s > 0);
        up.push_back(f);
        dn.push_back(s);
    }
    for(auto &i : up)
        for(auto &j : dn){
            int g = gcd(i, j);
            i /= g;
            j /= g;
        }
    for(auto i : up)
        assert(i == 1);
    for(auto i : dn)
        assert(i == 1);
    cout << 5 << "\n";
}
