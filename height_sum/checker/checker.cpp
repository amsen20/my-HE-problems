#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5+100;

vector<int> g[N];
ll sum;
bool mark[N];
int seen;

void dfs(int v, int par, int h=1){
	assert(!mark[v]);
	//quitf(_wa, "Output is not a tree.");
	cerr << v << " , " << par << " , " << h << " *** \n";
	assert(v >= 0 && v < N);
	mark[v] = true;
	seen ++;
	sum += h;
	
	// cerr << " ** " << v << ", " << mark[v] << "\n";
	for(auto u : g[v])
		if(u != par){
			cerr << "calling: " << u << ", " << v << ", " << h+1 << "\n";
			dfs(u, v, h+1);
		}
}

int main()
{
	// registerChecker("mls", argc, argv);
	int n;cin >> n;// = inf.readInt();
	ll m;cin >> m;// = inf.readLong();
	ll mn = 2*(n-1) + 1, mx = 1LL*n*(n+1)/2;
	if(m < mn || m > mx){
		int d;cin >> d;// = ouf.readInt();
		assert(d == -1);
		cout << "4\n";
		return 0;
		// if(d != -1)
		// 	quitf(_wa, "There is no tree like that.");
		// else
		// 	quitf(_ok, "ok.");
	}
	int t=n-1;
	while(t --){
		int v;cin >> v;v --;
		int u;cin >> u;u --;
		cerr << v << ", " << u << "\n";
		assert(v >= 0 && u >= 0 && v < N && u < N);
		g[v].push_back(u);
		g[u].push_back(v);
	}
	dfs(0, -1);
	cerr << sum << ", " << seen << "\n";
	if(sum == m && seen == n){
		cout << "4\n";
		return 0;
	}
	assert(false);
}
