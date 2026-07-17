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
#define vvii vector<vii>
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

vvii adj;

void djikstra(int s){
    var(s);
    priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> q;
    vi prec(n,-1);
    for (auto t : adj[s]){
        q.push({t.second, t.first,s});
        prec[t.first]=s;
    }
    vi vu(n);
    map<tuple<int,int,int>, int> vu_edge;
    vu[s]=true;
    while(!q.empty()){
        auto [time, som, before] = q.top();
        q.pop();
        if (som==s && time<0){
            prec[som]=before;
            var(prec[s]);
            int cur=som;
            vi res;
            res.push_back(s);
            while(prec[cur]!=s){
                cur=prec[cur];
                res.push_back(cur);
            }
            res.push_back(s);
            reverse(all(res));
            var(sz(res));
            for (auto x : res) cout<<x+1<<" ";
            return;
        }
        if (vu[som]) continue;
        vu[som]=true;
        prec[som]=before;
        for (auto edge : adj[som]){
            if (!vu_edge[{edge.first, edge.second, som}]){
                vu_edge[{edge.first, edge.second, som}]=true;
                q.push({time+edge.second, edge.first,som});
            }
        }
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
    priority_queue<pii, vector<pii>, greater<pii>> q;
    vi vu(n);
    vi d(n);
    forn(i,n){
        if (!vu[i]){
            vu[i]=1;
            q.push({0,i});
            while(!q.empty()){
                auto [time,s]=q.top();
                q.pop();
                if (vu[s]==2) continue;
                if (!vu[s]){
                    vu[s]=1;
                    d[s] = time;
                }
                else{
                    if (time < d[s]){
                        cout<<"YES\n";
                        djikstra(s);
                        return;
                    }
                }
                for (auto [t, cost] : adj[s]){
                    q.push({cost+time, t});
                }
            }
            vu[i]=2;
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