#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 7030;

int a[N];

struct Fen{
	int fen[N];
 
	Fen(){
		memset(fen, 0, sizeof fen);
	}
 
	void add(int x, int v){
		for( ; x<N ; x += x&-x)
			fen[x] += v;
	}
 
	int get(int x){
		int ret=0;
		for(; x ; x -= x&-x)
			ret += fen[x];
		return ret;
	}
} f;

signed main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n;cin >> n;
    for(int i=0 ; i<n ; i++)
        cin >> a[i];
    int invs=0, mx=0;
    for(int i=0 ; i<n ; i++){
        memset(f.fen, 0, sizeof f.fen);
        for(int j=i+1 ; j<n ; j++){
            if(a[i] > a[j]){
                invs ++;
                int mid = f.get(a[i]) - f.get(a[j]);
                mx = max(mx, 2*mid+1);
            }
            f.add(a[j], 1);
        }
    }
    cout << invs-mx << "\n";
}
