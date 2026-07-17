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
vector<vi> adj;
int vu[MAXN];
int tmp;

bool bipar(int s, vi& cc){
    // Returns whether the cc is bipar
    queue<int> q;
    q.push(s);
    cc[s] = 0;
    bool ok=true;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int u : adj[v]) {
            if (cc[u] == -1) {
                vu[u]=true;
                cc[u] = cc[v] ^ 1;
                q.push(u);
            } else {
                if (cc[u] == cc[v]){
                    ok=false;
                }
            }
        }
    }
    return ok;
}

int taille(int s, vi& vu2, vi& cc){
    stack<int> st;
    st.push(s);
    int tot = 0;

    while(!st.empty()){
        int v = st.top(); st.pop();
        if (cc[v]) tmp++;
        tot++;
        for(int u : adj[v]){
            if(!vu2[u]){
                vu2[u] = true;
                st.push(u);
            }
        }
    }
    return tot;
}

void solve(){
    int m;
    cin>>m;
    adj.clear();
    adj.resize(n);
    forn(i,n){
        vu[i]=false;
    }
    forn(i,m){
        int a,b;
        cin>>a>>b;
        a--;b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int tot=0;
    vi cc(n,-1);
    vi vu2(n,0);
    forn(i,n){
        // var(tot);
        // range(vu, vu+n);
        if (cc[i]==-1){
            cc[i]=0;
            if (bipar(i, cc)){
                vu2[i]=true;
                tmp=0;
                int x=taille(i,vu2, cc);
                tot+=max(tmp, x-tmp);
            }
        }
    }
    cout<<tot<<"\n";
}

signed main() {
    #ifdef DEBUG
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while (cin>>n) solve();
}