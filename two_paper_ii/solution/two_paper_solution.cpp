#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;

const int N = 3e5+100;

struct graph
{
	int n;
	vector<int> adj[N];
 
	graph(int n) : n(n){
        fill(adj, adj+n, vector<int>());
    }
 
	void add_edge(int u, int v)
	{
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
 	
	vector<int>& operator[](int u) { return adj[u]; }
};
 
vector<vector<int>> biconnected_components(graph &adj)
{
	int n = adj.n;
 
	vector<int> num(n), low(n), art(n), stk;
	vector<vector<int>> comps;
 
	function<void(int, int, int&)> dfs = [&](int u, int p, int &t)
	{
		num[u] = low[u] = ++t;
		stk.push_back(u);

		for (int v : adj[u]) if (v != p)
		{
			if (!num[v])
			{
				dfs(v, u, t);
				low[u] = min(low[u], low[v]);
 
				if (low[v] >= num[u])
				{
					art[u] = (num[u] > 1 || num[v] > 2);
 
					comps.push_back({u});
					while (comps.back().back() != v)
						comps.back().push_back(stk.back()), stk.pop_back();
				}
			}
			else low[u] = min(low[u], num[v]);
		}
	};
 
	for (int u = 0, t; u < n; ++u)
		if (!num[u]) dfs(u, -1, t = 0);
	
    return comps;
}

iii e[N];
int cnt[N];
bool mark[2][N];
set<int> c[N];

int get_cmn(set<int> &f, set<int> &s){
    if(f.size() > s.size())
        f.swap(s);
    for(auto v : f)
        if(s.count(v))
            return v;
    return -1;
}

signed main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n, m;cin >> n >> m;
    graph g = graph(n);
    for(int i=0 ; i<m ; i++){
        int v, u, w;cin >> v >> u >> w;v --;u --;
        e[i] = iii(ii(v, u), w);
        g.add_edge(v, u);
    }

    auto cmps = biconnected_components(g);
    int sz=0;
    for(auto cmp : cmps){
        for(auto i : cmp){
            c[i].insert(sz);
            cnt[sz] ++;
        }
        sz ++;
    }
    int all = 0;
    for(int i=0 ; i<m ; i++){
        int v = e[i].first.first, u = e[i].first.second, w = e[i].second;
        int cmn = get_cmn(c[v], c[u]);
        if(cmn > -1){
            mark[w][ cmn ] = true;
        }else
            all ^= w;
    }
    for(int i=0 ; i<sz ; i++){
        if(mark[1][i])
            all ^= (cnt[i] - 1);
        if(mark[0][i] && mark[1][i]){
            cout << "YES\n";
            return 0;
        }
    }
    cout << (all%2 == 1 ? "YES" : "NO") << "\n";
}
