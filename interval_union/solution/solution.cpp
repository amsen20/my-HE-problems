#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef long long ll;

const int N = 3e5+100, M = 6e5+100, MOD = 1e9+7;

int add(ll a, int b){
    return (a + b + 2LL*MOD) % MOD;
}
 
int mul(ll a, int b){
    return (a * b) % MOD;
}

void sadd(int &a, int b){
    a = add(a, b);
}

void smul(int &a, int b){
    a = mul(a, b);
}

int en[M];

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
    memset(en, -1, sizeof en);
    int n;cin >> n;
    vector<ii> invs;
    vector<int> unq;
    for(int i=0 ; i<n ; i++){
        int l, r;cin >> l >> r;l --;
        unq.push_back(l);
        unq.push_back(r);
        invs.push_back(ii(l, r));
    }

    sort(unq.begin(), unq.end());
    unq.resize(unique(unq.begin(), unq.end()) - unq.begin());
    
    for(auto &&I : invs){
        auto find = [&](int d){
            return lower_bound(unq.begin(), unq.end(), d) - unq.begin();
        };
        int l = find(I.first), r = find(I.second);
        en[l] = r;
    }

    int ans=1, sum=0, cnt=0;
    map<int, int> mp;
    for(int i=0 ; i<M ; i++){
        if(mp.count(i)){
            if(cnt == 1)
                smul(ans, sum);
            sadd(sum, -mp[i]);
            cnt --;
        }
        if(en[i] == -1)
            continue;
        int cur = (cnt ? sum : 1);
        sadd(sum, cur);
        mp[en[i]] = cur;
        cnt ++;
    }
    cout << ans << "\n";
}
