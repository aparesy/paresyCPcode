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
int n;

struct segtree{
    vi t;
    void build(){
        t.clear();
        t=vi(4*n);
    }
    int query(int v,int tl, int tr, int l, int r){
        if (l>r) return 0;
        if (l==tl && tr==r) return t[v];
        int m=(tl+tr)/2;
        return ((query(2*v,tl,m,l,min(r,m))+query(2*v+1,m+1,tr,max(l,m+1),r))%SIMPLE_MOD);
    }
    void update(int v, int tl, int tr, int pos, int val){
        if (tl==tr){
            t[v]=val;
            return;
        }
        int m=(tl+tr)/2;
        if (pos<=m) update(2*v,tl,m,pos,val);
        else update(2*v+1,m+1,tr,pos,val);
        t[v]=(t[2*v]+t[2*v+1])%SIMPLE_MOD;
    }
};

void solve(){
    vi tab(n);
    forn(i,n) cin>>tab[i];
    set<pii> st;
    forn(i,n){
        st.insert({tab[i], -i});
    }
    segtree sg;
    sg.build();
    for (auto [a,b] : st){
        b=-b;
        int x=sg.query(1,0,n-1,0,b);
        x++;
        x%=SIMPLE_MOD;
        var(x);
        sg.update(1,0,n-1,b,x);
    }
    cout<<sg.query(1,0,n-1,0,n-1);
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