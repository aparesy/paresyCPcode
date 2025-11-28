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
int m;

struct dsu{
    vi parent;
    void init(){
        parent.resize(n+m);
        rep(i,0,n+m) parent[i]=i;
    }
    int find(int a){
        if (parent[a]==a) return a;
        else return parent[a]=find(parent[a]);
    }
    void _union(int a, int b, int c){
        parent[a]=c;
        parent[b]=c;
    }
};

int u[MAXN];
int v[MAXN];
int weight[MAXN];
int minWeight[MAXN];
int tot=0;

void initMinWeight(int s, int curMin, vector<vector<int>>& tree){
    if (s<n) return;
    if (weight[s-n]<curMin) curMin=weight[s-n];
    minWeight[s]=curMin;
    for (auto x : tree[s]) initMinWeight(x, curMin, tree);
}

dsu uf2;


bool dfs(int s, vector<vector<int>>& tree, int& other, int parent, vector<vector<int>>& adj){
    if (s>=n){
        // Node
        vector<bool> tmp;
        for (auto t : tree[s]){
            tmp.push_back(dfs(t, tree, other, s, adj));
        }
        if (tmp.size()==2 && tmp[0] && tmp[1]) tot+=minWeight[s];
        if (tmp.size()==1) return tmp[0];
        if (tmp.size()==2) return tmp[0]^tmp[1];
    }
    else{
        if (adj[s].size()%2){
            return 1;
        }
        return 0;
    }

}

void solve(){
    tot=0;
    cin>>n>>m;
    dsu uf;
    uf2.init();
    uf.init();
    vector<vector<int>> adj(n);
    vector<vector<int>> tree(n+m);
    rep(i,0,m){
        cin>>u[i]>>v[i]>>weight[i];
        u[i]--; v[i]--;
        adj[u[i]].push_back(v[i]);
        adj[v[i]].push_back(u[i]);
        tot+=weight[i];
    }
    rep(i,0,m){
        int a=uf.find(u[i]);
        int b=uf.find(v[i]);
        if (a==b){
            tree[i+n].push_back(a);
        }
        else{
            tree[i+n].push_back(a);
            tree[i+n].push_back(b);
        }
        uf._union(a,b,i+n);
    }
    if (m==0){
        cout<<0<<"\n";
        return;
    }
    // rep(i,0,n+m){
    //     for (auto x : tree[i]) cout<<x<<" ";
    //     cout<<"\n";
    // }
    initMinWeight(n+m-1, weight[m-1], tree);
    int other=-1;
    dfs(n+m-1, tree, other, -1, adj);
    cout<<tot<<"\n";
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