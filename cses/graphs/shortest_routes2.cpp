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
int n,m,q;

void solve(){
    vi vu(n);
    vu[0]=true;
    vector<vii> adj(n);
    forn(i,m){
        int a,b,c;
        cin>>a>>b>>c;
        a--;b--;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }
    int dist[501][501];
    forn(i,n){
        forn(j,n){
            dist[i][j]=E18;
        }
        dist[i][i]=0;
    }

    forn(i,n){
        for (auto [b,c] : adj[i]) dist[b][i]=min(c, dist[b][i]), dist[i][b]=min(dist[i][b], c);
        forn(j,n){
            forn(k,n){
                dist[j][k]=min(dist[j][k], dist[j][i]+dist[i][k]);
            }
        }
    }
    forn(i,q){
        int a,b;
        cin>>a>>b;
        a--;b--;
        if (dist[a][b]==E18) cout<<-1<<"\n";
        else cout<<dist[a][b]<<"\n";
    }
}

signed main() {
    #ifdef DEBUG
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while (cin>>n>>m>>q) solve();
}