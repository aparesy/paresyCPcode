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
 
const int MAXN = 3e3 + 10;
int n,x,s;
string tab;

int simulate(int k){
    int tot=0;
    int tables=0;
    int tota=0;
    forn(i,n){
        if (tab[i]=='I'){
            if (tables<x){
                tables++;
                tot++;
            }
        }
        if (tab[i]=='A'){
            if (tota<k && tables<x){
                tota++;
                tables++;
                tot++;
            }
            else if (tot<tables*s){
                tot++;
            }
        }
        if (tab[i]=='E'){
            if (tot<tables*s) tot++;
        }
    }
    return tot;
}

void solve(){
    cin>>tab;
    int l=-1;
    int r=x+1;
    while(r-l>1){
        int m=(r+l)/2;
        if (simulate(m)<simulate(m+1)){
            l=m;
        }
        else r=m;
    }
    cout<<simulate(r)<<"\n";
}

signed main() {
    #ifdef DEBUG
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int ttt; cin>>ttt;
    while (cin>>n>>x>>s) solve();
}