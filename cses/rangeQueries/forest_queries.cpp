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
#define vvi vector<vector<int>>
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
int n,q;

void solve(){
    vvi grid(n,vi(n));
    forn(i,n){
        string s;
        cin>>s;
        forn(j,n){
            grid[i][j]=(s[j]=='*');
        }
    }  
    vvi tab(n,vi(n));
    forn(i,n){
        tab[i][0] = grid[i][0] + (i?tab[i-1][0]:0);
        tab[0][i] = grid[0][i] + (i?tab[0][i-1]:0);
    }
    forn(i,n-1){
        forn(j,n-1){
            tab[i+1][j+1]=tab[i+1][j]+tab[i][j+1]-tab[i][j]+grid[i+1][j+1];
        }
    }
    forn(i,q){
        int x,xx,y,yy;
        cin>>y>>x>>yy>>xx;
        x--;y--;xx--;yy--;
        tie(y,yy)=make_pair(min(y,yy), max(y,yy));
        tie(x,xx)=make_pair(min(x,xx), max(x,xx));
        cout<<tab[yy][xx]-(x==0?0:tab[yy][x-1])-(y==0?0:tab[y-1][xx])+(x*y==0?0:tab[y-1][x-1])<<"\n";
    } 
}

signed main() {
    #ifdef DEBUG
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while (cin>>n>>q) solve();
}