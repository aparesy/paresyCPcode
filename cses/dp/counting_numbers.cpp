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
int a,b;

int to_n(int n){
    if (n<0) return 0;
    if (!n) return 1;
    vi digits;
    while(n){
        digits.push_back(n%10);
        n/=10;
    }
    // Now modify to add zero transitions everywhere
    reverse(all(digits));
    int dp[sz(digits)][10][2];
    forn(i,10) dp[0][i][0] = dp[0][i][1] = 0;
    forn(i,digits[0]) dp[0][i][0]=1;
    dp[0][digits[0]][1]=1;
    dp[0][0][0]=0;
    forn(i,sz(digits)-1){
        forn(j, 10){
            dp[i+1][j][0]=0;
            dp[i+1][j][1]=0;
            forn(k,10) if (k!=j) {
                dp[i+1][j][0]+=dp[i][k][0];
            }
            if (j) dp[i+1][j][0]++;
            if (j<digits[i+1] && (j!=digits[i])) dp[i+1][j][0]+=dp[i][digits[i]][1];
        }
        if (digits[i]!=digits[i+1]) dp[i+1][digits[i+1]][1] = dp[i][digits[i]][1];
    }
    int tot=0;
    forn(i,10){
        tot+=dp[sz(digits)-1][i][0];
        tot+=dp[sz(digits)-1][i][1];
    }
    return tot+1;
}

void solve(){
    cout<<to_n(b)-to_n(a-1)<<"\n";
}

signed main() {
    #ifdef DEBUG
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while (cin>>a>>b) solve();
}