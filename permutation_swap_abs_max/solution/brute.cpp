#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef long long ll;

#define int ll

const int N = 1e5+100;

int p[N];

signed main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n;cin >> n;
    int ans=0, cur=0;
    for(int i=0 ; i<n ; i++){
        cin >> p[i];p[i] --;
        ans += abs(p[i] - i); 
    }
    cur = ans;
    for(int i=0 ; i<n ; i++)
        for(int j=i+1 ; j<n ; j++){
            int cur2 = cur;
            cur2 -= abs(p[j] - j);
            cur2 -= abs(p[i] - i);
            swap(p[i], p[j]);
            cur2 += abs(p[j] - j);
            cur2 += abs(p[i] - i);
            swap(p[i], p[j]);
            ans = max(ans, cur2);
        }
    cout << ans << "\n";
}

