#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

#define int ll

const int N = 2e5+100, MOD = 998244353;

vector<int> g[N];

int dp[N][2];

int bp(int a, int b){
    if(b == 0)
        return 1;
    int x = bp(a, b/2);
    x = x * x % MOD;
    return b&1 ? x * a % MOD : x;
}

int inv(int x){
    return bp(x, MOD-2);
}

void dfs(int v, int par){
    int all=1;
    for(auto u : g[v]){
        if(u == par)
            continue;
        dfs(u, v);
        all *= (dp[u][0] + dp[u][1]);
        all %= MOD;
    }
    dp[v][0] = all;
    for(auto u : g[v]){
        if(u == par)
            continue;
        dp[v][0] += all * inv(dp[u][0] + dp[u][1]) % MOD * dp[u][0] % MOD;
        dp[v][0] %= MOD;
    }
    for(int i=0 ; i<g[v].size() ; i++)
        for(int j=i+1 ; j<g[v].size() ; j++){
            if(g[v][i] == par || g[v][j] == par)
                continue;
            int u1 = g[v][i], u2 = g[v][j];
            int cur = all * inv(dp[u1][0] + dp[u1][1]) % MOD * dp[u1][0] % MOD;
            cur *= inv(dp[u2][0] + dp[u2][1]) % MOD * dp[u2][0] % MOD;
            dp[v][1] += cur;
            dp[v][1] %= MOD;
        }
}

signed main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n;cin >> n;
    for(int i=0 ; i<n-1 ; i++){
        int v, u;cin >> v >> u;v --;u --;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    dfs(0, -1);
    cout << (dp[0][0] + dp[0][1]) % MOD << "\n";
}
