#include<bits/stdc++.h>
#include "testlib.h"
using namespace std;

typedef pair<int, int> ii;

vector<ii> out;

set<int> get_unq(int t, int l, int r){
    set<int> st;
    while(t --){
        int d;
        do{ 
            d = rnd.next(l, r-1);
        }while(st.count(d));
        st.insert(d);
    }
    return st;
}

void build(int l, int r, int cnt, int tp){
    if(tp == 1){
        if(cnt < 3 || l+cnt >= r-1-cnt)
            tp --;
        else{
            out.push_back(ii(l, l+cnt));
            out.push_back(ii(r-cnt, r-1));
            for(int i=0 ; i<cnt-2 ; i++)
                out.push_back(ii(l+1+i, r-1-cnt+i));
            return;
        }
    }
    if(tp == 0 || tp == 2){
        set<int> pts = get_unq(2*cnt, l, r);
        vector<int> v;
        for(int i=0 ; i<cnt ; i++)
            v.push_back(1);
        for(int i=0 ; i<cnt ; i++)
            v.push_back(-1);
        if(!tp) // random
            shuffle(v.begin(), v.end());
        auto it = pts.begin();
        int sum=0;
        deque<int> dq;
        for(auto i : v){
            int cur = *it ++;
            if(abs(sum + i) > abs(sum)){
                dq.push_back(cur);
            } else {
                int l = dq.front(), r = cur;dq.pop_front();
                out.push_back(ii(l, r));
            }
            sum += i;
        }
        return;
    }
    
    { // linear
        vector<int> pts;
        for(auto i : get_unq(cnt+1, l, r))
            pts.push_back(i);
        for(int i=1 ; i<pts.size() ; i++)
            out.push_back(ii(pts[i-1], pts[i]));
    }
}

int main(int argc , char* argv[]){
	registerGen(argc, argv , 1);

	int n = atoi(argv[1]);
	int mx = atoi(argv[2]);
    int blcks = atoi(argv[3]);
    assert(mx%blcks == 0);

    int step = mx/blcks, cnt = n/blcks;
    for(int i=0 ; blcks-- ; i += step)
        build(i+1, min(i+step, mx)+1, cnt, rnd.wnext(4, -1));
    
    shuffle(out.begin(), out.end());
    cout << out.size() << "\n";
    for(auto i : out)
        cout << i.first << " " << i.second << "\n";
    return 0;
}
