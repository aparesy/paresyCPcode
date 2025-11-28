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
int n,m;
pii t[4*MAXN];
int inf=1e12;


void upd(int v, int tl, int tr, int pos, int x){
    if (tl==tr){
        t[v].first=x;
        t[v].second=1;
    }
    else{
        int tm=(tl+tr)/2;
        if (tm>=pos) upd(2*v,tl,tm,pos,x);
        else upd(2*v+1,tm+1,tr,pos,x);
        auto [a,b]=t[2*v];
        auto [c,d]=t[2*v+1];
        if (a==c){
            t[v].first=a;
            t[v].second=b+d;
        }
        else{
            t[v].first=min(a,c);
            t[v].second=(a<c)?b:d;
        }
    }
}

pii get(int v, int tl, int tr, int l, int r){
    if (l>r) return {inf,0};
    if (l <= tl && tr <= r) return t[v]; 
    int tm=(tl+tr)/2;
    pii res;
    auto [a,b] = get(2*v, tl, tm, l, min(r, tm));
    auto [c,d] = get(2*v+1, tm+1, tr, max(l, tm+1), r);
        if (a==c){
        res.first=a;
        res.second=b+d;
    }
    else{
        res.first=min(a,c);
        res.second=(a<c)?b:d;
    }
    return res;
}

void solve(){
    cin>>n>>m;
    forn(i,4*MAXN) t[i]={inf,1};
    forn(i,n){
        int x; cin>>x; 
        upd(1,0,n-1,i,x);
    }
    forn(i,m){
        int type;
        cin>>type;
        if (type==1){
            int i,v;
            cin>>i>>v;
            upd(1,0,n-1,i,v);
        }
        else{
            int l,r;
            cin>>l>>r;
            pii tmp=get(1,0,n-1,l,r-1);
            cout<<tmp.first<<" "<<tmp.second<<"\n";
        }
    }
}

signed main() {
    #ifdef DEBUG
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin.tie(0);
    solve();
}