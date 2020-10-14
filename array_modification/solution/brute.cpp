#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define int ll

const int N = 2e5+100;

int a[N];

signed main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
    int ls=0;
    int n;cin >> n;
    for(int i=0 ; i<n ; i++)
        cin >> a[i];
    int ans=0;
    for(int i=0 ; i<n ; i++){
        int pref=0;
        for(int j=0 ; j<i ; j++){
            pref += a[j];
            pref /= 2;
        }
        int suf=0;
        for(int j=n-1 ; j>i ; j--){
            suf += a[j];
            suf /= 2;
        }
        ans = max(ans, pref + suf + a[i]);
    }
    cout << ans << "\n";
}
