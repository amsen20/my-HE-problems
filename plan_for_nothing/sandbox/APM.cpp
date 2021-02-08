#include<bits/stdc++.h>
using namespace std;

const int N = 2e5+100, M = 1e6+100;

int cnt[M];

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n;cin >> n;
    for(int i=0 ; i<n ; i++){
        int m;cin >> m;
        while(m --){
            int l, r;cin >> l >> r;l --;
            cnt[l] ++;
            cnt[r] --;
        }
    }
    int sum=0;
    for(int i=0 ; i<M ; i++){
        sum += cnt[i];
        if(!sum){
            cout << i+1 << "\n";
            return 0;
        }
    }
    cout << "-1\n";
}
