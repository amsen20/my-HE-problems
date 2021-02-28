#include<bits/stdc++.h>
#include "testlib.h"
using namespace std;

typedef pair<int, int> ii;

const int N = 1000, M=50;

void print(string s){
    cout << s.size() << "\n" << s << "\n";
}

string add_noise(string s, int t, string reg="[a-z]{1}"){
    set<int> st;
    while(st.size() < t)
        st.insert(rnd.next(s.size()));
    for(auto i : st)
        s[i] = rnd.next(reg)[0];
    return s;
}

void build_a(){
    string s = add_noise(string(N, 'a'), rnd.next(M, M+10));
    print(s);
}

void build_b(){
    string pat = rnd.next("[a-z]{50}"), out;
    for(int i=0 ; i<N/M ; i++)
        out += pat;
    out = add_noise(out, rnd.next(M, M+10));
    print(out);
}

string dup_rot(string s){
    string ret;
    for(int i=0 ; i<N/M ; i++){
        string t;
        for(int i=0 ; i<M ; i++){
            int d = int(s[i%s.size()] - '0');
            d ++;
            d %= 4;
            t.push_back(char(d + '0'));
        }
        ret += t;
        s = t;
    }
    return ret;
}

void build_c(){
    string pat = string(M, '0');
    print(dup_rot(pat));
}

void build_d(){
    string pat = string(M, '0');
    print(dup_rot(add_noise(pat, M-10, "[0-3]{1}")));
}

void build_e(){
    int sq = sqrt(N);
    int x = sq/2, y = sq/2, r = 12;
    string s;
    for(int i=0 ; i<sq ; i++)
        for(int j=0 ; j<sq ; j++){
            int dx = i-x, dy = j-y;
            if(dx*dx + dy*dy <= r*r)
                s += "#";
            else
                s += ".";
            // if(j == sq-1)
            //     s += "\n";
        }
    print(s);
}

string str(vector<int> v){
    string s;
    for(auto i : v)
        s.push_back(i ? '1' : '0');
    return s;
}

void build_g(){
    int sz = 10;
    vector<char> v;
    string s;
    for(int i=0 ; i<sz ; i++)
        for(int j=0 ; j<sz ; j++)
            v.push_back(rnd.wnext(2, -1) ? 'a' : 'd');
    int t=10;
    int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
    while(t --){
        for(auto i : v)
            s.push_back(i);
        vector<char> tmp = v;
        for(int i=0 ; i<sz ; i++)
            for(int j=0 ; j<sz ; j++){
                int cnt=0;
                for(int it=0 ; it<8 ; it++){
                    int nx = i+dx[it], ny = j+dy[it];
                    if(nx>=0 && nx<sz && ny>=0 && ny<sz)
                        cnt += (v[nx*sz+ny] == 'a');
                }
                if(v[i*sz+j] == 'a'){
                    if(cnt<2)
                        tmp[i*sz+j] = 'u';
                    else if(cnt<=3)
                        tmp[i*sz+j] = 'a';
                    else
                        tmp[i*sz+j] = 'o';
                    
                }else{
                    if(cnt == 3)
                        tmp[i*sz+j] = 'a';
                    else
                        tmp[i*sz+j] = 'd';   
                }
            }
        v = tmp;
    }
    print(s);
}

void build_h(){
    string s = "ab";
    for(int i=2 ; i<N ; i++){
        char l = s.back() - 'a';
        char ll = s[s.size()-2] - 'a';
        s.push_back('a' + (l + ll)%26);
    }
    print(s);
}

void build_i(){
    print(rnd.next("[a-b]{1000}"));
}

void build_j(){
    print(rnd.next("[a-z]{1000}"));
}

int main(int argc , char* argv[]){
    char c = argv[1][0];
    int n = 1000;
    switch (c){
    case 'a': // all equal some noises
        build_a();
        break;
    case 'b': // a little pattern duplicates
        build_b();
        break;
    case 'c': // rootate (aac bba)
        build_c();
        break;
    case 'd': // noise + rotate
        build_d();
        break;
    case 'e': // circle
        build_e();
        break;
    /*case 'f': // 1000th row of pascal triangle
        build_f();
        break;*/
    case 'g': // 10 frame of game of life
        build_g();
        break;
    case 'h': // fibonacci
        build_h();
        break;
    case 'i': // random a-b
        build_i();
        break;
    case 'j': // random a-z
        build_j();
        break;
    default:
        break;
    }
}

