#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

const int N = 2e5+100, M = 1e6+100;

vector<ii> v[N];

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n;cin >> n;
    for(int i=0 ; i<n ; i++){
        int m;cin >> m;
        while(m --){
            int l, r;cin >> l >> r;l --;
            v[i].push_back(ii(l, r));
        }
    }
    for(int i=0 ; i<M ; i++){
        bool f = true;
        for(int j=0 ; j<n ; j++)
            for(auto inv : v[j]){
                if(inv.first > i)
                    break;
                if(inv.first <= i && inv.second > i){
                    f = false;
                    break;
                }
            }
        if(f){
            cout << i+1 << "\n";
            return 0;
        }
    }
    cout << "-1\n";
}
