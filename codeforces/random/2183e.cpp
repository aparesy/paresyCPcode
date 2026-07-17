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
 

vi dive[3001];
 
#define int ll
 
const int MAXN = 2e6 + 10;
int n;

void solve(){
    int m;
    cin>>m;
    vi tab(n);
    forn(i,n) cin>>tab[i];
    vector<vi> dp(n, vi(m+1));
    dp[0][1]=1;
    forn(i,n){
        if (!i){
            if (tab[0]){
                forn(j,m){
                    dp[0][j+1] = (j+1==tab[0]);
                }
            }
            continue;
        }

        if (tab[i]){
            for (auto d : dive[tab[i]]){
                if (d!=tab[i]){
                    dp[i][tab[i]]+=dp[i-1][tab[i]-(d)];
                    if (dp[i][tab[i]]>=FFT_MOD) dp[i][tab[i]]-=FFT_MOD;
                }
            }
        }

        else{
            for (int j=1; j<=m; j++){
                for (auto d : dive[j]){
                    if (d!=j){
                        dp[i][j]+=dp[i-1][j-d];
                        if (dp[i][j] >= FFT_MOD) dp[i][j]-=FFT_MOD;
                    }
                }
            }
        }
    }

    int tot=0;
    forn(i,m){
        tot+=dp[n-1][i+1];
        if (tot>=FFT_MOD) tot-=FFT_MOD;
    }
    // forn(i,n){
    //     var(i);
    //     forn(j,m){
    //         var(j+1);
    //         var(dp[i][j+1]);
    //     }
    // }
    if (tab[0]>=2){
        cout<<0<<"\n";
        return;
    }
    if (n==1){
        if (tab[0]){
            if (tab[0]!=1) cout<<0<<"\n";
            else cout<<1<<"\n";
        }
        else cout<<1<<"\n";
        return;
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
    forn(i,3001){
        if (!i) continue;
        for (int j=i; j<=3000; j+=i){
            dive[j].push_back(i);
        }
    }
    int t;
    cin>>t;
    while (cin>>n) solve();
}