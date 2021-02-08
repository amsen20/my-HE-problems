#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    if(a > b)
        swap(a, b);
    if(a == 0)
        return b;
    return gcd(b%a, a);
}

const int N = 2e5+100;

int a[N], pref[N], suf[N];

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n;cin >> n;
    for(int i=0 ; i<n ; i++){
        cin >> a[i];
        pref[i] = gcd(a[i], (i ? pref[i-1] : 0));
    }
    for(int i=n-1 ; i>=0 ; i--)
        suf[i] = gcd(a[i], suf[i+1]);
    int mx=0;
    for(int i=0 ; i<n ; i++){
        int g = gcd((i ? pref[i-1] : 0), suf[i+1]);
        mx = max(mx, g);
    }
    cout << mx << "\n";
}
