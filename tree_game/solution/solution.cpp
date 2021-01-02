#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int N = 1e5+100, M=18;

vector<int> g[N];

struct dat{
	int forced, sz;
	vector<int> cnt, val, to[2];
	int add_node(int v){
		to[0].push_back(-1);
		to[1].push_back(-1);
		cnt.push_back(0);
		val.push_back(v);
		return sz++;	
	}
	dat(){
		forced = sz = 0;
		add_node(0);
	}
	int get_mex(){
		assert(cnt[0] < (1 << M));
		int ret=0, it=0;
		for(int bt=M-1 ; bt>=0 ; bt--){
			bool fhv = (forced & (1 << bt));
			auto go = [&](bool f) -> int{
				int nxt = to[f][it];
				if(nxt == -1)
					return (((ret << 1) | f) << bt) | (((1 << bt)-1) & forced);
				if(cnt[nxt] < (1 << bt)){
					it = nxt;
					ret = (ret << 1) | f;
					return -1;
				}
				return -2;
			};
			int cur = go(fhv);
			if(cur>=0)
				return cur^forced;
			if(cur == -1)
				continue;
			cur = go(!fhv);
			if(cur>=0)
				return cur^forced;
		}
		return ret;
	}
	void add(int x){
		x ^= forced;
		int it=0, v=0;
		vector<int> path = {it};
		bool change = false;
		for(int bt=M-1 ; bt>=0 ; bt--){
			bool hv = (x & (1 << bt));
			v <<= 1;
			v |= hv;
			if(to[hv][it] == -1){
				int nw_node = add_node(v);
				to[hv][it] = nw_node;
				change = true;
			}
			cnt[it] ++;
			it = to[hv][it];
			path.push_back(it);
		}
		cnt[it] ++;
		if(!change)
			for(auto ver : path)
				cnt[ver] --;
	}
	bool merge(dat *other){
		if(sz < other->sz)
			return false;
		for(int i=1 ; i<other->sz ; i++)
			if(other->to[0][i] == -1 && other->to[1][i] == -1)
				add(other->val[i] ^ other->forced);
		return true;
	}
	void force(int x){
		forced ^= x;
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
			delete ret;
			ret = u;
		} else
			delete u;
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
		auto ans = dfs(0, -1).first;
		cout << (ans->get_mex() ? "A" : "B") << "\n";
		delete ans;
	}
}
