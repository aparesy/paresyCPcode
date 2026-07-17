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

int fastinv(int a){
    return a<=1 ? a : SIMPLE_MOD-(SIMPLE_MOD/a)*fastinv(SIMPLE_MOD%a)%SIMPLE_MOD;
}

int dp[501][501*501];

void solve(){
    forn(i,n+1){
        if (i==0){
            forn(j,501*501) dp[i][j]=0;
            dp[0][0]=1;
            continue;
        }
        forn(j,(i*(i+1)/2)+1){
            if (!j){
                dp[i][j]=1ll;
                continue;
            }
            dp[i][j]=dp[i-1][j]+(j>=i?dp[i-1][j-i]:0ll);
            if (dp[i][j]>=SIMPLE_MOD) dp[i][j]-=SIMPLE_MOD;
        }
    }
    if (n%4 == 1 || n%4==2){
        cout<<0;
    }
    else{
        cout<<(dp[n][(n*(n+1))/4]*fastinv(2ll))%SIMPLE_MOD;
    }
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