#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
 
#ifdef DEBUG
 
#define var(x) cerr << #x << ": " << x << '\n';
#define range(a, b) cerr << #a << ", " << #b << ": "; for (auto _it = a; _it != b; ++_it) cerr << *_it << ' '; cerr << '\n';
#else
#define var(x)
#define range(a, b)
#define cerr if (false) cerr
#endif
 
#define vi vector<int>
#define vii vector<pii>
#define forn(i, n) for (int i = 0; i < n; i++) 
#define F first
#define S second
#define T(x, i) get<i>(x)
#define pii pair<int, int>
#define all(v) v.begin(), v.end()
#define rep(i,a,b) for (int i = a; i < b; i++)
#define sz(v) int(v.size())

const int E2 = 100, E3 = 1000, E4 = 10000, E5 = 100000, E6 = 1000000, E9 = 1000000000;
const ll E18 = 1ll * E9 * E9;
const int FFT_MOD = 998244353;
const int SIMPLE_MOD = E9 + 7;
mt19937 rng(time(0));
 
 
#define int ll
 
const int MAXN = 2e6 + 10;
int n;
vector<string> grid;

void reduce(vii& tab){
    int minscore='Z'+1;
    vii acc;
    for (auto [a,b] : tab){
        if (grid[a][b]<minscore){
            minscore=grid[a][b];
            acc.clear();
            acc.push_back({a,b});
        }
        else if (grid[a][b]==minscore){
            acc.push_back({a,b});
        }
    }
    tab.clear();
    tab=acc;
}

void solve(){
    bool ok[n][n];
    bool vu[n][n];
    grid.resize(n);
    forn(i,n) cin>>grid[i];
    vii cd;
    cd.push_back({0,0});
    forn(i,n){
        forn(j,n){
            ok[i][j]=0;
            vu[i][j]=0;
        }
    }
    ok[0][0]=1;
    vu[0][0]=1;
    forn(i,2*(n-1)){
        vii tmp;
        for (auto [a,b] : cd){
            if (a!=n-1 && !vu[a+1][b]){
                tmp.push_back({a+1,b});
                vu[a+1][b]=true;
            }
            if (b!=n-1 && !vu[a][b+1]){
                tmp.push_back({a,b+1});
                vu[a][b+1]=true;
            }
        }
        reduce(tmp);
        cd.clear();
        cd=tmp;
        for (auto [a,b] : cd){
            ok[a][b]=true;
        }
    }

    vector<char> res;
    int i=n-1;
    int j=n-1;
    forn(i,n){
        range(ok[i], ok[i]+n);
    }
    while(i>0 || j>0){
        res.push_back(grid[i][j]);
        var(i);
        var(j);
        if (i>0 && ok[i-1][j]){
            i--;
        }
        else j--;
    }
    res.push_back(grid[0][0]);
    reverse(all(res));
    for (auto x : res) cout<<x;
}

signed main() {
    #ifdef DEBUG
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while (cin>>n) solve();
}