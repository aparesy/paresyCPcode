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
int x,n;

int fastpow(int a, int b){
    int tot=1;
    while(b){
        if (b & 1ll){
            tot*=a;
        }
        a*=a;
        b>>=1ll;
    }
    return tot;
}

set<int> div(int a){
    map<int,int> fact;
    for (int i=2;i*i<=a;i++){
        while (!(a%i)){
            fact[i]++;
            a/=i;
        }
    }
    if (a>1){
        fact[a]++;
    }
    set<int> st;
    st.insert(1);
    for (auto [b,c] : fact){
        set<int> st2=st;
        for (auto y : st2){
            forn(j,c){
                st.insert(y*fastpow(b,j+1));
            }
        }
    }
    return st;
}

void solve(){
    // m = n%(2k-2)
    // x = m or x = 2k-2-m if m>=k-1 
    x--;
    n--;
    int d=n-x;
    int d2=n+x;
    set<int> s1=div(d);
    set<int> s2=div(d2);
    // set<int> s3=div(gcd(d,d2));
    set<int> s;
    for (auto y : s1){
        if (!(y%2ll) && y>2ll*x-2ll){
            s.insert(y);
        }
    }
    for (auto y : s2){
        if (!(y%2ll) && y>2ll*x-2ll){
            s.insert(y);
        }
    }
    for (auto y : s) var(y);
    cout<<sz(s)<<"\n";
}

signed main() {
    #ifdef DEBUG
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int ttt; cin>>ttt;
    while (cin>>n>>x) solve();
}