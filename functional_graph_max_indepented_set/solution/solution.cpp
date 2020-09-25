#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 5e2 + 20;
const int mod = 1e9 + 7;

int dp[2][maxn][maxn] , c[maxn][maxn];

inline void mkay(int &a)
{
	if(a >= mod)
		a -= mod;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	for(int i = 0; i < maxn; i++)
		for(int j = 0; j <= i; j++)
		{
			if(!j || i == j)
				c[i][j] = 1;
			else
				mkay(c[i][j] = c[i - 1][j] + c[i - 1][j - 1]);
		}

	int n , m;
	cin >> n >> m;

	dp[1][1][1] = 1;
	// toole i, j ta block, k ta adade mokhtalef
	for(int i = 1; i < n; i++)
	{
		int x = i&1;
		memset(dp[x ^ 1] , 0 , sizeof dp[x ^ 1]);
		for(int j = 0; j <= m; j++)
			for(int k = j; k <= m && k <= i; k++)
			{
				mkay(dp[x ^ 1][j + 1][k + 1] += 1LL * (j + 1) * dp[x][j][k] % mod);
				mkay(dp[x ^ 1][j][k + 1] += 1LL * (2 * j) * dp[x][j][k] % mod);
				if(j)
					mkay(dp[x ^ 1][j - 1][k + 1] += 1LL * (j - 1) * dp[x][j][k] % mod);
				mkay(dp[x ^ 1][j][k] += 1LL * j * dp[x][j][k] % mod);
			}
	}

	int res = 0;
	for(int j = 1; j <= m; j++)
		for(int k = 1; k <= m; k++)
			mkay(res += 1LL * dp[n&1][j][k] * c[m - k + 1][j] % mod);

	cout << res << endl;
}












