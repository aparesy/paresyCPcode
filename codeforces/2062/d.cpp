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
int n;
vii tab;

int dfs(int cur, vvi& adj, vi& vu,int h){
    int tot=0;
    for (auto t : adj[cur]) if (!vu[t]){
        vu[t]=true;
        if (tab[t].first>h){
            tot+=tab[t].first-h;
            h=tab[t].first;
        }
        else if (tab[t].second<h){
            h=tab[t].second;
        }
        tot+=dfs(t, adj, vu, h);
    }
    return tot; 
}

void solve(){
    tab.resize(n);
    vvi adj(n);
    int tot=0;
    int cur=0;
    forn(i,n){
        cin>>tab[i].first>>tab[i].second;
        if (tab[i].first>=tot){
            tot=tab[i].first;
            cur=i;
        }
    }
    forn(i,n-1){
        int a,b;
        cin>>a>>b;
        a--;b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vi vu(n);
    vu[cur]=true;
    int delta=dfs(cur,adj,vu,tot);
    cout<<tot+delta<<"\n";
}

signed main() {
    #ifdef DEBUG
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int ttt; cin>>ttt;
    while (cin>>n) solve();
}