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

int vu[MAXN]; //0 for not seen, 1 for seen and 2 for elim
int d[MAXN];
vector<vii> adj;

void dfs(int s, int dd, vi& seen, map<int,int>& call_stack, int depth){
    var(depth);
    if (vu[s]==2){
        return;
    }
    else if (vu[s]==1){
        if (call_stack[s]==0) return;
        if (dd>=d[s]){
            return;
        }
        else{
            cout<<"YES\n";
            vi res(depth);
            for (auto [a,b] : call_stack){
                res[b]=a;
            }
            bool ok=false;
            for (int i=1;i<depth;i++){
                if (res[i]==s) ok=true;
                if (ok) cout<<res[i]+1<<" ";
            }
            cout<<s+1<<" ";
            cout<<"\n";
            exit(0);
        }
    }
    else{
        seen.push_back(s);
        vu[s]=1;
        d[s]=dd;
        call_stack[s]=depth;
        for (auto [t,cost] : adj[s]){
            dfs(t,dd+cost,seen,call_stack,depth+1);
        }
        call_stack[s]=0;
        vu[s]=2;
    }
}

void solve(){
    int m;
    cin>>m;
    adj.clear();
    adj.resize(n);
    forn(i,m){
        int a,b,c;
        cin>>a>>b>>c;
        a--;b--;
        adj[a].push_back({b,c});
    }
    forn(i,n){
        d[i]=0;
        vu[i]=0;
        sort(all(adj[i]));
    }
    forn(i,n){
        if (!vu[i]){
            d[i]=0;
            vi seen;
            map<int,int> call_stack;
            dfs(i,0,seen,call_stack,1);
            for (auto x : seen) vu[x]=2;
        }
    }
    cout<<"NO\n";
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