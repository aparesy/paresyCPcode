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
 
const int MAXN = 3e3 + 10;
int n,x,s;

void solve(){
    string tab;
    cin>>tab;
    
    int dp[x+1];
    forn(i,x+1){
        dp[i]=-E18;
    }
    dp[0] = 0;
    forn(i,n){
        if (tab[i]=='I'){
            for (int j=x-1;j>=0;j--){
                dp[j+1] = max(dp[j+1], dp[j]+1);
            }
        }
        else if (tab[i]=='E'){
            forn(j,x+1){
                if (dp[j]<j*s){
                    dp[j]++;
                }
            }
        }
        else{
            for (int j=x;j>=0;j--){
                int maxi = dp[j];
                if (j){
                    maxi = max(maxi, dp[j-1]+1);
                }
                if (dp[j]<j*s){
                    maxi = max(maxi, dp[j]+1);
                }
                dp[j]=maxi;
            }
        }
    }
    int maxi=0;
    forn(i,x+1){
        maxi = max(maxi, dp[i]);
    }
    cout<<maxi<<"\n";
}

signed main() {
    #ifdef DEBUG
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int ttt; cin>>ttt;
    while (cin>>n>>x>>s) solve();
}