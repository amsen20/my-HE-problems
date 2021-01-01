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
    for(int i=0 ; i<n-1 ; i++)
        cout << i+1 << " " << (i+1)%(n-1)+1 << "\n";
}
