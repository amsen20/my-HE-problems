#include<bits/stdc++.h>
using namespace std;

const int MAXN = 3e5+100;

int a[MAXN];

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n;cin >> n;
    for(int i=0 ; i<n ; i++)
        cin >> a[i];
    sort(a, a+n);
    cout << (a[n-1]&a[n-2]) << "\n";
}
