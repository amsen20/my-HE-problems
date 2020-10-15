#include<bits/stdc++.h>
using namespace std;

#define greater greater123123
#define less less123123

const int N = 3e5+100;

int a[N];

struct Seg{
    int seg[4*N];

    Seg(){
        memset(seg, 0, sizeof seg);
    }

    int get(int l, int r, int s=0, int e=N, int id=1){
        if(r<=s || e<=l)
            return 0;
        if(l<=s && e<=r)
            return seg[id];
        int mid = (s + e)/2;
        return max(get(l, r, s, mid, 2*id), get(l, r, mid, e, 2*id+1));
    }

    void upd(int x, int val, int s=0, int e=N, int id=1){
        if(s>x || e<=x)
            return;
        if(e-s == 1){
            seg[id] = max(seg[id], val);
            return;
        }
        int mid = (s + e)/2;
        upd(x, val, s, mid, 2*id);
        upd(x, val, mid, e, 2*id+1);
        seg[id] = max(seg[2*id], seg[2*id+1]);
    }
} greater, less;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n;cin >> n;
    for(int i=0 ; i<n ; i++)
        cin >> a[i];
    reverse(a, a+n);
    int ans=0;
    for(int i=0 ; i<n ; i++){
        // <= a[i]
        int cur1 = less.get(0, a[i]+1) + 1;
        ans = max(ans, cur1);
        // >= a[i]
        int cur2 = greater.get(a[i], N) + 1;
        greater.upd(a[i], cur1);
        less.upd(a[i], cur2);
    }

    cout << ans << "\n";
}
