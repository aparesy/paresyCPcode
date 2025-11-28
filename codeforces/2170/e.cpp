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
 

int mod=998244353;
const int MAXN = 2e6 + 10;
int n,m;
pii segs[MAXN];
int pow2[MAXN];

void solve(){
    cin>>n>>m;
    forn(i,m) cin>>segs[i].first>>segs[i].second;
    sort(segs, segs+m);
    int tot=0;
    int i=0;
    int nbNoSegs=0;
    int lastRight=-1;
    while(i<m){
        nbNoSegs+=segs[i].first-lastRight-1;
        tot++;
        int curRight=segs[i].second;
        while(i<m && segs[i].first<=curRight){
            i++;
            curRight=max(curRight, segs[i].second);
        }
        lastRight=curRight;
    }
    nbNoSegs+=n-1-lastRight;
    int tmp=0;
    tmp=pow2[n];
    tmp-=pow2[tot]*pow2[nbNoSegs];
    tmp%=mod;
    if (tmp<0) tmp+=mod;
    cout<<tmp<<"\n";
}

signed main() {
    #ifdef DEBUG
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin.tie(0);
    pow2[0]=1;
    forn(i,MAXN){
        if (!i) continue;
        pow2[i]=2ll*pow2[i-1];
        if (pow2[i]>=mod) pow2[i]-=mod;
    }
    int _t;
    cin >> _t;
    rep(i,0,_t) {
        solve();
    }
}