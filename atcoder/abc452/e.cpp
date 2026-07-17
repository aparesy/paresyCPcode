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
 
const int MAXN = 2e6 + 10;
int n;

void solve(){
    int m;
    cin>>m;
    vi a(n);
    vi b(m);
    forn(i,n){
        cin>>a[i];
    }
    forn(j,m){
        cin>>b[j];
    }
    int tot=0;
    forn(i,n){
        tot+=(i+1ll)*a[i];
        tot%=FFT_MOD;
    }
    int tmp=0;
    forn(i,m) tmp+=b[i];
    tmp%=FFT_MOD;
    tot*=tmp;
    tot%=FFT_MOD;

    vi acc_a(n+1);
    acc_a[0]=0;
    forn(i,n){
        acc_a[i+1]=acc_a[i]+a[i];
        if (acc_a[i+1]>=FFT_MOD) acc_a[i+1]-=FFT_MOD;
    }

    for (int j=1;j<=m;j++){
        for (int i=2*j-1;i<=n+j;i+=j){
            var(i/j);
            tot -= ((b[j-1] * (acc_a[min(n,i)]-acc_a[i-j]) % FFT_MOD) * (i/j) % FFT_MOD) * j % FFT_MOD;
            tot%=FFT_MOD;
        }
    }

    if (tot<0) tot+=FFT_MOD;
    cout<<tot<<"\n";
}

signed main() {
    #ifdef DEBUG
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //int ttt; cin>>ttt;
    while (cin>>n) solve();
}