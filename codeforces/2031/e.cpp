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

vvi adj;

int taille[MAXN];

pii dfs(int s){
    // transforme en binaire
    if (sz(adj[s])==0) return {0,1};
    set<pair<pii, int>> ch;
    int c=0;
    for (auto t : adj[s]){
        ch.insert({dfs(t), c});
        c++;
    }
    while(ch.size()>=3){
        auto [a,_]=*ch.begin();
        ch.erase(*ch.begin());
        auto [b,xxx]=*ch.begin();
        ch.erase(*ch.begin());
        auto [h1, t1] = a;
        auto [h2, t2] = b;
        // if (h1==h2){
        //     ch.insert({make_pair(h1+1, 1+t1+t2), c});
        // }
        // else{
        //     if (h2+1>((int)(log2(t1+t2)))){
        //         ch.insert({make_pair(h2, t1+t2),c});
        //     }
        //     else{
        //         ch.insert({make_pair(h2+1, 1+t1+t2),c});
        //     }
        // }
        ch.insert({make_pair(h2+1, t1+ t2+1), c+1});
        c++;
    }
    auto x = *ch.begin();
    ch.erase(x);
    if (sz(ch)){
        auto y=*ch.begin();
        pii z;
        z.first=max(x.first.first, y.first.first)+1;
        z.second=x.first.second+y.first.second+1;
        return z;
    }
    else{
        x.first.first+=1;
        x.first.second+=1;
        return x.first;
    }

}

void init_taille(int s){
    int tot=1;
    for (auto t : adj[s]){
        init_taille(t);
        tot+=taille[t];
    }
    taille[s]=tot;
}


void solve(){
    adj.clear();
    adj.resize(n);
    forn(i,n-1){
        int a;
        cin>>a;
        a--;
        adj[a].push_back(i+1);
    }
    forn(i,n) taille[i]=0;
    init_taille(0);
    cout<<dfs(0).first<<"\n";
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