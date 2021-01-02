#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int N = 1e5+100, M=18;

vector<int> g[N];

struct dat{
    set<int> all;
	dat(){
	}
	int get_mex(){
        int ret=0;
        while(all.count(ret))
            ret ++;
		return ret;
	}
	void add(int x){
        all.insert(x);
	}
	bool merge(dat *other){
		if(all.size() < other->all.size())
			return false;
        for(auto i : other->all)
            all.insert(i);
		return true;
	}
	void force(int x){
        set<int> tmp;
		for(auto i : all)
            tmp.insert(i^x);
        all = tmp;
	}
};

pair<dat*, int> dfs(int v, int par){
	dat *ret = new dat();
	int ch=0;
	vector<pair<dat*, int> > vec;
	for(auto u : g[v]){
		if(u == par)
			continue;
		auto child = dfs(u, v);
		auto cur = child.first;
		int cmex = cur->get_mex();
		ch ^= cmex;
		cur->add(child.second);
		vec.push_back({cur, cmex});
	}
	for(auto U : vec){
		auto u = U.first;
		auto cmex = U.second;
		u->force(ch ^ cmex);
		if(!ret->merge(u)){
			u->merge(ret);
			ret = u;
		}
	}
	return {ret, ch};
}

signed main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int t;cin >> t;
	while(t --){
		int n;cin >> n;
		for(int i=0 ; i<n ; i++)
			g[i].clear();
		for(int i=1 ; i<n ; i++){
			int p;cin >> p;p --;
			g[i].push_back(p);
			g[p].push_back(i);
		}
		cout << (dfs(0, -1).first->get_mex() ? "A" : "B") << "\n";
	}
}
