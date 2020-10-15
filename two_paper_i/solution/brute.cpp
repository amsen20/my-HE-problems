#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;

signed main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n;cin >> n;
    vector<iii> ed;
    for(int i=0 ; i<n-1 ; i++){
        int v, u, w;cin >> v >> u >> w;v --;u --;
        ed.push_back(iii(ii(v, u), w));
    }
    int ans=0;
    for(int msk=0 ; msk<(1 << (n-1)) ; msk++){
        vector<iii> cur;
        int cans=0;
        for(int i=0 ; i<n-1 ; i++)
            if(msk & (1 << i)){
                cur.push_back(ed[i]);
                cans ^= ed[i].second;
            }
        bool f = true;
        for(int i=0 ; i<cur.size() ; i++)
            for(int j=i+1 ; j<cur.size() ; j++){
                set<int> st;
                st.insert(cur[i].first.first);
                st.insert(cur[i].first.second);
                st.insert(cur[j].first.first);
                st.insert(cur[j].first.second);
                if(st.size() != 4)
                    f = false;
            }
        if(f)
            ans ^= cans;
    }
    cout << ans << "\n";
}
