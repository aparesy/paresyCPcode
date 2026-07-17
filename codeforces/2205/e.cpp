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
 
 
const int MAXN = 2e6 + 10;
int n;
int tab[MAXN];
int dp[MAXN];

void solve(){
    forn(i,n) cin>>tab[i];
    // dp : how many s [1...i] can be reached ?
    // when reaching a new string of size n+1, of course every prior solution will work.
    // now, for every switch such that s[n+1] != s[i], this will also create a new string
    // but if s[n+1] = s[i], then there's a chance that the switch might be redundant. this happens if the 
    // swapped s[i...n+1] = s[i+1...n] is equal to 
    vector<vi> border(n,vi(n));
    forn(i,n){
        border[i][i]=0;
        for (int j=i+1;j<n;j++){
            int k=border[i][j-1];
            while(k>0 && tab[i+k]!=tab[j]){
                k=border[i][i+k-1];
            }
            if (tab[i+k]==tab[j]) k++;
            border[i][j] = k;
        }
        // range(border[i], border[i]+n);
    }

    dp[0]=1;
    forn(i,n-1){
        dp[i+1]=dp[i];
        forn(j,i+1){
            if (!border[j][i+1]){
                dp[i+1]+=(j?dp[j-1]:1);
                if (dp[i+1]>=FFT_MOD) dp[i+1]-=FFT_MOD;
            }
        }
    }    
    range(dp, dp+n);
    cout<<dp[n-1]<<"\n";
}

signed main() {
    #ifdef DEBUG
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);int t;
    cin>>t;
    while (cin>>n) solve();
}