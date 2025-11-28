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
int mod=FFT_MOD;
const int MAXN = 5001;
int n;

int dp[MAXN][MAXN];

void solve(){
    cin>>n;
    map<int,int> occ;
    rep(i,0,n){
        int x;
        cin>>x;
        occ[x]++;
    }
    int res=1;
    int maxOcc=0;
    for (auto [a,b] : occ){
        maxOcc=max(maxOcc, b);
    }
    dp[0][0]=1;
    int i=0;
    for (auto [a,b] : occ){
        //only b is important
        i++;
        forn(j,maxOcc+1) dp[i][j]=dp[i-1][j];
        forn(j,maxOcc+1){
            dp[i][min(j+b, maxOcc)]+=dp[i-1][j]*b;
            dp[i][j]%=mod;
        }
    }
    res=dp[occ.size()][maxOcc];
    cout<<res<<"\n";
}

signed main() {
    #ifdef DEBUG
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin.tie(0);
    int _t;
    cin >> _t;
    rep(i,0,_t) {
        solve();
    }
}