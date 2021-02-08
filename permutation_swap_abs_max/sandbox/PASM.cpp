#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef long long ll;

#define int ll

const int N = 1e5+100;

signed main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n;cin >> n;
    int ans=0, mnr=n, mxl=-1;
    for(int i=0 ; i<n ; i++){
        int d;cin >> d;d --;
        ans += abs(d - i);
        int l=i, r=d;
        if(l>r)
            swap(l, r);
        mnr = min(mnr, r);
        mxl = max(mxl, l);
    }
    if(mxl > mnr)
        ans += 2*(mxl-mnr);
    cout << ans << "\n";
}

