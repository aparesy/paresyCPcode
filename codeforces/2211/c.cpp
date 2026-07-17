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
int n,k;
map<int,int> mp;

void solve(){
    mp.clear();
    vi a(n);
    forn(i,n){
        cin>>a[i];
    }
    vi b(n);
    forn(i,n){
        cin>>b[i];
        mp[b[i]]++;
    }
    for (auto [a,b] : mp){
        if (a!=-1 && b>1){
            cout<<"NO\n";
            return;
        }
    }
    for (int i=0;i+k<n;i++){
        if (b[i]!=-1 && b[i]!=a[i]){
            cout<<"NO\n";
            return;
        }
        if (b[i]==-1 && mp[a[i]]>0){
            cout<<"NO\n";
            return;
        }
    }
    reverse(all(a));
    reverse(all(b));
    for (int i=0;i+k<n;i++){
        if (b[i]!=-1 && b[i]!=a[i]){
            cout<<"NO\n";
            return;
        }
        if (b[i]==-1 && mp[a[i]]>0){
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
}

signed main() {
    #ifdef DEBUG
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int ttt; cin>>ttt;
    while (cin>>n>>k) solve();
}