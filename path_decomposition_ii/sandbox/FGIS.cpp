#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int N = 1e5+100, M = 17, MOD = 998244353;

int add(ll a, int b){
	return (a + b + 2LL*MOD) % MOD;
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

int prob(int a, int b){
	return mul(a, inv(add(a, b)));
}

vector<int> g[N];
int dp[N][2], up[N], dn[N], inv_two;

void dfs_dn(int v, int par){
	int all=1, sum=0;
	for(auto u : g[v]){
		if(u == par)
			continue;
		dfs_dn(u, v);
		int cur = add(dp[u][0], dp[u][1]);
		smul(all, cur);
		sadd(sum, prob(dp[u][0], dp[u][1]));
	}
	dp[v][0] = dn[v] = all;
	int sum2 = mul(sum, sum);
	for(auto u : g[v]){
		if(u == par)
			continue;
		int cur = prob(dp[u][0], dp[u][1]);
		sadd(dp[v][0], mul(all, cur));
		sadd(sum2, -mul(cur, cur));
	}
	smul(sum2, all);
	smul(sum2, inv_two);
	dp[v][1] = sum2;
}

void dfs_up(int v, int par, int up0, int up1){
	int cur_up = prob(up0, up1);
	int all=add(up0, up1), sum=cur_up, sum2s=mul(cur_up, cur_up);
	up[v] = add(up0, up1);
	for(auto u : g[v]){
		if(u == par)
			continue;
		smul(all, add(dp[u][0], dp[u][1]));
		int cur = prob(dp[u][0], dp[u][1]);
		sadd(sum, cur);
		sadd(sum2s, mul(cur, cur));
	}
	int cdp[2] = {};
	cdp[0] = add(all, mul(all, cur_up));
	for(auto u : g[v]){
		if(u == par)
			continue;
		int cur = prob(dp[u][0], dp[u][1]);
		sadd(cdp[0], mul(cur, all));
	}
	for(auto u : g[v]){
		if(u == par)
			continue;
		int cur = prob(dp[u][0], dp[u][1]), c_inv = inv(add(dp[u][0], dp[u][1]));
		int c0 = add(cdp[0], -mul(all, cur));
		smul(c0, c_inv);
		int csum = add(sum, -cur);
		int csum2s = add(sum2s, -mul(cur, cur));
		int csum2 = add(mul(csum, csum), -csum2s);
		smul(csum2, inv_two);
		smul(csum2, mul(all, c_inv));
		int c1 = csum2;
		dfs_up(u, v, c0, c1);
	}
}

int par[N][M], cnt[N][M], h[N];

int get_par(int v, int len){
	for(int i=0 ; i<M ; i++)
		if(len & (1 << i)){
			v = par[v][i];
		}
	return v;
}

int get_cnt(int v, int len){
	int ret = 1, ls=-1;
	for(int i=0 ; i<M ; i++)
		if(len & (1 << i)){
			smul(ret, cnt[v][i]);
			if(ls >= 0)
				smul(ret, inv(add(dp[ls][0], dp[ls][1])));
			ls = get_par(v, (1 << i)-1);
			v = par[v][i];
		}
	return ret;
}

void dfs_calc(int v, int p){
	h[v] = (p>=0 ? h[p] + 1 : 0);
	par[v][0] = p;
	cnt[v][0] = dn[v];
	for(int lg=1 ; lg<M ; lg++){
		par[v][lg] = par[ par[v][lg-1] ][lg-1];
		if(par[v][lg] == -1)
			continue;
		cnt[v][lg] = mul(cnt[v][lg-1], cnt[ par[v][lg-1] ][lg-1]);
		int cmn = get_par(v, (1 << (lg-1))-1);
		int cur_inv = inv(add(dp[cmn][0], dp[cmn][1]));
		smul(cnt[v][lg], cur_inv);
	}

	for(auto u : g[v])
		if(u != p)
			dfs_calc(u, v);
}

int lca(int v, int u){
	if(h[v] < h[u])
		swap(v, u);
	v = get_par(v, h[v]-h[u]);
	if(v == u)
		return v;
	for(int i=M-1 ; i>=0 ; i--)
		if(par[v][i] != par[u][i]){
			v = par[v][i];
			u = par[u][i];
		}
	return par[v][0];
}

int eval(int v, int u){
	int cmn = lca(v, u);
	int ret = mul(get_cnt(v, h[v] - h[cmn]), get_cnt(u, h[u] - h[cmn]));
	auto upd = [&](int v){
		if(h[v] == h[cmn])
			return;
		int ls = get_par(v, h[v] - h[cmn] - 1);
		smul(ret, inv(add(dp[ls][0], dp[ls][1])));
	};
	upd(v);
	upd(u);
	smul(ret, dn[cmn]);
	smul(ret, up[cmn]);
	return ret;
}

signed main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	inv_two = inv(2);
	int n, q;cin >> n >> q;
	for(int i=0 ; i<n-1 ; i++){
		int v, u;cin >> v >> u;v --;u --;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	dfs_dn(0, -1);
	dfs_up(0, -1, 0, 1);
	dfs_calc(0, -1);
	while(q --){
		int v, u;cin >> v >> u;v --;u --;
		cout << eval(v, u) << "\n";
	}
}
