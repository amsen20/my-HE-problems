#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int N = 110;

string s[N];
int c[N], n, v;

bool isdigit(char c){
    return (c >= '0' && c <= '9');
}

bool isop(char c){
    return (c == '&' || c == '|' || c == '!' || c == '^');
}

bool valid(char c){
    if(isdigit(c))
        return true;
    if(isop(c))
        return true;
    if(c == '(' || c == ')')
        return true;
    return false;
}

void bad(){
    throw "bad expression.";
}

int get_num(const string &exp, int l, int r){
    int d=0;
    for(int i=l ; i<r ; i++){
        d *= 10;
        d += exp[i] - '0';
        if(d > v)
            bad();
    }
    return d;
}

int eval(int f, int s, char op){
    if(op == '&')
        return f&s;
    if(op == '^')
        return f^s;
    if(op == '|')
        return f|s;
    bad();
    return -1;
}

int calc(string env, string exp){
    bool alldigit = true;
    for(auto c : exp)
        alldigit &= isdigit(c);
    if(alldigit)
        return env[get_num(exp, 0, exp.size())] - '0';

    vector<int> vec, vals;
    for(int i=0 ; i<exp.size() ; i++){
        char c = exp[i];
        if(!valid(c))
            bad();
        if(c == '('){
            vec.push_back(i);
            continue;
        }
        if(c == ')'){
            if(vec.empty())
                bad();
            int l = vec.back()+1, r=i;
            vec.pop_back();
            if(r == l)
                bad();
            if(exp[l] == '!'){
                if(isdigit(exp[l+1])){
                    int d=get_num(exp, l+1, r);
                    vals.push_back(1 - int(env[d] - '0'));
                    continue;
                } else if(exp[l+1] == '('){
                    if(vals.empty())
                        bad();
                    int d = 1 - vals.back();
                    vals.pop_back();
                    vals.push_back(d);
                    continue;
                } else
                    bad();
            }
            int ind=-1, sum = 0;
            for(int i=l ; i<r ; i++){
                if(exp[i] == '(')
                    sum ++;
                if(exp[i] == ')')
                    sum --;
                if(isop(exp[i]) && !sum){
                    if(ind != -1)
                        bad();
                    ind = i;
                }
            }
            if(ind == l || ind == r-1)
                bad();
            int fr=-1, sc=-1;
            
            { // second operand
                if(isdigit(exp[ind+1]))
                    sc = env[get_num(exp, ind+1, r)] - '0';
                else if(exp[ind+1] == '('){
                    if(vals.empty())
                        bad();
                    sc = vals.back();
                    vals.pop_back();
                } else 
                    bad();
            }

            { // first operand
                if(isdigit(exp[ind-1]))
                    fr = env[get_num(exp, l, ind)] - '0';
                else if(exp[ind-1] == ')'){
                    if(vals.empty())
                        bad();
                    fr = vals.back();
                    vals.pop_back();
                } else 
                    bad();
            }

            int res = eval(fr, sc, exp[ind]);
            vals.push_back(res);
        }
    }
    if(vals.size() != 1)
        bad();
    return vals.back();
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    try{
        cin >> n >> v;
        for(int i=0 ; i<n ; i++)
            cin >> s[i] >> c[i];
        string expr;cin >> expr;
        if(expr.size() > 3e4)
            bad();
        int ops=0;
        for(auto c : expr)
            if(isop(c))
                ops ++;
        if(2*ops > 3*n*v)
            bad();
        int cnt=0;
        for(int i=0 ; i<n ; i++)
            cnt += (calc(s[i], expr) == c[i]);
        double occ = double(cnt)/n;
        occ *= occ;
        double sc = (exp(occ) - 1)/(exp(1) - 1) * (1 - ops/(1.5*n*v)) * 5;
        cout << fixed << setprecision(7) << sc << "\n";
    } catch(string s){
        assert(false);
        // cout << "0\n";
        // return 0;
    }
}
