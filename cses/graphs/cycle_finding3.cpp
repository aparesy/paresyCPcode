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
#define vvi vector<vii>
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
vector<vii> adj;

void solve(){
    n++;
    adj.resize(n);
    int m;
    cin>>m;
    forn(i,m){
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
    }
    forn(i,n-1){
        adj[0].push_back({i+1,0});
    }
    vi d(n,E18);
    d[0]=0;
    forn(i,n+1){
        forn(j,n+1){
            for (auto [dest, cost] : adj[j]){
                d[dest] = min(d[dest], cost+d[j]);
            }
        }
    }
    set<int> bouge;
    forn(j,n+1){
        for (auto [dest,cost] : adj[j]){
            if (d[j]+cost<d[dest]){
                bouge.insert(dest);
            }
        }
    }
    if (!sz(bouge)){
        cout<<"NO\n";
    }
    else{
        cout<<"YES\n";
        int cur=(*bouge.begin());
        int start=cur;
        vi res;
        res.push_back(cur);
        for (auto [t, cost] : adj[cur]){
            if (bouge.count(t)){
                cur=t;
                res.push_back(cur);
                break;
            }
        }
        while(cur!=start){
            for (auto [t, cost] : adj[cur]){
                if (bouge.count(t)){
                    cur=t;
                    res.push_back(cur);
                    break;
                }
            }
        }
        for (auto x : res){
            cout<<x+1<<" ";
        }
    //    cout<<start+1<<"\n";
    }
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