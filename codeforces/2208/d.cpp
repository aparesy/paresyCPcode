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
 
 
 
const int MAXN = 2e6 + 10;
int n;

vector<vi> adj;
vi vu;
vector<string> mat;

bitset<8001> mat2[8001];
bitset<8001> revmat2[8001];

bool dfs(int s, set<int>& st){
    set<int> tmp;
    for (auto i : st){
        if (i==s) continue;
        if (!vu[i] && mat[s][i]=='1'){
            tmp.insert(i);
        }
    }
    for (auto i : tmp){
        bitset<8001> bs;
        bs[i]=1;
        bs[s]=1;
        if ((mat2[i] & revmat2[s])==bs){
            vu[i]=true;
            adj[s].push_back(i);
            if (!dfs(s,tmp) && i!=s) return false;
        }   
    }

    set<int> tmp2;

    for (auto i : st){
        if (i==s) continue;
        if (!vu[i] && mat[i][s]=='1'){
            tmp2.insert(i);
            if (tmp.count(i) && i!=s) return false;
        }
    }
    var(sz(st))
    for (auto i : tmp2){
        bitset<8001> bs;
        bs[i]=1;
        bs[s]=1;
        if ((mat2[i] & revmat2[s])==bs){
            vu[i]=true;
            adj[i].push_back(s);
            if (!dfs(i,tmp2)) return false;
        }   
    }

    return true;
}

void solve(){
    adj.clear();
    vu.clear();
    mat.clear();
    adj.resize(n);
    vu.resize(n);
    mat.resize(n);
    forn(i,n){
        mat2[i]=0;
        revmat2[i]=0;
    }
    forn(i,n){
        cin>>mat[i];
        forn(j,n){
            if (mat[i][j]=='1'){
                mat2[i][j]=1;
                revmat2[j][i]=1;
            }
        }
    }
    vu[0]=true;
    set<int> st;
    forn(i,n-1){
        st.insert(i+1);
    }
    if (!dfs(0,st)){
        cout<<"No\n";
        return;
    }
    range(vu.begin(), vu.end());
    forn(i,n){
        if (!vu[i]){
            cout<<"No\n";
            return;
        }
    }

    int tot=0;
    forn(i,n){
        tot+=sz(adj[i]);
    }
    if (tot!=n-1){
        cout<<"No\n";
        return;
    }

    cout<<"Yes\n";
    forn(i,n){
        for (auto j : adj[i]){
            cout<<i+1<<" "<<j+1<<"\n";
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
    int t;
    cin>>t;
    while (cin>>n) solve();
}