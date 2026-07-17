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
int n,m;

void solve(){
    vector<vii> adj(2*n);
    forn(i,m){
        int a,b,c;
        cin>>a>>b>>c;
        a--;b--;
        adj[a].push_back({b,c});
        adj[a+n].push_back({b+n,c});
        adj[a].push_back({b+n,c/2});
    }
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0,0});
    vi vu(2*n);
    while(!q.empty()){
        auto [a,b] = q.top();
        q.pop();
        if (b==2*n-1){
            cout<<a<<"\n";
            return;
        }
        if (vu[b]) continue;
        vu[b]=true;
        for (auto [t,c] : adj[b]){
            if (!vu[t]){
                q.push({c+a, t});
            }
        }
    }
    cout<<-1<<"\n";
}

signed main() {
    #ifdef DEBUG
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while (cin>>n>>m) solve();
}