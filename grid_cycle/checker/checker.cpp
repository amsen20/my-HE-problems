#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 110;

string matIn[N], mat[N];
int par[N*N];

int root(int v){
    return par[v] = (v == par[v] ? v : root(par[v]));
}

void merge(int v, int u){
    v = root(v);
    u = root(u);
    par[v] = u;
}

signed main(signed argc, char * argv[]){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
    int cnt=0, used=0;
    int n, m;cin >> n >> m;
    int score = 3;
    if(n == 100 && m == 50)
        score ++;
    for(int i=0 ; i<n ; i++)
        cin >> matIn[i];
    for(int i=0 ; i<n ; i++){
        cin >> mat[i];
        assert(mat[i].size() == matIn[i].size());
        for(int j=0 ; j<matIn[i].size() ; j++){
            cnt += (matIn[i][j] == '.');
            if(matIn[i][j] == mat[i][j])
                continue;
            assert(matIn[i][j] != '#');
            assert(mat[i][j] == '#');
            used ++;
        }
    }
    assert(3*used <= cnt);
    int ed=0;
    for(int i=0 ; i<n ; i++)
        for(int j=0 ; j<m ; j++)
            par[i*m+j] = i*m+j;
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    cnt = 0;
    for(int i=0 ; i<n ; i++)
        for(int j=0 ; j<m ; j++)
            if(mat[i][j] == '.'){
                cnt ++;
                for(int it=0 ; it<4 ; it++){
                    int nx = i+dx[it], ny = j+dy[it];
                    if(nx<0 || nx>=n || ny<0 || ny>=m || mat[nx][ny] == '#')
                        continue;
                    merge(i*m+j, nx*m+ny);
                    ed ++;
                }
            }
    ed /= 2;
    set<int> st;
    for(int i=0 ; i<n ; i++)
        for(int j=0 ; j<m ; j++)
            if(mat[i][j] == '.')
                st.insert(root(i*m+j));
    assert(cnt - (int)st.size() == ed);
    cout << score << "\n";
}
