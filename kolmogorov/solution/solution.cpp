#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<char, int> ci;

string str(int n){
    string ret;
    while(n){
        int d = n%10;
        ret.push_back(d + '0');
        n /= 10;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

signed main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n;cin >> n;
    string s;cin >> s;
    s += "$";
    vector<ci> v;
    string ans="";
    for(auto c : s){
        if(!v.size()){
            v.push_back(ci(c, 1));
            continue;
        }
        if(v.back().first == c){
            v.back().second ++;
            continue;
        }
        string ch;
        ch.push_back(v.back().first);
        ans += "\"" + ch + "\"*" + str(v.back().second) + "+";
        v.pop_back();
        v.push_back(ci(c, 1));
    }
    ans.pop_back();
    cout << "1\nprint(" << ans << ")\n";
}
