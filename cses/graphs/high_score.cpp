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

void solve(){
    vector<vii> adj(n);
    vector<vi> revadj(n);
    forn(i,m){
        int a,b,c;
        cin>>a>>b>>c;
        a--;
        b--;
        adj[a].push_back({b,-c});
        revadj[b].push_back({a});
    }
    int dist[5001];
    forn(i,n){
        dist[i]=E18;
    }

    vi ok(n);
    ok[n-1]=1;
    stack<int> st;
    vi vu(n);
    vu[n-1]=true;
    st.push(n-1);
    while(!st.empty()){
        auto t = st.top();
        st.pop();
        for (auto x : revadj[t]){
            if (!vu[x]){
                vu[x]=true;
                ok[x]=true;
                st.push(x);
            }
        }
    }
    vi ok2(n);
    ok2[0]=1;
    vu.clear();
    vu.resize(n);
    vu[0]=true;
    st.push(0);
    while(!st.empty()){
        auto t = st.top();
        st.pop();
        for (auto x : adj[t]){
            if (!vu[x.first]){
                vu[x.first]=true;
                ok2[x.first]=true;
                st.push(x.first);
            }
        }
    }
    range(ok.begin(), ok.end());
    dist[0]=0;
    forn(aa,n+1){
        forn(i,n){
            for (auto [j,c] : adj[i]){
                if(dist[i]+c < dist[j]){
                    dist[j]=dist[i]+c;
                }
            }
        }
    }
    bool ch=false;
    forn(aa,n){
        forn(i,n){
            for (auto [j,c] : adj[i]){
                if(dist[i]+c < dist[j]){
                    dist[j]=dist[i]+c;
                    if (ok[j] && ok2[j]) ch=true;
                }
            }
        }
    }
    if(ch){
        cout<<-1<<"\n";
        return;
    }
    cout<<-dist[n-1]<<"\n";
    return;
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