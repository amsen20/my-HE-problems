#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define bit(a , b) (((a)>>(b))&1)

const int maxn = 5e2 + 20;
const int maxm = (1 << 17) + 20;
const int mod = 1e9 + 7;

int dp[2][maxm];

inline void mkay(int &a)
{
	if(a >= mod)
		a -= mod;
	else if(a < 0)
		a += mod;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n , m;
	cin >> n >> m;

	dp[0][0] = 1;
	for(int i = 0; i < n; i++)
	{
		int x = i&1;
		memset(dp[x ^ 1] , 0 , sizeof dp[x ^ 1]);
		for(int mask = 0; mask < (1 << m); mask++)
			for(int j = 0; j < m; j++)
				if(!j || !bit(mask , j - 1) || !bit(mask , j))
					mkay(dp[x ^ 1][mask | (1 << j)] += dp[x][mask]);
	}

	int res = 0;
	for(int mask = 0; mask < (1 << m); mask++)
		mkay(res += dp[n&1][mask]);

	cout << res << endl;
}












