// In the name of Allah.
// We're nothing and you're everything.
// Ya Ali!

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 2e5 + 14, mod = 998244353;
int n, dp[maxn][2];
vector<int> g[maxn], _pre[maxn], _pre2[maxn];
void dfs(int v = 0, int p = -1){
    vector<int> &pre = _pre[v], &pre2 = _pre2[v];
    pre.resize(g[v].size() + 1);
    pre2.resize(g[v].size() + 1);
    pre[0] = 1;
    for(int i = 0; i < g[v].size(); i++){
        g[g[v][i]].erase(find(g[g[v][i]].begin(), g[g[v][i]].end(), v));
        dfs(g[v][i]);
        pre[i + 1] = (ll) pre[i] * (dp[g[v][i]][0] + dp[g[v][i]][1]) % mod;
        pre2[i + 1] = ((ll) pre[i] * dp[g[v][i]][1] + pre2[i] * ll(dp[g[v][i]][0] + dp[g[v][i]][1])) % mod;
    }
    dp[v][1] = pre[g[v].size()];
    for(int i = (int) g[v].size() - 1, suf = 1; i >= 0; i--){
        int u = g[v][i];
        dp[v][1] = (dp[v][1] + (ll) dp[u][1] * suf % mod * pre[i]) % mod;
        dp[v][0] = (dp[v][0] + (ll) pre2[i] * dp[u][1] % mod * suf) % mod;
        suf = (ll) suf * (dp[u][0] + dp[u][1]) % mod;
    }
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for(int i = 0; i < n - 1; i++){
        int v, u;
        cin >> v >> u;
        v--, u--;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    dfs();
    cout << (dp[0][0] + dp[0][1])%mod << '\n';
}
