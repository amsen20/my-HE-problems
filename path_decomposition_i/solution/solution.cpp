#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int N = 2e5+100, MOD = 998244353;

vector<int> g[N];
int dp[N][2];

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

void dfs(int v, int par){
	int all=1, sum=0;
	for(auto u : g[v]){
		if(u == par)
			continue;
		dfs(u, v);
		int cur = add(dp[u][0], dp[u][1]);
		smul(all, cur);
		sadd(sum, mul(dp[u][0], inv(cur)));
	}
	dp[v][0] = all;
	int sum2 = mul(sum, sum);
	for(auto u : g[v]){
		if(u == par)
			continue;
		int cur = add(dp[u][0], dp[u][1]);
		cur = mul(dp[u][0], inv(cur));
		sadd(dp[v][0], mul(all, cur));
		sadd(sum2, -mul(cur, cur));
	}
	smul(sum2, all);
	smul(sum2, inv(2));
	dp[v][1] = sum2;
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
	cout << add(dp[0][0], dp[0][1]) << "\n";
}
