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
 
const int MAXN = 2e6 + 10;
int n;
int tab[MAXN];

void solve(){
    cin>>n;
    rep(i,0,n){
        cin>>tab[i];
    }
    string s;
    cin>>s;
    if (s[0]=='1') {cout<<-1<<"\n"; return;}
    if (s[n-1]=='1') {cout<<-1<<"\n"; return;}
    int indMin=0;
    int indMax=0;
    rep(i,0,n){
        if (tab[i]==n && s[i]=='1') {cout<<-1<<"\n"; return;}
        if (tab[i]==1 && s[i]=='1') {cout<<-1<<"\n"; return;}
        if (tab[i]==1) indMin=i;
        if (tab[i]==n) indMax=i;
    }
    cout<<5<<"\n";
    cout<<1<<" "<<indMin+1<<"\n";
    cout<<indMin+1<<" "<<n<<"\n";
    cout<<1<<" "<<indMax+1<<"\n";
    cout<<indMax+1<<" "<<n<<"\n";
    if (indMax<indMin) cout<<indMax+1<<" "<<indMin+1<<"\n";
    else cout<<indMin+1<<" "<<indMax+1<<"\n";
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