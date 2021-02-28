#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, int> ii;

const int N = 2e5+100, M = 3e5+10;
const ll INF = 1e18;

ll dis[N];
int T, stt[N], who[N], cnt[N];
vector<ii> g[N], d_es;
vector<int> d[N], r[N];
bool ok[N], mark[N], all[N];

struct ed{
	int v, u, w;
	ed():
		v(-1), u(-1), w(-1) {}
	ed(int v, int u, int w):
		v(v), u(u), w(w) {}
} e[M];

void dfs(int v){
	ok[v] = true;
	for(auto u : r[v])
		if(!ok[u])
			dfs(u);
}

void dfs_top(int v){
	mark[v] = true;
	for(auto u : d[v])
		if(!mark[u] && ok[u])
			dfs_top(u);
	stt[v] = T++;
	who[ stt[v] ] = v;
}

signed main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n, m;cin >> n >> m;
	for(int i=0 ; i<m ; i++){
		int v, u, w;cin >> v >> u >> w;v --;u --;
		e[i] = ed(v, u, w);
		g[v].push_back(ii(u, w));
		g[u].push_back(ii(v, w));
	}
	for(int i=0 ; i<n ; i++)
		dis[i] = INF;
	set<ii> st;
	st.insert(ii(0, 0));
	dis[0] = 0;
	while(!st.empty()){
		int v = st.begin()->second;
		st.erase(st.begin());
		for(auto U : g[v]){
			int u = U.first, w = U.second;
			if(dis[u] > dis[v] + w){
				st.erase(ii(dis[u], u));
				dis[u] = dis[v] + w;
				st.insert(ii(dis[u], u));
			}
		}
	}
	for(int i=0 ; i<m ; i++){
		int v = e[i].v, u = e[i].u, w = e[i].w;
		if(dis[v] > dis[u])
			swap(v, u);
		if(dis[v] + w == dis[u]){
			d[v].push_back(u);
			r[u].push_back(v);
			d_es.push_back(ii(u, v));
		}
	}
	dfs(n-1);
	dfs_top(0);
	for(auto e : d_es){
		int v = e.first, u = e.second;
		if(!ok[v] || !ok[u])
			continue;
		cnt[ stt[v]+1 ] ++;
		cnt[ stt[u] ] --;
	}
	int sum=0;
	for(int i=0 ; i<T ; i++){
		sum += cnt[i];
		if(!sum)
			all[ who[i] ] = true;
	}
	int cnt1=0, cnt2=0;
	for(int i=0 ; i<n ; i++){
		if(!ok[i]){
			cout << "none\n";
			continue;
		}
		if(all[i]){
			cnt2 ++;
			cout << "all\n";
		}else{
			cnt1 ++;
			cout << "some\n";
		}
	}
	// assert(cnt1<100);
	// assert(cnt2<100   );
}
