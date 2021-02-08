#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int N = 555, INF = 1e9;

vector<int> g[N], r[N], cmp[N], top;
vector<ii> es;
bool mark[N], sink[N], source[N];
int c[N], cnt[N][N];

void dfs(int v){
	mark[v] = true;
	for(auto u : g[v])
		if(!mark[u])
			dfs(u);
	top.push_back(v);
}

void rdfs(int v, int col){
	cmp[col].push_back(v);
	c[v] = col;
	mark[v] = true;
	for(auto u : r[v])
		if(!mark[u])
			rdfs(u, col);
}

signed main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n, m;cin >> n >> m;
	while(m --){
		int v, u;cin >> v >> u;v --;u --;
		g[v].push_back(u);
		r[u].push_back(v);
		es.push_back(ii(v, u));
	}
	for(int i=0 ; i<n ; i++){
		sink[i] = source[i] = true;
		if(!mark[i])
			dfs(i);
	}
	memset(mark, 0, sizeof mark);
	reverse(top.begin(), top.end());
	int sz=0;
	for(int i=0 ; i<n ; i++)
		if(!mark[i])
			rdfs(i, sz ++);
	for(auto e : es){
		int v = e.first, u = e.second;
		cnt[ c[v] ][ c[u] ] ++;
		source[ c[u] ] = false;
		sink[ c[v] ] = false;
	}
	for(int i=0 ; i<sz ; i++)
		if(source[i])
			for(int j=0 ; j<sz ; j++)
				if(sink[j] && i != j && cnt[i][j] == cmp[i].size() * cmp[j].size()){
					cout << "YES\n";
					return 0;
				}
	cout << "NO\n";
}
