#include "testlib.h"
using namespace std;

typedef long long ll;
#define int ll

const int MAXOUT = 1e18;

int gcd(int a, int b){
    if(a > b)
        swap(a, b);
    if(a == 0)
        return b;
    return gcd(b%a, a);
}

signed main(signed argc, char * argv[])
{
	registerChecker("fs", argc, argv);
    int a = inf.readInt(), b = inf.readInt(), l = inf.readInt();
    vector<int> up, dn;
    up.push_back(b);
    dn.push_back(a);
    for(int i=0 ; i<l ; i++){
        int f = ouf.readLong(1, MAXOUT, "up frac");
        ouf.readSpace();
        int s = ouf.readLong(1, MAXOUT, "down frac");
        if(f >= s)
            quitf(_wa, "The fracs must be less than 1");
        ouf.readEoln();
        up.push_back(f);
        dn.push_back(s);
    }
    for(auto &i : up)
        for(auto &j : dn){
            int g = gcd(i, j);
            i /= g;
            j /= g;
        }
    for(auto i : up)
        if(i != 1)
            quitf(_wa, "The multiplication of fracs is not a/b!");
    for(auto i : dn)
        if(i != 1)
            quitf(_wa, "The multiplication of fracs is not a/b!");
    quitf(_ok, "The multiplication is correct.");
}
