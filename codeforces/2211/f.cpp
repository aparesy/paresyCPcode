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
const int SIMPLE_MOD = 676767677;
mt19937 rng(time(0));
 
 
#define int ll
 
const int MAXN = 2e6 + 10;
int n,m;
int fact[MAXN];
int invfact[MAXN];
//int nb[MAXN];
int cumsum[MAXN];

int inv(int a){
    return a<=1?a:SIMPLE_MOD-(SIMPLE_MOD/a)*inv(SIMPLE_MOD%a) % SIMPLE_MOD;
}

int binom(int a, int b){
    int tmp=fact[b]*invfact[a]%SIMPLE_MOD;
    return (tmp*invfact[b-a])%SIMPLE_MOD;
}

void dfs(vi& tab, int a, int b, int k){
    if (a>b) return;
    if (a==b){
        tab[a-1]=k;
        return;
    }
    int mid=(a+b)/2;
    tab[mid-1]=k;
    dfs(tab, a,mid-1,k+1);
    dfs(tab, mid+1,b,k+1);
}

void dfs2(vi& howmuch, int a, int b, int last, int vallast){
    if (a>b) return;
    int mid=(a+b)/2;
    howmuch[mid-1]=vallast-binom(n-abs(mid-last), n-abs(mid-last)+m-1);
    howmuch[mid-1]%=SIMPLE_MOD;
    if (howmuch[mid-1]<0) howmuch[mid-1]+=SIMPLE_MOD;
    last=mid;
    vallast=howmuch[mid-1];
    if (a==b) return;
    dfs2(howmuch, a, mid-1, last, vallast);
    dfs2(howmuch, mid+1, b, last, vallast);
}

int incr_seq(int a, int b){
    return binom(a, a+b-1);
}

void solve(){
    //nb[1] = 1;
    vi tab(n);
    dfs(tab,1,n,1);
    vi howmuch(n);
    //howmuch[i] = everyone for center, everyone minus
    dfs2(howmuch, 1, n, (1+n)/2, (2ll*incr_seq(n,m))%SIMPLE_MOD);
    int tot=0;
    forn(i,n){
        tot+=tab[i]*howmuch[i];
        tot%=SIMPLE_MOD;
    }
    cout<<tot<<"\n";
}

signed main() {
    #ifdef DEBUG
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    fact[0]=1;
    forn(i,MAXN-1){
        fact[i+1]=(i+1ll)*fact[i];
        fact[i+1]%=SIMPLE_MOD;
        invfact[i+1]=inv(fact[i+1]);
    }
    invfact[0]=1;
    int ttt; cin>>ttt;
    while (cin>>n>>m) solve();
}