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

void bfs(int s){
    queue<int> q;
    q.push(s);
    vu[s]=true;
    while(!q.empty()){
        auto t = q.front();
        q.pop();
        for (auto u : adj[t]){
            if (!vu[u]){
                vu[u]=true;
                q.push(u);
                prec[u]=t;
            }
            if (u==n-1) return;
        }
    }
}

void solve(){
    memset(vu, 0, sizeof(vu));
    memset(prec, 0, sizeof(prec));
    adj.resize(n);
    forn(i,m){
        int a,b;
        cin>>a>>b;
        a--;b--;
        adj[a].push_back(b);
        adj[b].push_back(a);       
    }
    bfs(0);
    if (!vu[n-1]){
        cout<<"IMPOSSIBLE\n";
    }
    else{
        vi res;
        int cur=n-1;
        while(cur!=0){
            res.push_back(cur);
            cur=prec[cur];
        }
        reverse(all(res));
        cout<<sz(res)+1<<"\n";
        cout<<1<<" ";
        for(auto x : res){
            cout<<x+1<<" ";
        }   
    }
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