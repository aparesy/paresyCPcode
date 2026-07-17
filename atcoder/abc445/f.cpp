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
#define vvi vector<vector<int>>

const int E2 = 100, E3 = 1000, E4 = 10000, E5 = 100000, E6 = 1000000, E9 = 1000000000;
const ll E18 = 1ll * E9 * E9;
const int FFT_MOD = 998244353;
const int SIMPLE_MOD = E9 + 7;
mt19937 rng(time(0));
 
 
#define int ll
 
const int MAXN = 2e6 + 10;
int n;

vvi prod(vvi& a, vvi& b){
    vvi tab(n, vi(n));
    forn(i,n){
        forn(j,n){
            tab[i][j]=LLONG_MAX;
            forn(k,n){
                tab[i][j]=min(tab[i][j], a[i][k]+b[k][j]);
            }
        }
    }
    return tab;
}

void solve(){
    int k;
    cin>>k;
    vvi tab(n, vi(n));
    forn(i,n){
        forn(j,n){
            cin>>tab[i][j];
        }
    }

    vvi cur(n, vi(n, LLONG_MAX-1e12));
    forn(i,n) cur[i][i]=0;
    while(k){
        if (k&1){
            cur = prod(cur, tab);
        }
        tab = prod(tab,tab);
        k>>=1ll;
    }
    // forn(i,n){
    //     forn(j,n){
    //         cout<<cur[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    forn(i,n){
        cout<<cur[i][i]<<"\n";
    }
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