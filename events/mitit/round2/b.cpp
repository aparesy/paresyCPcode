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
 
const int MAXN = 2e5 + 10;
int n;

int dp[MAXN];
int taille[MAXN];

int fact[MAXN];

int fast_pow(int a, int b){
    int cur=1;
    while(b){
        if (b & 1){
            cur*=a;
            cur%=SIMPLE_MOD;
        }
        a*=a;
        a%=SIMPLE_MOD;
        b>>=1;
    }
    return cur;
}

int fast_inv(int a){
    return fast_pow(a, SIMPLE_MOD-2);
}

int binom(int a, int b){
    return fact[b] * fast_inv(fact[a]) % SIMPLE_MOD * fast_inv(fact[b-a]) % SIMPLE_MOD;
}

void dfs(int s, vvi& adj, int p){
    taille[s]=1;
    int tot=0;
    int vois=0;
    dp[s]=1;
    for (auto t : adj[s]) if (t!=p){
        dfs(t,adj,s);
        taille[s]+=taille[t];
        tot+=(taille[t]%2); // Means that we can swap colors with the next child
        dp[s]*=dp[t];
        dp[s]%=SIMPLE_MOD;
        vois++;
    }
    dp[s]*=binom(tot/2,tot);
    dp[s]%=SIMPLE_MOD;
    if (tot>=1){
        dp[s]*=fast_pow(2,vois-tot);
        dp[s]%=SIMPLE_MOD;
    }
}

void solve(){
    forn(i,n) dp[i]=0;
    vvi adj(n);
    forn(i,n-1){
        int a,b;
        cin>>a>>b;
        a--;b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(0, adj, -1);
    cout<<dp[0]<<"\n";
}

signed main() {
    #ifdef DEBUG
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    fact[0]=1;
    forn(i,MAXN){
        if (!i) continue;
        fact[i]=i*fact[i-1];
        fact[i]%=SIMPLE_MOD;
    }
    int ttt; cin>>ttt;
    while (cin>>n) solve();
}