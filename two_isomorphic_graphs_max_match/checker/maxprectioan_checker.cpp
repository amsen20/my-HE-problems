#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

vector<ii> es;

map<ii, bool> is;

const int N = 1e5+100;

int p[N];

signed main(signed argc, char * argv[])
{
	//registerChecker("fs", argc, argv);
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n, m;cin >> n >> m;
    for(int i=0 ; i<m ; i++){
        int v, u;cin >> v >> u;v --;u --;
        es.push_back(ii(v, u));
    }
    for(int i=0 ; i<m ; i++){
        int v, u;cin >> v >> u;v --;u --;
        is[ii(v, u)] = true;
        is[ii(u, v)] = true;
    }
    set<int> st;
    for(int i=0 ; i<n ; i++){
        cin >> p[i];
        p[i] --;
        if(p[i] < 0 || p[i] >= n){
            cout << "0\n";
            return 0;
        }
        st.insert(p[i]);
    }
    if(st.size() != n){
        cout << "0\n";
        return 0;
    }
    int cnt=0;
    for(int i=0 ; i<m ; i++){
        int v = es[i].first, u = es[i].second;
        v = p[v];
        u = p[u];
        if(is[ii(v, u)])
            cnt ++;
    }
    cout << fixed << setprecision(7) << max(0.0, 5.0 * double(cnt)/m) << "\n";
}
