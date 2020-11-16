#include<bits/stdc++.h>
#include "testlib.h"
using namespace std;

typedef pair<int, int> ii;
typedef pair<ii, int> iii;

const int N = 1e6+100;

int p[N];

vector<iii> shuffle_vertices(int n, const vector<iii> &eds){
    vector<iii> ret;
    for(int i=0 ; i<n ; i++)
        p[i] = i;
    shuffle(p, p+n);
    for(auto e : eds)
        ret.push_back(iii(ii(p[e.first.first], p[e.first.second]), e.second));
    shuffle(ret.begin(), ret.end());
    return ret;
}

vector<iii> eds;

void build_graph(vector<int> v, int m, int w){
    int deg = (m + (int)v.size() - 1) / v.size();
    for(int i=1 ; i<v.size() ; i++){
        int cur = min(m, deg);
        if(i+1 == v.size())
            cur = m;
        cur = min(cur, i);
        m -= cur;
        set<int> st;
        do{
            int d = rnd.next(i);
            st.insert(d);
        }while(st.size() < cur);
        int ver = v[i];
        for(auto j : st){
            int u = v[j];
            assert(ver != u);
            eds.push_back(iii(ii(ver, u), w));
        }
    }
}

int main(int argc , char* argv[]){
	registerGen(argc, argv , 1);

	int n = atoi(argv[1]);
    int m = atoi(argv[2]);
    int cnt_block = atoi(argv[3]);
    char hv = argv[4][0];

    int block = (n+cnt_block-1) / cnt_block;
    int block_ed = (m+cnt_block-1) / cnt_block;
    
    vector<int> cmps;

    int all = 0;

    for(int i=0 ; i<n ; i+=block){
        int cur = rnd.next(0, min(block_ed, m));
        m -= cur;
        vector<int> cur_cmp;
        for(int j=i ; j<n && j<i+block ; j++)
            cur_cmp.push_back(j);
        cmps.push_back(cur_cmp[rnd.next(cur_cmp.size())]);
        build_graph(cur_cmp, cur, 1);
        if(cur_cmp.size() % 2 == 0)
            all = 1-all;
    }

    build_graph(cmps, m, 0);

    if(all == 1)
        assert(false);

    if(hv == 't')
        for(auto &i : eds){
            if(i.second == 1)
                i.second = 0;
            break;
        }

   eds = shuffle_vertices(n, eds);

    cout << n << " " << eds.size() << "\n";
    for(auto e : eds)
        cout << e.first.first+1 << " " << e.first.second+1 << " " << e.second << "\n";
}

