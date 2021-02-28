#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, int> ii;

const int N = 2e5+100;
const ll INF = 1e18;

ll dis0[N], disn[N], dis[N];
vector<ii> g[N];

int n, m;

void dij(int root, ll *dis, int banned=-1){
    for(int i=0 ; i<n ; i++)
        dis[i] = INF;
    set<ii> st;
    if(banned){
        st.insert(ii(0, root));
        dis[root] = 0;
    }
    while(!st.empty()){
        int v = st.begin()->second;
        st.erase(st.begin());
        for(auto U : g[v]){
            int u = U.first, w = U.second;
            if(dis[v] + w < dis[u] && u != banned){
                st.erase(ii(dis[u], u));
                dis[u] = dis[v] + w;
                st.insert(ii(dis[u], u));
            }
        }
    }
}

signed main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	cin >> n >> m;
	for(int i=0 ; i<m ; i++){
		int v, u, w;cin >> v >> u >> w;v --;u --;
		g[v].push_back(ii(u, w));
		g[u].push_back(ii(v, w));
	}
    dij(0, dis0);
    dij(n-1, disn);
    for(int i=0 ; i<n ; i++){
        if(dis0[i] + disn[i] != dis0[n-1])
            cout << "none\n";
        else{
            dij(0, dis, i);
            if(dis[n-1] == dis0[n-1])
                cout << "some\n";
            else
                cout << "all\n";
        }
    }
}
