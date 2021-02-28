#include<bits/stdc++.h>
#include "testlib.h"
using namespace std;

const int small = 100, medium = 10000, large = 100000000;
const int MAXL = 1000;

vector<string> getPat(int id){
    vector<string> ret;
    if(id == 1){
        ret.push_back("##.##");
        ret.push_back("#...#");
        ret.push_back(".....");
        ret.push_back("#...#");
        ret.push_back("##.##");
    }
    if(id == 2){
        ret.push_back("###.");
        ret.push_back("#.#.");
        ret.push_back("..##");
        ret.push_back("..#.");
    }
    if(id == 3){
        ret.push_back("##.");
        ret.push_back("#..");
        ret.push_back("...");
    }
    if(id == 4){
        ret.push_back("##.##");
        ret.push_back("##.##");
        ret.push_back(".....");
        ret.push_back("##.##");
        ret.push_back("##.##");
    }
    if(id == 5){
        ret.push_back("#.#.#");
        ret.push_back("..#..");
        ret.push_back("#####");
        ret.push_back("..#..");
        ret.push_back("#.#.#");        
    }
    return ret;
}

int main(int argc , char* argv[]){
    registerGen(argc, argv , 1);
    int n = atoi(argv[1]);
    int m = atoi(argv[2]);
    int patId = atoi(argv[3]);
    auto pat = getPat(patId);
    cout << n << " " << m << "\n";
    for(int i=0 ; i<n ; i++)
        for(int j=0 ; j<m ; j++){
            cout << pat[i%pat.size()][j%pat[0].size()];
            if(j == m-1)
                cout << "\n";
        }
}
