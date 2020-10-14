#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int N = 2e5+100, M = 3e5+100;

ii e[2][M];
int p[N];

signed main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n, m;cin >> n >> m;
    for(int j=0 ; j<2 ; j++)
        for(int i=0 ; i<m ; i++)
           cin >> e[j][i].first >> e[j][i].second;
    set<int> st;
    for(int i=1 ; i<=n ; i++)
        st.insert(i);
    p[e[0][0].first-1] = e[1][0].first;
    p[e[0][0].second-1] = e[1][0].second;
    st.erase(e[1][0].first);
    st.erase(e[1][0].second);
    for(int i=0 ; i<n ; i++)
        if(!p[i]){
            p[i] = *st.begin();
            st.erase(st.begin());
        }
    for(int i=0 ; i<n ; i++)
        cout << p[i] << " \n"[i == n-1];
}
