#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int N = 2e5+100;

vector<int> g[N];
int n;
bool dp_dn[N][2];

map<ii, int> mp;

void fil(vector<int> &d, function<int(int, int)> f, int def){
    int ls=def;
    for(auto &i : d){
        i = f(ls, i);
        ls = i;
    }
}

void proc(vector<int> &pref, vector<int> &suf, function<int(int, int)> f, int def){
    fil(pref, f, def);
    reverse(suf.begin(), suf.end());
    fil(suf, f, def);
    reverse(suf.begin(), suf.end());
}

void dfs_prep(int v, int par){
    int cnt=0;
    vector<int> ch, pref, suf;
    dp_dn[v][0] = 1;
    for(auto u : g[v]){
        if(u == par)
            continue;
        cnt ++;
        dfs_prep(u, v);
        dp_dn[v][0] *= dp_dn[u][1];
        ch.push_back(u);
        pref.push_back(dp_dn[u][1]);
        suf.push_back(dp_dn[u][1]);
    }
    dp_dn[v][1] = dp_dn[v][0];
    proc(pref, suf, [&](int a, int b){return a*b;}, 1);
    for(int i=0 ; i<ch.size() ; i++){
        int cur = (i ? pref[i-1] : 1);
        cur *= (i+1 < ch.size() ? suf[i+1] : 1);
        cur *= dp_dn[ ch[i] ][0];
        dp_dn[v][1] ^= cur;
    }
}

int ans;

void dfs(int v=0, int par=-1, int up_used=0, int up_unused=1){
    if(par >= 0){
        int w = mp[ii(v, par)];
        ans ^= up_used * dp_dn[v][0] * w;
    }
    vector<int> used, unused, ch, pref, suf, ppref, ssuf;
    for(auto u : g[v]){
        if(u == par)
            continue;
        ch.push_back(u);
        pref.push_back(dp_dn[u][1]);
        suf.push_back(dp_dn[u][1]);
        used.push_back(0);
        unused.push_back(0);
    }
    proc(pref, suf, [&](int a, int b){return a*b;}, 1);
    for(int i=0 ; i<ch.size() ; i++){
        int cur = (i ? pref[i-1] : 1);
        cur *= (i+1 < ch.size() ? suf[i+1] : 1);
        used[i] ^= cur * up_unused;
        unused[i] ^= cur * (up_used ^ up_unused);
        ppref.push_back(dp_dn[ ch[i] ][0] * (i ? pref[i-1] : 1));
        ssuf.push_back(dp_dn[ ch[i] ][0] * (i+1 < ch.size() ? suf[i+1] : 1));
    }
    proc(ppref, ssuf, [&](int a, int b){return a^b;}, 0);
    for(int i=0 ; i<ch.size() ; i++){
        if(i) { // left
            int cur = ppref[i-1] * (i+1 < ch.size() ? suf[i+1] : 1);
            unused[i] ^= cur * up_unused;
        }
        if(i+1 < ch.size()) { // right
            int cur = ssuf[i+1] * (i ? pref[i-1] : 1);
            unused[i] ^= cur * up_unused;
        }
        int u = ch[i];
        dfs(u, v, used[i], unused[i]);
    }
}

signed main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
    cin >> n;
    for(int i=0 ; i<n-1 ; i++){
        int v, u, w;cin >> v >> u >> w;v --;u --;
        g[v].push_back(u);
        g[u].push_back(v);
        mp[ii(v, u)] = w;
        mp[ii(u, v)] = w;
    }
    dfs_prep(0, -1);
    dfs();
    cout << ans << "\n";
}
