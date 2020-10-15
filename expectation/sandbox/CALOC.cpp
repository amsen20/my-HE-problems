#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 60, MOD = 1e9+7;

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

struct dat{
    int sum[4][4], cnt[4][4];
    dat(){
        memset(sum, 0, sizeof sum);
        memset(cnt, 0, sizeof cnt);
    }
} dp[N];

int mp[4][4];

dat merge(const dat &f, const dat &s){
    dat ret;
    for(int ll=0 ; ll<4 ; ll++)
        for(int lr=0 ; lr<4 ; lr++)
            for(int rl=0 ; rl<4 ; rl++)
                for(int rr=0 ; rr<4 ; rr++){
                    sadd(ret.cnt[ll][rr], mul(f.cnt[ll][lr], s.cnt[rl][rr]));
                    int cur = mul(f.cnt[ll][lr], s.sum[rl][rr]);
                    sadd(cur, mul(f.sum[ll][lr], s.cnt[rl][rr]));
                    int cnt = mp[lr][rl];
                    sadd(cur, mul(cnt, mul(f.cnt[ll][lr], s.cnt[rl][rr])));
                    sadd(ret.sum[ll][rr], cur);
                }
    return ret;
}

void init();

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
    init();
    for(int i=0 ; i<4 ; i++)
        dp[0].cnt[i][i] = 1;
    for(int bt=1 ; bt<N ; bt++)
        dp[bt] = merge(dp[bt-1], dp[bt-1]);
    int n;cin >> n;
    dat ans = dp[0];
    for(int i=0 ; i<N ; i++)
        if((n-1) & (1LL << i))
            ans = merge(ans, dp[i]);
    int out = 0;
    for(int l=0 ; l<4 ; l++)
        for(int r=0 ; r<4 ; r++){
            int cur = mul(ans.cnt[l][r], 1 + (bool(r&1) != bool(r&2)));
            sadd(cur, ans.sum[l][r]);
            sadd(out, cur);
        }
    //cerr << out << "\n";
    cout << mul(out, inv(bp(2, 2LL*n))) << "\n";
}

void init(){
    mp[0][0] = 0;
    mp[0][1] = 0;
    mp[0][2] = 0;
    mp[0][3] = 1;
    mp[1][0] = 1;
    mp[1][1] = 0;
    mp[1][2] = 2;
    mp[1][3] = 1;
    mp[2][0] = 1;
    mp[2][1] = 2;
    mp[2][2] = 0;
    mp[2][3] = 1;
    mp[3][0] = 1;
    mp[3][1] = 0;
    mp[3][2] = 0;
    mp[3][3] = 0;
}

