#include<bits/stdc++.h>

using namespace std;

const int maxN = 20;
int a[maxN][maxN];
int dp[maxN][(1 << maxN)];

int main(){
	int n, m; cin >> n >> m;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			a[i][j] = -1;
	for(int i = 0; i < m; i++){
		int x, y, w; cin >> x >> y >> w;
		x --; y --;
		a[x][y] = a[y][x] = w;
	}
	for(int i = 0; i < n; i++)
		dp[0][(1 << i)] = 1;
	for(int i = 0; i < (1 << n); i++){
		for(int j = 0; j < n; j++){
			if(i & (1 << j)){
				int tmp = i ^ (1 << j);
				for(int t = 0; t < n; t++){
					if((tmp & (1 << t)) && (a[j][t] != -1)){
						dp[0][i] |= dp[0 ^ a[j][t]][tmp];
						dp[1][i] |= dp[1 ^ a[j][t]][tmp];
					}
				}
			}
		}	
	}
	cout << (dp[1][(1 << n) - 1] ? "YES" : "NO") << "\n";
}


