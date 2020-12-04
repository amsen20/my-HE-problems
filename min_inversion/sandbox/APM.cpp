#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5+100;

int a[N];

signed main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n;cin >> n;
    for(int i=0 ; i<n ; i++)
        cin >> a[i];
    int invs = 0;
    for(int i=0 ; i<n ; i++)
        for(int j=0 ; j<i ; j++)
            if(a[j] > a[i])
                invs ++;
    int mx=0;
    for(int i=0 ; i<n ; i++)
        for(int j=i+1 ; j<n ; j++)
            if(a[i] > a[j]){
                int cnt=0;
                for(int k=i+1 ; k<j ; k++)
                    if(a[k] < a[i] && a[k] > a[j])
                        cnt ++;
                mx = max(mx, 2*cnt+1);
            }
    cout << invs-mx << "\n";
}
