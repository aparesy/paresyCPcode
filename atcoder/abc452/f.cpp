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
 
const int MAXN = 7e5;
int n;

struct segtree{
    vi seg;
    void init(){
        seg.assign(4*MAXN,0);
    }
    void update(int v, int tl, int tr, int pos, int val){
        if (tl==tr){
            seg[v]=val;
            return;
        }
        int tm=(tl+tr)/2;
        if (pos<=tm) update(2*v,tl,tm,pos,val);
        else update(2*v+1,tm+1,tr,pos,val);
        seg[v]=seg[2*v]+seg[2*v+1];
    }
    int query(int v, int tl, int tr, int l, int r){
        if (l>r) return 0;
        if (tl==l && tr==r) return seg[v];
        int tm=(tl+tr)/2;
        return query(2*v,tl,tm,l,min(r,tm))+query(2*v+1,tm+1,tr,max(l,tm+1),r);
    }
};

void solve(){
    int k;
    cin>>k;
    vi tab(n);
    forn(i,n){
        cin>>tab[i];
    }
    int inv=0;
    segtree sg;
    sg.init();
    int cur=0;
    int tot=0;
    while(cur<n && inv<k){
        inv+=sg.query(1,0,n-1,tab[cur]-1,n-1);
        sg.update(1,0,n-1,tab[cur]-1,1);
        cur++;
    }
    
    for (int i=0;i<n;i++){
        sg.update(1,0,n-1,tab[i]-1,0);
        inv-=sg.query(1,0,n-1,0,tab[i]-1);
        while(cur<n && inv<k){
            inv+=sg.query(1,0,n-1,tab[cur]-1,n-1);
            sg.update(1,0,n-1,tab[cur]-1,1);
            cur++;
        }
        while(cur<n && inv==k){
            tot++;
            inv+=sg.query(1,0,n-1,tab[cur]-1,n-1);
            sg.update(1,0,n-1,tab[cur]-1,1);
            cur++;
        }
        if (inv==k) tot++;
    }
    cout<<tot;  
}


signed main() {
    #ifdef DEBUG
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //int ttt; cin>>ttt;
    while (cin>>n) solve();
}