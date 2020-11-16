/*
    author:  Maksim1744
    created: 17.10.2020 21:46:58
*/

#include <bits/stdc++.h>

using namespace std;

#define ll   long long
#define ld   long double

#define mp   make_pair
#define pb   push_back
#define eb   emplace_back

#define sum(a)     ( accumulate ((a).begin(), (a).end(), 0ll))
#define mine(a)    (*min_element((a).begin(), (a).end()))
#define maxe(a)    (*max_element((a).begin(), (a).end()))
#define mini(a)    ( min_element((a).begin(), (a).end()) - (a).begin())
#define maxi(a)    ( max_element((a).begin(), (a).end()) - (a).begin())
#define lowb(a, x) ( lower_bound((a).begin(), (a).end(), (x)) - (a).begin())
#define uppb(a, x) ( upper_bound((a).begin(), (a).end(), (x)) - (a).begin())

template<typename T>             vector<T>& operator--            (vector<T>& v){for (auto& i : v) --i;            return  v;}
template<typename T>             vector<T>& operator++            (vector<T>& v){for (auto& i : v) ++i;            return  v;}
template<typename T>             istream& operator>>(istream& is,  vector<T>& v){for (auto& i : v) is >> i;        return is;}
template<typename T>             ostream& operator<<(ostream& os,  vector<T>& v){for (auto& i : v) os << i << ' '; return os;}
template<typename T, typename U> istream& operator>>(istream& is, pair<T, U>& p){is >> p.first >> p.second;        return is;}
template<typename T, typename U> ostream& operator<<(ostream& os, pair<T, U>& p){os << p.first << ' ' << p.second; return os;}
template<typename T, typename U> pair<T,U> operator-(pair<T,U> a, pair<T,U> b){return mp(a.first-b.first, a.second-b.second);}
template<typename T, typename U> pair<T,U> operator+(pair<T,U> a, pair<T,U> b){return mp(a.first+b.first, a.second+b.second);}
template<typename T, typename U> void umin(T& a, U b){if (a > b) a = b;}
template<typename T, typename U> void umax(T& a, U b){if (a < b) a = b;}

#ifdef HOME
#define TAG_LENGTH       25
#define LR_LEFT          left
#define LR_RIGHT         right
#define LR_VALUE         value
#define LR_SECOND_VALUE  mn
#include "C:/C++ libs/print.cpp"
#else
#define showl            42;
#define shows            42;
#define show(...)        42;
#define showm(...)       42;
#define showt(...)       42;
#define printTree(...)   42;
#define printGraph(...)  42;
#define printLRTree(...) 42;
#define printMatrix(...) 42;
#define printWGraph(...) 42;
#define debug     if (false)
#endif

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    vector<vector<pair<int, int>>> g(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        int w;
        cin >> u >> v;
        cin >> w;
        --u; --v;
        g[u].eb(v, w);
        g[v].eb(u, w);
    }

    vector<bool> u(n, false);
    vector<vector<int>> cnt(n, vector<int>(2, 0));
    vector<vector<int>> xr(n, vector<int>(2, 0));

    function<void(int)> dfs = [&](int v) {
        u[v] = true;
        vector<pair<int, int>> children;
        for (auto [k, w] : g[v]) {
            if (!u[k]) {
                dfs(k);
                children.eb(k, w);
            }
        }
        int cnt_odd = 0, cnt_even = 0;
        int xr_odd = 0;
        vector<int> ev;
        for (auto [k, w] : children) {
            if (cnt[k][1] == 1) {
                cnt_odd++;
                xr_odd ^= xr[k][1];
            } else {
                ev.pb(k);
                cnt_even++;
            }
        }

        if (v == 0) {
            show(cnt_odd, cnt_even, xr_odd, ev);
        }

        if (cnt_even >= 2) {
            xr[v][0] = 0;
            cnt[v][0] = 0;
        } else if (cnt_even == 1) {
            xr[v][0] = xr[ev[0]][1];
            cnt[v][0] = 0;
        } else if (cnt_even == 0) {
            xr[v][0] = xr_odd;
            cnt[v][0] = 1;
        }

        if (v == 0) show(xr[v][0]);

        for (auto [k, w] : children) {
            if (cnt_even - (cnt[k][1] == 0) == 0) {
                int odd_here = 0;
                if (cnt[k][1] % 2 == 1)
                    odd_here = xr[k][1];
                xr[v][1] ^= xr[k][0] ^ (w * cnt[k][0]) ^ ((xr_odd ^ odd_here) * cnt[k][0]);
                cnt[v][1] += cnt[k][0];
            } else {
                if (cnt[k][0] == 1 && cnt_even - (cnt[k][1] == 0) == 1) {
                    for (auto u : ev) {
                        if (u != k)
                            xr[v][1] ^= xr[u][1];
                    }
                }
            }
            if (v == 0) show(k, xr[v][1]);
        }


        cnt[v][1] += cnt[v][0];
        cnt[v][1] %= 2;
        cnt[v][0] %= 2;
        xr[v][1] ^= xr[v][0];
    };
    dfs(0);

    show(cnt);
    show(xr);

    cout << xr[0][1] << '\n';

    return 0;
}

