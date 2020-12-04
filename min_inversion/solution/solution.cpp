#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5+100, M=20;

int a[N], n, seg[M][N];

void build(int s=0, int e=n, int h=0){
    if(e-s == 1){
        seg[h][s] = a[s];
        return;
    }
    int mid = (s + e)/2;
    build(s, mid, h+1);
    build(mid, e, h+1);
    merge(seg[h+1]+s, seg[h+1]+mid, seg[h+1]+mid, seg[h+1]+e, seg[h]+s);
}

int get(int l, int r, int lb, int hb, int s=0, int e=n, int h=0){
    if(e<=l || r<=s)
        return 0;
    if(l<=s && e<=r){
        int ilb = lower_bound(seg[h]+s, seg[h]+e, lb) - seg[h] - s;
        int ihb = lower_bound(seg[h]+s, seg[h]+e, hb) - seg[h] - s;
        return ihb-ilb;
    }
    int mid = (s + e)/2;
    return get(l, r, lb, hb, s, mid, h+1) + get(l, r, lb, hb, mid, e, h+1);
}

int eval(int l, int r){
    int lb = min(a[l], a[r])+1, hb = max(a[l], a[r]);
    int cnt = (a[l] > a[r] ? 1 : -1);
    if(lb != hb)
        cnt += (a[l] > a[r] ? 1 : -1) * 2*get(l, r+1, lb, hb);
    return cnt;
}

struct Fen{
	int fen[N];
 
	Fen(){
		memset(fen, 0, sizeof fen);
	}
 
	void add(int x, int v){
		for( ; x<N ; x += x&-x)
			fen[x] += v;
	}
 
	int get(int x){
		int ret=0;
		for(; x ; x -= x&-x)
			ret += fen[x];
		return ret;
	}
} f;

signed main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
    cin >> n;
    for(int i=0 ; i<n ; i++)
        cin >> a[i];
    build();
    vector<int> v, u;
    v.push_back(0);
    for(int i=1 ; i<n ; i++)
        if(a[i] > a[ v.back() ])
            v.push_back(i);
    u.push_back(n-1);
    for(int i=n-2 ; i>=0 ; i--)
        if(a[i] < a[ u.back() ])
            u.push_back(i);
    reverse(u.begin(), u.end());
    auto l = v.begin(), r = u.begin();
    int mx=0;
    for(auto i : u)
        cerr << i << " ";
    cerr << "\n";
    for(; l != v.end() ; l++){
        while(r != u.end() && *r <= *l)
            r ++;
        if(r == u.end())
            break;
        vector<int>::iterator nxt;
        while(true){
            nxt = r;
            nxt ++;
            if(nxt == u.end())
                break;
            if(eval(*l, *r) <= eval(*l, *nxt))
                r = nxt;
            else
                break;
        }
        if(*l == 10 && *r == 79)
            cerr << " ### " << *nxt << "\n";
        cerr << *l << ", " << *r << "\n"; 
        mx = max(mx, eval(*l, *r));
    }

    int invs=0;
    for(int i=0 ; i<n ; i++){
        int cnt = f.get(a[i]);
        f.add(a[i], 1);
        invs += i-cnt;
    }
    cout << invs-mx << "\n";
}
