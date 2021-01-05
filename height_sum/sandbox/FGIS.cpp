#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int N = 1e5+100;

int ans[N];

void fin(){
	cout << "-1\n";
	exit(0);
}

signed main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n;
	ll x;cin >> n >> x;
	x -= n;
	if(x<2*(n-1) + 1 || x > n*(n+1)/2)
		fin();
	int cnt=n-1;
	ans[0] = 1;
	for(int i=1 ; i<n ; i++){
		if(!cnt)
			break;
		cnt --;
		ans[i] ++;
		x -= i;
		while(true){
			ll mn = (i < n-1 ? 1LL*cnt*(i+1) : 0);
			if(mn > x){
				ans[i] ++;
				x -= i;
				cnt --;
				continue;
			}
			break;
		}
	}
	if(x)
		fin();
	int ls=0, it=1;
	vector<ii> out;
	for(int i=1 ; i<n ; i++){
		int nls;
		while(ans[i] --){
			nls = it;
			out.push_back(ii(ls, it ++));
		}
		ls = nls;
	}
	for(auto i : out)
		cout << i.first+1 << " " << i.second+1 << "\n";
}
