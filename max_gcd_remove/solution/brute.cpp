#include<bits/stdc++.h>
using namespace std;

const int MAXN = 3e5+100;

int a[MAXN];

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n;cin >> n;
    for(int i=0 ; i<n ; i++)
        cin >> a[i];
    int ans=0;
    for(int i=0 ; i<n ; i++)
        for(int j=i+1 ; j<n ; j++)
            ans = max(ans, a[i]&a[j]);
    cout << ans << "\n";
}
