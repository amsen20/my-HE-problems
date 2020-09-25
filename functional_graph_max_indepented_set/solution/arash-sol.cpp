// In the name of God

#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <deque>
#include <assert.h>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <stdio.h>
#include <string.h>
#include <utility>
#include <math.h>
#include <bitset>
#include <iomanip>
#include <complex>

using namespace std;

#define rep(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }
template<typename T> inline bool smin(T &a, const T &b)   { return a > b ? a = b : a;    }
template<typename T> inline bool smax(T &a, const T &b)   { return a < b ? a = b : a;    }

typedef long long LL;

const int N = (int) 505, mod = (int) 1e9 + 7;
int dp[N][N], odp[N][N], comb[N][N];
void sadd(int &x, int y) {
	x = (x + y) % mod;	
}
int main() {
	int n, m;
	cin >> n >> m;
	dp[0][0] = 1;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j <= i; ++j)
			comb[i][j] = (i == j || j == 0) ? 1 : (comb[i - 1][j - 1] + comb[i - 1][j]) % mod;
	for (int pos = 0; pos < n; ++pos) {
		memcpy(odp, dp, sizeof dp);
		memset(dp, 0, sizeof dp);
		for (int comp = 0; comp <= min(m, n); ++comp) {
			for (int g = comp; g <= m; ++g) {
				if (comp > 1) {
					sadd(dp[comp - 1][g + 1], odp[comp][g] * (LL) (comp - 1) % mod);
				}
				sadd(dp[comp + 1][g + 1], odp[comp][g] * (LL) (comp + 1) % mod);
				sadd(dp[comp][g + 1], odp[comp][g] * (LL) comp * 2 % mod); 
				sadd(dp[comp][g], odp[comp][g] * (LL) comp % mod);
			}
		}
	}
	int res = 0;
	for (int comp = 0; comp <= min(m, n); ++comp) {
		for (int g = comp; g <= m; ++g) if (dp[comp][g]) {
			int rem = m - g;
			rem += 2;
			int ways = dp[comp][g] * (LL) comb[rem - 1][comp] % mod;
			res = (res + ways) % mod;	
			
		}
	}
	cout << res << endl;
	
	
}

















