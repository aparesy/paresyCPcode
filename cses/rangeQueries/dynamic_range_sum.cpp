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
 
const int MAXN = 2e5 + 10;
int n,q;

struct segtree{
    int add(int a, int b){return a^b;}
    int neutral=0;
    int t[4*MAXN];

    void update(int v, int tl, int tr, int pos, int val){
        if (tl==tr){
            t[v] = val;
            return;
        }
        int m=(tl+tr)/2;
        if (m>=pos) update(2*v,tl,m,pos,val);
        else update(2*v+1,m+1,tr,pos,val);
        t[v] = add(t[2*v], t[2*v+1]);
    }
    
    void build(vi& tab){
        forn(i,n) update(1,0,n-1,i,tab[i]);
    }

    int query(int v, int tl, int tr, int l, int r){
        if (tl>tr) return neutral;
        if (tl>=l && tr<=r) return t[v];
        int m=(tl+tr)/2;
        if (r<=m) return query(2*v,tl,m,l,r);
        if (l>=m+1) return query(2*v+1,m+1,tr,l,r);
        return add(query(2*v,tl,m,l,r), query(2*v+1,m+1,tr,l,r));
    }
};

void solve(){
    vi tab(n);
    forn(i,n) cin>>tab[i];
    segtree sg;
    sg.build(tab);
    forn(i,q){
        int a,b;
        cin>>a>>b;
        cout<<sg.query(1,0,n-1,a-1,b-1)<<"\n";
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