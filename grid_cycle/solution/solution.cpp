#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1010;

string mat[N];

signed main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n, m;cin >> n >> m;
	int cnt[3] = {};
	for(int i=0 ; i<n ; i++){
		cin >> mat[i];
		for(int j=0 ; j<m ; j++)
			if(mat[i][j] == '.')
				cnt[(i+j)%3] ++;
	}
	int del = min_element(cnt, cnt+3) - cnt;
	for(int i=0 ; i<n ; i++)
		for(int j=0 ; j<m ; j++)
		if((i+j) % 3 == del)
			mat[i][j] = '#';
	for(int i=0 ; i<n ; i++)
		cout << mat[i] << "\n";
}
