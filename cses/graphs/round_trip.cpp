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

bool vu[MAXN];
int prec[MAXN];
vvi adj;

bool dfs(int s, int p, map<int,int>& mp){
    for (auto t : adj[s]) if (t!=p){
        if (vu[t] && mp[t]){
            int x=t;
            vi res;
            res.push_back(x);
            x=s;
            while(x!=t){
                res.push_back(x);
                x=prec[x];
            }
            res.push_back(t);
            cout<<res.size()<<"\n";
            for (auto y : res){
                cout<<y+1<<" ";
            }
            return true;
        }
        else{
            mp[t]=true;
            prec[t]=s;
            vu[t]=true;
            if (dfs(t,s,mp)) return true;
            mp[t]=false;
        }
    }
    return false;
}

void solve(){
    memset(vu,0,sizeof(vu));
    memset(prec,0,sizeof(prec));
    adj.resize(n);
    forn(i,m){
        int a,b;
        cin>>a>>b;
        a--;b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    forn(i,n){
        if (!vu[i]){
            vu[i]=true;
            map<int,int> mp;
            if (dfs(i,-1,mp)){
                return;
            }
        }
    }
    cout<<"IMPOSSIBLE\n";
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