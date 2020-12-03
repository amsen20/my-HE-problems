#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6, mod = 1e9 + 7;
struct Seg{
  int l, r;
  bool operator <(Seg o) const{
    return l < o.l;
  }
}  a[maxn];
int dp[maxn];
int main(){
  int n;
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> a[i].l >> a[i].r;
    //a[i].r++;
  }
  sort(a, a + n);
  dp[0] = 1;
  int ans = 1;
  for(int l = 0, i = 1; i < n; i++){
    while(l < i - 1 && a[l].r < a[i].l)
      (ans += mod - dp[l++]) %= mod;
    dp[i] = ans;
    // cout << a[i].l << ' ' << a[i].r << ' ' << dp[i] << '\n';
    ans = ans * 2 % mod;
  }
  cout << dp[n - 1] << '\n';
}
