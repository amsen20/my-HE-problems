#include<bits/stdc++.h>
#include "testlib.h"
using namespace std;

typedef pair<int, int> ii;

vector<ii> build(set<int> st){
    vector<ii> ret;
    while(st.size() > 1){
        int f = *st.begin();st.erase(f);
        int s = *st.begin();st.erase(s);
        ret.push_back(ii(f, s));
    }
    return ret;
}

bool in(int x, const vector<ii> &vec){
    for(auto i : vec)
        if(x >= i.first && x <= i.second)
            return true;
    return false;
}

int main(int argc , char* argv[]){
	registerGen(argc, argv , 1);

	int n = atoi(argv[1]);
	int m = atoi(argv[2]);
    int cnt = atoi(argv[3]);
    char hv = argv[4][0];
    cnt *= 2;

    int block = (cnt+n-1)/n;
    int ans = (hv == 't' ? rnd.wnext(m, 3) : m);

    cout << n << "\n";

    for(int i=0 ; i<n ; i++){
        int ccnt = cnt < block ? cnt : block;
        if(!ccnt){
            cout << "0\n";
            continue;
        }
        set<int> st;
        while(ccnt --){
            int d;
            do{
                d = rnd.next(m);
            }while(st.count(d) || d == ans);
            st.insert(d);
        }
        auto fir = build(st);
        if(!st.count(0))
            st.insert(0);
        else
            st.erase(st.begin());
        auto sec = build(st);
        auto out = fir;
        if(!in(ans, sec))
            out = sec;
        else
            assert(!in(ans, fir));
        cout << out.size();
        if(out.empty()){
            cout << "\n";
            continue;
        }
        cout << " ";
        for(auto i : out)
            cout << i.first+1 << " " << i.second+1 << " \n"[out.back() == i];
        cnt -= out.size();
    }
    return 0;

}

