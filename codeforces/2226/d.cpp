#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
 
#ifdef DEBUG
 
// #define var(x) cerr << #x << ": " << x << '\n';
#define var(x) cerr << #x << ": " << x.first<<" "<<x.second << '\n';
#define range(a, b) cerr << #a << ", " << #b << ": "; for (auto _it = a; _it != b; ++_it) cerr << *_it << ' '; cerr << '\n';
#else
#define var(x)
#define range(a, b)
#define cerr if (false) cerr
#endif
 
#define vi vector<int>
#define vii vector<pii>
#define vvi vector<vector<int>>
#define vvii vector<vii>
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

void solve(){
    vi tab(n);
    forn(i,n) cin>>tab[i];
    pii oddlim = {-1,INT_MAX};
    pii evenlim = {-1,INT_MAX};
    forn(i,n){
        if (tab[i]%2){
            oddlim.first=max(oddlim.first, tab[i]);
            oddlim.second=min(oddlim.second, tab[i]);
        }
        else{
            evenlim.first=max(evenlim.first, tab[i]);
            evenlim.second=min(evenlim.second, tab[i]);
        }
    }
    if (oddlim.first==-1 || evenlim.first==-1){
        forn(i,n-1){
            if (tab[i]>tab[i+1]){
                cout<<"No\n";
                return;
            }
        }
        cout<<"Yes\n";
        return;
    }
    pii curoddlim = {-1,INT_MAX};
    pii curevenlim = {-1,INT_MAX};
    forn(i,n){
        if (tab[i]%2){
            curoddlim.first=max(curoddlim.first, tab[i]);
            curoddlim.second=min(curoddlim.second, tab[i]);
            // if (tab[i]>evenlim.first && curoddlim.second < evenlim.second){
            //     cout<<"No\n";
            //     return;
            // }
            if (tab[i] < evenlim.second && curoddlim.first > evenlim.first){
                cout<<"No\n";
                return;
            }
        }
        else{
            curevenlim.first=max(curevenlim.first, tab[i]);
            curevenlim.second=min(curevenlim.second, tab[i]);
            // if (tab[i]>oddlim.first && curevenlim.second < oddlim.second){
            //     cout<<"No\n";
            //     return;
            // }
            if (tab[i] < oddlim.second && curevenlim.first > oddlim.first){
                cout<<"No\n";
                return;
            }
        }
    }
    cout<<"Yes\n";
}

signed main() {
    #ifdef DEBUG
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int ttt; cin>>ttt;
    while (cin>>n) solve();
}