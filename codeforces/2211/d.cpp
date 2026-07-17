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
int fact[MAXN];
int invfact[MAXN];

int inv(int a){
    return a<=1?a:SIMPLE_MOD-(SIMPLE_MOD/a)*inv(SIMPLE_MOD%a) % SIMPLE_MOD;
}

int binom(int a, int b){
    int tmp=fact[b]*invfact[a]%SIMPLE_MOD;
    return (tmp*invfact[b-a])%SIMPLE_MOD;
}

void solve(){
    vi b(n);
    forn(i,n) cin>>b[i];
    vi res(n);
    vi mp(30);
    for (int i=n-1;i>=0;i--){
        int tot=0;
        forn(j,29){
            if (mp[j]){
                // There are i+1 choose mp[j]
                tot+=binom(i+1, mp[j])*(1ll<<j);
                tot%=SIMPLE_MOD;
            }
        }
        b[i]-=tot;
        b[i]%=SIMPLE_MOD;
        if (b[i]<0) b[i]+=SIMPLE_MOD;
        for (int j=28;j>=0;j--) if (!mp[j]){
            if ((1ll<<j) & b[i]){
                // there are exactly i ones at this position
                mp[j]=i+1;
                forn(k,i+1){
                    res[k]+=(1ll<<j);
                }
            }
        }
    }
    forn(i,n){
        res[i]%=SIMPLE_MOD;
        cout<<res[i]<<" ";
    }
    cout<<"\n";
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
    while (cin>>n) solve();
}