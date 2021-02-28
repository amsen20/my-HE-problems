#include "graph.h"
#include "testlib.h"
using namespace std;

typedef pair<int, int> ii;

int main(int argc , char* argv[]){
	registerGen(argc, argv , 1);
	int n = atoi(argv[1]);
    bool f = (n>300 && argv[5][0] == 'Y');
    if(f)
        n --;
    int m = atoi(argv[2]);
    if(f)
        m -= 200;
    int c = atoi(argv[3]);
    int w = atoi(argv[4]);
    n -= 2*(c-1);
    m -= 12*(c-1);
    int sz = n/c;
    int ed = m/c;
    setWeightBound(1, w+1);
    WeightedGraph ret(0);
    int lv=-1, lu=-1;
    for(int i=0 ; i<c ; i++){
        WeightedGraph g(sz);
        g = add_tree(g);
        int ced = ed - g.m;
        while(ced --)
            addRandomEdge(g);
        int v, u;
        if(i < c-1){
            v = g.n;
            g.extend(g.n+1);
            int t=0;
            do{
                if(g.add_edge(rnd.next(v), v))
                    t ++;
            }while(t < 3);
            u = g.n;
            g.extend(g.n+1);
            t=0;
            do{
                if(g.add_edge(rnd.next(v), u, w))
                    t ++;
            }while(t < 3);
        }
        int dn = ret.n;
        assert(concatGraphs(ret, g));
        v += dn;
        u += dn;
        if(lv == -1){
            lv = v;
            lu = u;
            continue;
        }
        int t=0;
        do{
            if(ret.add_edge(lv, rnd.wnext(dn, ret.n-1, -1)))
                t++;
        }while(t<3);
        t = 0;
        do{
            if(ret.add_edge(lu, rnd.wnext(dn, ret.n-1, -1), w))
                t++;
        }while(t<3);
        lv = v;
        lu = u;
    }
    if(f){
        int ls = ret.n;
        ret.extend(ret.n+1);
        int t=200;
        while(t)
            if(ret.add_edge(rnd.wnext(ret.n-1, 3), ls))
                t --;
    }
    vector<int> p = range(ret.n);
    shuffle(p.begin()+1, p.end()-1);
    print(ret);
}
