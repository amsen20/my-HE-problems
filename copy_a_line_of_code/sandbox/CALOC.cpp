#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n, i;cin >> n >> i;
    int l = n - i;
    cout << min(l+4, 2*l) << "\n";
}

