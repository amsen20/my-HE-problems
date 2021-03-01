#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int N = 2e5+100, M = 3e5+100;

string to_str(int x){
    if(!x)
        return "0";
    string ret;
    while(x){
        int d = x%10;
        ret.push_back(d+'0');
        x /= 10;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

signed main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n, v;cin >> n >> v;
    string ans;
    for(int i=0 ; i<n ; i++){
        string s;cin >> s;
        int d;cin >> d;
        if(!d)
            continue;
        string cur;
        for(int j=0 ; j<v ; j++){
            string var;
            if(s[j] == '0')
                var = "(!" + to_str(j) + ")";
            else
                var = to_str(j);
            if(cur.empty())
                cur = var;
            else
                cur = "(" + cur + "&" + var + ")";
        }
        if(ans.empty())
            ans = cur;
        else
            ans = "(" + ans + "|" + cur + ")";            
    }
    cout << ans << "\n";
}
