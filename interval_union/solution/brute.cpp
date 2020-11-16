#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef long long ll;

const int N = 22;

ii a[N];
int uni[4*N], sz;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n;cin >> n;
    int mx = -1;
    for(int i=0 ; i<n ; i++)
        cin >> a[i].first >> a[i].second;
    sort(a, a+n);
    for(int i=0 ; i<n ; i++){
        if(mx < a[i].first){
            uni[sz ++] = mx;
            uni[sz ++] = a[i].first;
        }
        mx = a[i].second;
    }
    uni[sz ++] = mx;
    int ans=0;
    for(int msk=1 ; msk<(1<<n) ; msk+=2){
        int mx=-1;
        bool f = true;
        int it=0;
        for(int i=0 ; i<n ; i++){
            if(!((1<<i)&msk))
                continue;
            if(mx<a[i].first){
                if(it >= sz || uni[it ++] != mx){
                    f = false;
                    break;
                }
                if(it >= sz || uni[it ++] != a[i].first){
                    f = false;
                    break;
                }
            }
            mx = a[i].second;
        }
        f &= (uni[it ++] == mx);
        f &= (it == sz);
        ans += f;
    }
    cout << ans << "\n";
}
