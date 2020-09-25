#include<bits/stdc++.h>
#include "testlib.h"
using namespace std;

const int small = 100, medium = 10000, large = 100000000;
const int MAXL = 1000;

int main(int argc , char* argv[])
{
	registerGen(argc, argv , 1);

	char size = argv[1][0];
    char type = argv[2][0];
	int a=0, b=0, l, r;
    switch(size){
        case 's':
            l = 1;
            r = small;
            break;
        case 'm':
            l = small+1;
            r = medium;
            break;
        case 'l':
            l = medium+1;
            r = large;
            break;
    }
    while(a == b){
        a = rnd.next(l, r);
        b = rnd.next(l, r);
        if(a>b)
            swap(a, b);
    }
    int len = rnd.next(1, MAXL);
    if(type == 's' && b-a >= len && len > 1)
        a = b - rnd.next(1, len);
    if(type == 'f')
        len = rnd.next(1, len);
    cout << a << " " << b << " " << len << "\n";
}



