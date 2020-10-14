#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int N = 3e5+100;

int f[N];
bool mark[N], mark2[N];

signed main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n;cin >> n;
	for(int i=0 ; i<n ; i++){
		cin >> f[i];f[i] --;
	}
    assert(n<=25);
    int ans=0;
    for(int msk=0 ; msk<(1<<n) ; msk++){
        bool fl = true;
        for(int i=0 ; i<n ; i++)
            if(msk & (1 << i))
                if(msk & (1 << f[i]))
                    fl = false;
        if(fl){
            ans = max(ans, __builtin_popcount(msk)); 
        }
    }
	cout << ans << "\n";
}
