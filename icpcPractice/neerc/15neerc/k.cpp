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
int n,m;
vector<int> adj[MAXN];
int path[MAXN];

unordered_map<bitset<MAXN>, bool> ok;

bool bt(int s, bitset<MAXN>& vu, int nb){
    var(s); var(nb);
    if (nb==n && path[nb-1]==0){
        return true;
    }
    if (ok[vu]) return false;
    for (auto x : adj[s]){
        if (!vu[x]){
            vu[x]=true;
            path[nb]=x;
            if (bt(x, vu, nb+1)){
                return true;
            }
            vu[x]=false;
        }
    }
    ok[vu]=true;
    return false;
}

void solve(){
    cin>>n>>m;
    forn(i,m){
        int a,b;
        cin>>a>>b;
        a--;b--;
        adj[a].push_back(b);
    }
    bitset<MAXN> vu;
    for(auto x : adj[0]){
        vu[x]=true;
        path[0]=x;
        if (bt(x, vu, 1)){
            cout<<1<<" ";
            forn(i,n) cout<<path[i]+1<<" ";
            return;
        }
        vu[x]=false;
    }
    cout<<"There is no route, Karl!";
}

signed main() {
    freopen("king.in", "r", stdin);
    freopen("king.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin.tie(0);
    int _t;
    solve();
}