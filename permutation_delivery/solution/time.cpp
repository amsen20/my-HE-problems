#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef long long ll;

const int N = 2e3, MOD = 998244353;

int f[N][N];

signed main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n;cin >> n;
    f[1][1] = 1;
    for(int i=2 ; i<=n ; i++)
        for(int j=1 ; j<=n ; j++)
            f[i][j] = (f[i-1][j-1] + 1LL * f[i-1][j] * (i-1)) % MOD;
    for(int i=1 ; i<=n ; i++)
        cout << f[n][i] << " \n"[i == n];
}