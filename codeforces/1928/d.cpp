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
int n,b,x;
vi c;

int evaluate(int nb){
    int tot=0;
    forn(i,n){
        tot+=c[i]*(c[i]-1ll)/2ll*b;
        int y=(c[i]/nb);
        tot-=(y*(y-1ll)/2ll)*nb*b;
        tot-=(c[i]%nb)*y*b;
    }
    return tot-(nb-1ll)*x;
}

void solve(){
    c.resize(n);
    forn(i,n) cin>>c[i];
    int l=1;
    int r=E9;
    while(r-l>=3){
        int m1=l + (r-l)/3ll;
        int m2=l + (2ll*(r-l))/3ll;
        int a=evaluate(m1);
        int b=evaluate(m2);
        var(a);
        var(b);
        if (a<=b){
            l=m1;
        }
        else{
            r=m2;
        }
    }
    var(l);
    int a=evaluate(l);
    if (l<=n-1){
        a=max(a, evaluate(l+1));
    }
    if (l<=n-2){
        a=max(a, evaluate(l+2));
    }
    a=max(a, evaluate(1));
    a=max(a, evaluate(n));
    cout<<a<<"\n";
}

signed main() {
    #ifdef DEBUG
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int ttt; cin>>ttt;
    while (cin>>n>>b>>x) solve();
}