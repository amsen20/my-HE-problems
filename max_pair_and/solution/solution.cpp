#include<bits/stdc++.h>
using namespace std;

bool hv(int x, int b){
    return x & (1 << b);
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n;cin >> n;
    multiset<int> st;
    for(int i=0 ; i<n ; i++){
        int d;cin >> d;
        st.insert(d);
    }
    for(int bt=30 ; bt>=0 ; bt --){
        if(!hv(*st.rbegin(), bt))
            continue;
        auto it = st.rbegin();
        it ++;
        if(!hv(*it, bt)){
            int d = *st.rbegin();
            st.erase(st.find(d));
            d -= (1 << bt);
            st.insert(d);
            continue;
        }
        while(!hv(*st.begin(), bt))
            st.erase(st.begin());
    }
    cout << *st.rbegin() << "\n";
}












