#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef long long ll;

const int N = 3e5+100;

int p[N], mark[N], cnt[N];

signed main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n;cin >> n;
    for(int i=0 ; i<n ; i++)
        p[i] = i;
    do{
        for(int i=0 ; i<n ; i++)
            mark[i] = false;
        int cyc=0;
        for(int i=0 ; i<n ; i++){
            if(mark[i])
                continue;
            cyc ++;
            int it = i;
            while(!mark[it]){
                mark[it] = true;
                it = p[it];
            }
        }
        cnt[cyc] ++;
    }while(next_permutation(p, p+n));
    for(int i=1 ; i<=n ; i++)
        cout << cnt[i] << " \n"[i == n];
}
