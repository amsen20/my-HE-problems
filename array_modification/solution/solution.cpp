#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define int ll

const int N = 2e5+100;

int ans[N], a[N];

signed main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
    int ls=0;
    int n;cin >> n;
    for(int i=0 ; i<n ; i++){
        cin >> a[i];
        ans[i] = a[i];
    }
    for(int i=0 ; i<n ; i++){
        ans[i] += ls;
        ls += a[i];
        ls /= 2;
    }
    ls = 0;
    for(int i=n-1 ; i>=0 ; i--){
        ans[i] += ls;
        ls += a[i];
        ls /= 2;
    }
    cout << *max_element(ans, ans+n) << "\n";
}
