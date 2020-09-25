#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define int ll

signed main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int a, b, l;cin >> a >> b >> l;
	if(b-a > l){
		for(int i=0 ; i<l-1 ; i++)
			cout << a+i << " " << a+i+1 << "\n";
		cout << a+l-1 << " " << b << "\n";
		return 0;
	}
	for(int i=0 ; i<b-a-1 ; i++)
		cout << a+i << " " << a+i+1 << "\n";
	l -= b-a-1;
	int f = b-1;
	while(--l){
		cout << (f+2)*f << " " << (f+1)*(f+1) << "\n";
		f ++;
	}
	cout << f << " " << f+1 << "\n";
}