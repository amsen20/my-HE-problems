#include<bits/stdc++.h>
#include "testlib.h"
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 1e5 + 20;
int n , m;

int main(int argc , char* argv[])
{
	registerGen(argc, argv , 1);

	n = rnd.next(atoi(argv[1]) , atoi(argv[2]));
	m = rnd.next(atoi(argv[3]) , atoi(argv[4]));
	printf("%d %d\n", n, m);
}



