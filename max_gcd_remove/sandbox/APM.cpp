#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    if(a > b)
        swap(a, b);
    if(a == 0)
        return b;
    return gcd(b%a, a);
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n;cin >> n;
    vector<int> v;
    for(int i=0 ; i<n ; i++){
        int d;cin >> d;
        v.push_back(d);
    }
    sort(v.begin(), v.end());
    v.erase(v.begin());
    int x = 0;
    for(auto i : v)
        x = gcd(x, i);
    cout << x << "\n";
}
