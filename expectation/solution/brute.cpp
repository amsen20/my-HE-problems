#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MOD = 1e9+7;

int add(ll a, int b){
    return (a + b) % MOD;
}

int mul(ll a, int b){
    return a * b % MOD;
}

void sadd(int &a, int b){
    a = add(a, b);
}

void smul(int &a, int b){
    a = mul(a, b);
}

int bp(int a, int b){
    if(b == 0)
        return 1;
    int x = bp(a, b/2);
    smul(x, x);
    return b&1 ? mul(x, a) : x;
}

int inv(int x){
    return bp(x, MOD-2);
}

int dpc[2][4], dps[2][4];

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n;cin >> n;
    for(int i=0 ; i<4 ; i++)
        dpc[0][i] = 1;
    int all = 4;
    for(int i=1 ; i<n ; i++){
        smul(all, 4);
        int d = i&1;
        memset(dpc[d], 0, sizeof dpc[d]);
        memset(dps[d], 0, sizeof dps[d]);
        for(int ls=0 ; ls<4 ; ls++)
            for(int nxt=0 ; nxt<4 ; nxt++){
                sadd(dpc[d][nxt], dpc[1-d][ls]);
                bool con0 = (ls&1) == (nxt&1);
                bool con1 = (ls&2) == (nxt&2);
                bool eq0 = bool(ls&1) == bool(ls&2);
                bool eq1 = bool(nxt&1) == bool(nxt&2);
                int cur = 0;
                if(eq0)
                    cur = (!con0 && !con1);
                else
                    cur = int(!con0) + !con1;
                sadd(dps[d][nxt], dps[1-d][ls]);
                sadd(dps[d][nxt], mul(cur, dpc[1-d][ls]));
            }
    }
    int d = 1 - (n&1);
    int out=0;
    for(int i=0 ; i<4 ; i++)
        sadd(out, add(dps[d][i], mul(dpc[d][i], 1 + (bool(i&1) != bool(i&2)))));
    //cerr << out << "\n";
    cout << mul(out, inv(all)) << "\n";
}

