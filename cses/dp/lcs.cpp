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

void solve(){
    int m;
    cin>>m;
    vi s(n);
    vi t(m);
    forn(i,n) cin>>s[i];
    forn(i,m) cin>>t[i];
    int dp[n+1][m+1];
    pii prev[n+1][m+1];
    pii a={-1,-1};
    forn(i,n+1) forn(j,m+1) prev[i][j]=a;
    forn(i,n+1) dp[i][0]=0;
    forn(i,m+1) dp[0][i]=0;
    forn(i,n){
        forn(j,m){
            if (dp[i][j+1]>dp[i+1][j]) prev[i+1][j+1] = {i,j+1}; else prev[i+1][j+1]={i+1,j}; 
            dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
            if (s[i]==t[j] && dp[i][j]+(s[i]==t[j])>=dp[i+1][j+1]) prev[i+1][j+1]={i,j};
            dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j]+(s[i]==t[j]));
        }
    }
    cout<<dp[n][m]<<"\n";
    int i=n;
    int j=m;
    stack<int> st;
    while(min(i,j)>0){
        if (prev[i][j].first==i-1 && prev[i][j].second==j-1) st.push(s[i-1]);
        auto tmp=prev[i][j];
        i=tmp.first;
        j=tmp.second;
    }
    while(!st.empty()){
        auto x = st.top();
        cout<<x<<" ";
        st.pop();
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