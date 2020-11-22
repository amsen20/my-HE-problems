#include<bits/stdc++.h>
#include "testlib.h"
using namespace std;

const int MAXA = 10000*10000, MAXL = 1000;

int main(int argc , char* argv[])
{
	registerValidation(argc, argv);

	int a = inf.readInt(1 , MAXA , "a");
	inf.readSpace();
	int b = inf.readInt(1 , MAXA , "b");
	inf.readSpace();
	int l = inf.readInt(1 , MAXL , "l");
    inf.readEoln();
	inf.readEof();
    ensuref(a < b, "a should be less than b");
}
