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
vi fact;

int fast_exp(int a, int b){
    int cur=1;
    while(b){
        if (b&1ll){
            cur*=a;
            cur%=SIMPLE_MOD;
        }
        a*=a;
        a%=SIMPLE_MOD;
        b>>=1;
    }
    return cur;
}

int fast_inv(int x){return fast_exp(x,SIMPLE_MOD-2);}

int binom(int a, int b){
    // a parmi b
    return fast_inv(fact[a])*fast_inv(fact[b-a])%SIMPLE_MOD*fact[b]%SIMPLE_MOD;
}

void solve(){
    if (n%2) cout<<0<<"\n", exit(0);
    n>>=1;
    fact.resize(2*n+1);
    fact[0]=1;
    forn(i,2*n){
        fact[i+1]=fact[i]*(i+1ll)%SIMPLE_MOD;
    }
    cout<<fast_inv(n+1)*fact[2*n]%SIMPLE_MOD*fast_inv(fact[n])%SIMPLE_MOD*fast_inv(fact[n])%SIMPLE_MOD;
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